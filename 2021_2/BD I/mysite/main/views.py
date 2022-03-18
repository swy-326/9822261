from django.shortcuts import render,redirect
from django.http import HttpResponse
from .models import Curiosities, Comment
from django.contrib.auth.forms import AuthenticationForm, UserCreationForm
from django.contrib.auth import login,logout,authenticate
from django.contrib import messages
from .forms import CuriositiesForm, CommentForms


# Create your views here.
def homepage(request):
    curiosities = Curiosities.objects.all
    comments = Comment.objects.select_related('curiosity_id')
    return render(request=request,
                template_name="main/home.html",
                context={"curiosities": curiosities,
                        "comments":comments})

def register(request):

    if request.method == "POST":
        form = UserCreationForm(request.POST)
        if(form.is_valid()):
            user = form.save()
            username = form.cleaned_data.get("username")
            messages.success(request,f"new account created {username} ")
            login(request,user)
            return redirect("main:homepage")
        else:
            for msg in form.error_messages:
                messages.error (request,f"{msg}:{form.error_messages[msg]}")
         
    form = UserCreationForm
    return render(request=request,
                template_name="main/register.html",
                context={"form":form})

def logout_request(request):
    logout(request)
    messages.info(request,"Logged out sucessfuly")
    return redirect("main:homepage")

def login_request(request):
    
    if request.method == "POST":
        form = AuthenticationForm(request,data=request.POST)
        if(form.is_valid()):
            username = form.cleaned_data.get('username')
            password = form.cleaned_data.get('password')
            user = authenticate(username=username,password=password)
            if(user is not None):
                login(request,user)
                messages.info(request,f"you are now logged in as {username} ")
                return redirect("main:homepage")
            else:
                messages.error(request,"Invalid username or password")
        else:
                messages.error(request,"Invalid username or passwordss")

    form = AuthenticationForm()
    return render(request=request,
                template_name="main/login.html",
                context={"form":form})
    
def create_curiosity(request):
    if request.user.is_authenticated:
    
        form = CuriositiesForm()
        if(request.method == "POST"):
            form = CuriositiesForm(request.POST)
            if(form.is_valid()):
                form.save()
                return redirect("main:homepage")
        context = {'form':form}
        return render(request,"main/create_curiosity.html",context)
    else:
        return redirect("main:login")

def my_curiosities(request):
    if request.user.is_authenticated:
        return render(request=request,
                    template_name="main/home.html",
                    context={"curiosities": Curiosities.objects.filter(author_id=request.user.id)})
    else:
        return redirect("main:login")


def delete_curiosity(request,pk):
    comment = Comment.objects.get(comment_id=pk)
    if(request.method == "POST"):
        comment.delete()
        return redirect("main:homepage")

    return render(request,'main/delete.html',context={"comment":comment})

def create_comment(request):
    if request.user.is_authenticated:
    
        form = CommentForms()
        if(request.method == "POST"):
            form = CommentForms(request.POST)
            if(form.is_valid()):
                form.save()
                return redirect("main:homepage")
        context = {'form':form}
        return render(request,"main/create_comment.html",context)
    else:
        return redirect("main:login")
from django.db import models
from django.conf import settings
from django.forms import ModelForm



# Create your models here.
DEFAULT_CATEGORY_ID = 1
class Category(models.Model):
    category_id = models.AutoField(primary_key=True)
    name = models.TextField()
    def __str__(self):
        return self.name

class Curiosities(models.Model):
    id = models.AutoField(primary_key=True)
    text = models.TextField(max_length=200)
    published_date = models.DateTimeField("date published",auto_now_add=True)
    category_id = models.ForeignKey(Category, on_delete=models.CASCADE, default=DEFAULT_CATEGORY_ID)
    author_id = models.ForeignKey(settings.AUTH_USER_MODEL,on_delete=models.CASCADE,default=DEFAULT_CATEGORY_ID)

    #override to print statement
    def __str__(self):
        return self.text

class Vote(models.Model):
    
    vote_id = models.AutoField(primary_key=True)
    published_date = models.DateTimeField("date published")
    curiosity_id = models.ForeignKey(Curiosities, on_delete=models.CASCADE)
    author_id = models.ForeignKey(settings.AUTH_USER_MODEL,on_delete=models.CASCADE)

class Comment(models.Model):
    
    comment_id = models.AutoField(primary_key=True)
    text = models.TextField()
    published_date = models.DateTimeField("date published",null=True)
    curiosity_id = models.ForeignKey(Curiosities, on_delete=models.CASCADE)
    author_id = models.ForeignKey(settings.AUTH_USER_MODEL,on_delete=models.CASCADE,default=DEFAULT_CATEGORY_ID)
    
    def __str__(self):
        return self.text
    



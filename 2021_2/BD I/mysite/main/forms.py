from django.db.models.base import Model
from django.forms import ModelForm
from .models import Curiosities, Comment

class CuriositiesForm(ModelForm):
    class Meta:
        model = Curiosities
        fields = ['text','category_id']

class CommentForms(ModelForm):
    class Meta:
        model = Comment
        fields = ['text','curiosity_id']
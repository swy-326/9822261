from django.contrib import admin
from .models import Curiosities,Category, Comment

class CuriositiesAdmin(admin.ModelAdmin):
    fields = [
        "author_name",
        "published_date",
        "curiosity"
    ]

class CategoriesAdmin(admin.ModelAdmin):
    fields = [
        "text",
        "published_date"
    ]

class CommentsAdmin(admin.ModelAdmin):
    fields = [
        "text",
        "curiosity_id",
        "published_date",
        "author_id"
    ]

# Register your models here.
admin.site.register(Curiosities,CuriositiesAdmin)
#admin.site.register(Category,CategoriesAdmin)
admin.site.register(Category)
admin.site.register(Comment)
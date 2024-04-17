# In book/admin.py
from django.contrib import admin
from .models import Book, Metadata, Review, Publisher

admin.site.register(Book)
admin.site.register(Metadata)
admin.site.register(Review)
admin.site.register(Publisher)

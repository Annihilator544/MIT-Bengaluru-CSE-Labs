# In book/models.py
from django.db import models

class Book(models.Model):
    title = models.CharField(max_length=255)
    author = models.CharField(max_length=255)
    cover_image = models.ImageField(upload_to='covers/')

class Metadata(models.Model):
    book = models.OneToOneField(Book, on_delete=models.CASCADE)
    # Add other metadata fields

class Review(models.Model):
    book = models.ForeignKey(Book, on_delete=models.CASCADE)
    content = models.TextField()
    # Add other review fields

class Publisher(models.Model):
    book = models.OneToOneField(Book, on_delete=models.CASCADE)
    name = models.CharField(max_length=255)
    # Add other publisher info fields

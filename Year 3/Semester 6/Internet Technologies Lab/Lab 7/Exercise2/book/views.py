# In book/views.py
from django.shortcuts import render

def home(request):
    return render(request, 'book/home.html')

def metadata(request):
    return render(request, 'book/metadata.html')

def reviews(request):
    return render(request, 'book/reviews.html')

def publisher_info(request):
    return render(request, 'book/publisher_info.html')

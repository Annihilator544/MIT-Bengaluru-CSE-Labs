# groceryapp/urls.py
from django.urls import path
from . import views

urlpatterns = [
    path('', views.grocery_checklist, name='grocery_checklist'),
]

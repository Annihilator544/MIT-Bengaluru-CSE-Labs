from django.urls import path
from . import views

urlpatterns = [
    path('', views.home, name='home'),
    path('calculate_cgpa/', views.calculate_cgpa, name='calculate_cgpa'),
    path('display_cgpa/', views.display_cgpa, name='display_cgpa'),
]

from django.urls import path
from . import views

urlpatterns = [
    path('', views.register, name='register'),
    path('success/<str:username>/<str:email>/<str:contact_number>/', views.success, name='success'),
]

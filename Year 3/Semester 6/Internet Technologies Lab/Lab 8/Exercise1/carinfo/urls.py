# carinfo/urls.py
from django.urls import path
from . import views

urlpatterns = [
    path('', views.car_info_form, name='car_info_form'),
    path('display/', views.display_car_info, name='display_car_info'),
]

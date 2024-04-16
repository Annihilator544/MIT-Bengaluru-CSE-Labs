# urls.py
from django.urls import path
from . import views

urlpatterns = [
    path('employee_form/', views.employee_form, name='employee_form'),
    path('promotion_check/', views.promotion_check, name='promotion_check'),
]

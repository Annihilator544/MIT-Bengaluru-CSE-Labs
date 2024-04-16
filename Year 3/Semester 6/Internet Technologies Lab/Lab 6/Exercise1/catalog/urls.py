from django.urls import path
from . import views

urlpatterns = [
    path('student_form/', views.student_form, name='student_form'),
]
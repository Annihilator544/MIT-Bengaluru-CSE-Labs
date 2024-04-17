from django.urls import path
from . import views

urlpatterns = [
    path('arithmetic/', views.arithmetic, name='arithmetic'),
]
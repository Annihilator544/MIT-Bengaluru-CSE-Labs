from django.urls import path
from . import views

urlpatterns = [
    path('', views.vote_book, name='vote_book'),
    path('result/', views.vote_result, name='vote_result'),
]

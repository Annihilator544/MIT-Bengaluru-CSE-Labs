from django.db import models

class BookVote(models.Model):
    CHOICES = (
        ('good', 'Good'),
        ('satisfactory', 'Satisfactory'),
        ('bad', 'Bad'),
    )
    vote = models.CharField(max_length=20, choices=CHOICES)

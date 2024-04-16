from django.db import models

class Student(models.Model):
    name = models.CharField(max_length=100)
    dob = models.DateField()
    address = models.CharField(max_length=255)
    contact_number = models.CharField(max_length=15)
    email = models.EmailField()
    marks_english = models.FloatField()
    marks_physics = models.FloatField()
    marks_chemistry = models.FloatField()

    def total_percentage(self):
        total_marks = self.marks_english + self.marks_physics + self.marks_chemistry
        return (total_marks / 300) * 100

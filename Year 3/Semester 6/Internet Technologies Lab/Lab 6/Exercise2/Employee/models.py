from django.db import models

class Employee(models.Model):
    employee_id = models.CharField(max_length=20, unique=True)
    date_of_joining = models.DateField()

    def __str__(self):
        return self.employee_id

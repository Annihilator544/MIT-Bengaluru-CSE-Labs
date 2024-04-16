from django import forms
from .models import Employee

class EmployeeExperienceForm(forms.ModelForm):
    class Meta:
        model = Employee
        fields = ['employee_id', 'date_of_joining']

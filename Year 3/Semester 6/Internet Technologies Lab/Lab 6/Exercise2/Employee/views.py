from django.shortcuts import render
from .forms import EmployeeExperienceForm
from datetime import date

def check_experience(request):
    if request.method == 'POST':
        form = EmployeeExperienceForm(request.POST)
        if form.is_valid():
            employee_id = form.cleaned_data['employee_id']
            date_of_joining = form.cleaned_data['date_of_joining']
            years_of_experience = (date.today() - date_of_joining).days // 365
            is_eligible = years_of_experience > 5
            return render(request, 'result.html', {'is_eligible': is_eligible})
    else:
        form = EmployeeExperienceForm()
    return render(request, 'employee_form.html', {'form': form})

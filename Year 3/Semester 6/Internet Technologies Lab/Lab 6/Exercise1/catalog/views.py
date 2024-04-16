from django.shortcuts import render
from .forms import StudentForm

def student_form(request):
    total_marks = None  # Initialize total_marks

    if request.method == 'POST':
        form = StudentForm(request.POST)
        if form.is_valid():
            form.save()
            # Calculate total marks
            english_marks = form.cleaned_data['marks_english']
            physics_marks = form.cleaned_data['marks_physics']
            chemistry_marks = form.cleaned_data['marks_chemistry']
            total_marks = english_marks + physics_marks + chemistry_marks
    else:
        form = StudentForm()

    return render(request, 'catalog/student_form.html', {'form': form, 'total_marks': total_marks})

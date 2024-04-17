from django.shortcuts import render, redirect

def home(request):
    return render(request, 'home.html')

def calculate_cgpa(request):
    if request.method == 'POST':
        name = request.POST.get('name')
        total_marks = int(request.POST.get('total_marks'))
        cgpa = total_marks / 50
        # Store data in session
        request.session['name'] = name
        request.session['cgpa'] = cgpa
        return redirect('display_cgpa')
    else:
        return redirect('home')

def display_cgpa(request):
    name = request.session.get('name')
    cgpa = request.session.get('cgpa')
    return render(request, 'display_cgpa.html', {'name': name, 'cgpa': cgpa})

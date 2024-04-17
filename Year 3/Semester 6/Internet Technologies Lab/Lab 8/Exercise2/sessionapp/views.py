# sessionapp/views.py
from django.shortcuts import render, redirect

def first_page(request):
    if request.method == 'POST':
        name = request.POST.get('name')
        roll = request.POST.get('roll')
        subject = request.POST.get('subject')
        request.session['name'] = name
        request.session['roll'] = roll
        request.session['subject'] = subject
        return redirect('second_page')
    return render(request, 'sessionapp/firstPage.html')

def second_page(request):
    name = request.session.get('name')
    roll = request.session.get('roll')
    subject = request.session.get('subject')
    context = {'name': name, 'roll': roll, 'subject': subject}
    return render(request, 'sessionapp/secondPage.html', context)

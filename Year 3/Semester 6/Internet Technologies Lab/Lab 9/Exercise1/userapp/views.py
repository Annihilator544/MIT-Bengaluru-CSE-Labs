from django.shortcuts import render, redirect
from django.contrib import messages

def register(request):
    if request.method == 'POST':
        username = request.POST.get('username')
        email = request.POST.get('email')
        contact_number = request.POST.get('contact_number')
        # Password is not handled here for simplicity
         # Validate contact number
        if len(contact_number) < 10 or not contact_number.isdigit():
            messages.error(request, 'Contact number must be at least 10 digits long and contain only digits.')
            return redirect('register')
        # Redirect to success page with user data
        return redirect('success', username=username, email=email, contact_number=contact_number)
    return render(request, 'userapp/register.html')

def success(request, username, email, contact_number):
    return render(request, 'userapp/success.html', {'username': username, 'email': email, 'contact_number': contact_number})

# carinfo/views.py
from django.shortcuts import render

def car_info_form(request):
    return render(request, 'carinfo/car_info_form.html')

def display_car_info(request):
    if request.method == 'POST':
        manufacturer = request.POST.get('manufacturer')
        model_name = request.POST.get('model_name')
        return render(request, 'carinfo/display_car_info.html', {'manufacturer': manufacturer, 'model_name': model_name})
    else:
        return render(request, 'carinfo/car_info_form.html')

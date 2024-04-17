# groceryapp/views.py
from django.shortcuts import render
from .models import GroceryItem

def grocery_checklist(request):
    items = GroceryItem.objects.all()
    selected_items = []

    if request.method == 'POST':
        selected_item_ids = request.POST.getlist('selected_items')
        selected_items = GroceryItem.objects.filter(id__in=selected_item_ids)

    return render(request, 'groceryapp/checklist.html', {'items': items, 'selected_items': selected_items})

# groceryapp/templatetags/custom_filters.py
from django import template

register = template.Library()

@register.filter
def get_item(items, item_id):
    return items.filter(id=item_id).first()

$(document).ready(function(){
    // AJAX call to load products dynamically
    $.ajax({
        url: 'products.json',
        dataType: 'json',
        success: function(data) {
            // Iterate through each product and create product card
            $.each(data.products, function(index, product) {
                var card = `
                    <div class="product-card">
                        <img src="${product.image}" alt="${product.name}">
                        <h3>${product.name}</h3>
                        <p>$${product.price}</p>
                        <button class="add-to-cart" data-name="${product.name}" data-price="${product.price}">Add to Cart</button>
                    </div>`;
                $('#product-list').append(card);
            });
        },
        error: function(xhr, status, error) {
            console.error('Error loading products:', error);
        }
    });

    // Add to Cart functionality
    $('#product-list').on('click', '.add-to-cart', function() {
        var name = $(this).data('name');
        var price = parseFloat($(this).data('price'));

        // Check if item is already in cart
        var found = false;
        $('.cart-item').each(function() {
            if ($(this).data('name') === name) {
                var quantity = parseInt($(this).find('.quantity').text());
                $(this).find('.quantity').text(quantity + 1);
                found = true;
                return false;
            }
        });

        // If item not found in cart, add new item
        if (!found) {
            var item = `<div class="cart-item" data-name="${name}">
                            <span class="item-name">${name}</span>
                            <span class="quantity">1</span>
                            <span class="item-price">$${price.toFixed(2)}</span>
                        </div>`;
            $('.cart-items').append(item);
        }

        // Update total amount
        var total = parseFloat($('#cart-total').text());
        $('#cart-total').text((total + price).toFixed(2));

        // Open shopping cart sidebar
        $('.shopping-cart').addClass('open');
    });

    // Toggle shopping cart sidebar
    $('.shopping-cart-toggle').click(function() {
        $('.shopping-cart').toggleClass('open');
    });

    // Checkout button functionality
    $('#checkout-btn').click(function() {
        alert('Checkout functionality not implemented yet.');
    });
});

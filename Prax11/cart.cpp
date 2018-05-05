#include <algorithm>
#include <numeric>
#include "cart.h"

void Cart::add(const Item &item, size_t qty) {
    if ( qty == 0 ) {
        throw std::invalid_argument("Quantity cannot be zero");
    }

    items[item] += qty;
}

void Cart::change(const Item &item, size_t qty) {
    if ( items.count(item) == 0 ) {
        throw std::invalid_argument("Item does not exist");
    }
    if ( qty == 0 ) {
        throw std::invalid_argument("Quantity cannot be zero");
    }

    items[item] = qty;
}

void Cart::remove(const Item &item) {
    if ( items.count(item) == 0 ) {
        throw std::invalid_argument("Item does not exist");
    }

    items.erase(item);
}

void Cart::clear() {
    // items.erase(items.begin(),items.end());
    items.clear();
}

std::ostream &operator<<(std::ostream &os, const Cart &cart) {
    for ( auto itemPair : cart.items ) {
        os << itemPair.first << " qty "
           << itemPair.second << " pcs"
           << std::endl;
    }
    return os;
}

float Cart::getTotal1() {
    float price = 0;

    auto lambda = [&price] ( std::pair<Item,size_t> p ) {
        price += p.first.getPrice() * p.second;
    };

    std::for_each(items.begin(), items.end(), lambda);

    return price;
}

float Cart::getTotal2() {

    auto lambda = [] ( float total, const std::pair<Item,size_t> &p ) {
        return total + p.first.getPrice() * p.second;
    };

    return std::accumulate(items.begin(),items.end(), 0.0f, lambda);
}

Order Cart::checkOut() {
    Order o;

    for ( auto itemPair : items ) {
        o.add(itemPair.first, itemPair.second);
    }

    return o;
}

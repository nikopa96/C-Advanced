#include "order.h"

void Order::add(const Item &item, size_t qty) {
    if ( qty == 0 ) {
        throw std::invalid_argument("Quantity cannot be zero.");
    }
    items[item] += qty;
}

std::ostream &operator<<(std::ostream &os, const Order &order) {
    for ( const auto &e : order.items ) {
        os << e.first << " qty " << e.second << " pcs." << std::endl;
    }
    return os;
}

std::map<Item, size_t>::iterator Order::begin() {
    return items.begin();
}

std::map<Item, size_t>::iterator Order::end() {
    return items.end();
}

std::map<Item, size_t>::const_iterator Order::begin() const {
    return items.cbegin();
}

std::map<Item, size_t>::const_iterator Order::end() const {
    return items.cend();
}

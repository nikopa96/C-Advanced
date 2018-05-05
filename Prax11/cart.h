#ifndef PRAX11_CART_H
#define PRAX11_CART_H

#include <map>
#include "item.h"
#include "order.h"

class Cart {
public:
    void add(const Item &item, size_t qty = 1);
    void change(const Item &item, size_t qty);
    void remove(const Item &item);
    void clear();
    friend std::ostream &operator<< (std::ostream &os, const Cart &cart);
    float getTotal1();
    float getTotal2();
    Order checkOut();
private:
    std::map<Item,size_t> items;
};

#endif //PRAX11_CART_H

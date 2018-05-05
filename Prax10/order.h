#ifndef PRAX10_ORDER_H
#define PRAX10_ORDER_H

#include <map>
#include <ostream>
#include "item.h"

class Order {
public:
    void add(const Item &item, size_t qty);
    friend std::ostream &operator<< ( std::ostream &os, const Order &order );
    std::map<Item,size_t>::iterator begin();
    std::map<Item,size_t>::iterator end();
    std::map<Item,size_t>::const_iterator begin() const;
    std::map<Item,size_t>::const_iterator end() const;
private:
    std::map<Item,size_t> items;
};

#endif //PRAX10_ORDER_H

#ifndef PRAX10_STOCK_H
#define PRAX10_STOCK_H

#include <map>
#include "item.h"
#include "order.h"

class Stock {
public:
    void receive (const Order &order);
    size_t getAvailable (const Item &item);
    void dispatch(const Order &order);
    friend std::ostream &operator<< ( std::ostream& os, const Stock &stock );
private:
    std::map<Item,size_t> items;
};

#endif //PRAX10_STOCK_H

#ifndef PRAX10_ITEM_H
#define PRAX10_ITEM_H

#include <string>
#include <ostream>

class Item {
public:
    Item(const std::string &name, float price);
    friend std::ostream &operator<< ( std::ostream &os, const Item &item );
    friend bool operator< ( const Item &lhs, const Item &rhs );
    float getPrice() const { return price; }
    friend bool operator== ( const Item &lhs, const Item &rhs );
public:
private:
    std::string name;
    float price;
};

#endif //PRAX10_ITEM_H

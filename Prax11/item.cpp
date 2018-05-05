#include <cmath>
#include "item.h"

Item::Item(const std::string &name, float price) {
    this->name = name;
    this->price = price;
}

std::ostream &operator<<(std::ostream &os, const Item &item) {
    return os << item.name << " @ " << item.price << " EUR";
}

bool operator<(const Item &lhs, const Item &rhs) {
    return lhs.name < rhs.name;
}

bool operator==(const Item &lhs, const Item &rhs) {
    return  lhs.name == rhs.name &&
            std::fabs(lhs.price - rhs.price) < 0.0001;
}

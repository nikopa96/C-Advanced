#ifndef PRAX10_STOCK_H
#define PRAX10_STOCK_H

#include <map>
#include <set>
#include <vector>
#include "item.h"
#include "order.h"

using Transaction = std::tuple<Item,int,Order>;

struct TransactionComparator {
    bool operator() (const Transaction &lhs, const Transaction &rhs) {
        float price1 = std::get<0>(lhs).getPrice() *
                       std::abs(std::get<1>(lhs));

        float price2 = std::get<0>(rhs).getPrice() *
                       std::abs(std::get<1>(rhs));

        return price1 < price2;
    }
};

class Stock {
public:
    void receive (const Order &order);
    size_t getAvailable (const Item &item);
    void dispatch(const Order &order);
    friend std::ostream &operator<< ( std::ostream& os, const Stock &stock );
    size_t countAllTransactions();
    std::vector<Transaction> countItemTransactions1(const Item &item);
    std::vector<Transaction> countItemTransactions2(const Item &item);
private:
    std::map<Item,size_t> items;
    std::multiset<Transaction,TransactionComparator> transactions;
};

#endif //PRAX10_STOCK_H

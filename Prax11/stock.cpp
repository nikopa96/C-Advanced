#include <sstream>
#include <algorithm>
#include <numeric>
#include "stock.h"

void Stock::receive(const Order &order) {
    for ( const auto &e : order ) {
        const Item &item = e.first;
        const size_t &qty = e.second;
        items[item] += qty;

        // items[e.first] += e.second

        transactions.emplace(item,qty,order);
    }
}

size_t Stock::getAvailable(const Item &item) {
    if ( !items.count(item) ) {
        std::stringstream ss;
        ss << "Stock has no items " << item;
        throw std::invalid_argument(ss.str());
    }
    return items[item];
}

void Stock::dispatch(const Order &order) {
    for ( const auto &e : order ) {
        const Item &requestedItem = e.first;
        const size_t &requestedQty = e.second;

        if ( !items.count(requestedItem) ) {
            std::stringstream ss;
            ss << "Item " << requestedItem << " is not available in stock."
               << std::endl;
            throw std::invalid_argument(ss.str());
        }

        const size_t &availableQty = items[requestedItem];

        if ( availableQty < requestedQty ) {
            std::stringstream ss;
            ss << "Stock does not have enough items of "
               << requestedItem;
            throw std::invalid_argument(ss.str());
        }

        items[requestedItem] -= requestedQty;

        transactions.emplace(requestedItem,-requestedQty,order);

        if ( items[requestedItem] == 0 ) {
            items.erase(requestedItem);
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Stock &stock) {
    os << "Store contains " << stock.items.size()
              << " items." << std::endl;
    for ( const auto &e : stock.items ) {
        os << e.first << " qty " << e.second << " pcs." << std::endl;
    }
    return os;
}

size_t Stock::countAllTransactions() {
    return transactions.size();
}

std::vector<Transaction> Stock::countItemTransactions1(const Item &item) {

    std::vector<Transaction> output;

    std::for_each(
        transactions.begin(), transactions.end(),
        [&output,item] ( const Transaction &t ) {
            if ( std::get<0>(t) == item ) {
                output.push_back(t);
            }
        }
    );

    return output;
}

std::vector<Transaction> Stock::countItemTransactions2(const Item &item) {
    return std::accumulate(
        transactions.begin(), transactions.end(),
        std::vector<Transaction>(),
        [item] ( std::vector<Transaction> &total,
                 const Transaction &t ) {
            if ( std::get<0>(t) == item ) {
                total.push_back(t);
            }
            return total;
        }
    );
}

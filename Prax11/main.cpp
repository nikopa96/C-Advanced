#include <iostream>
#include "item.h"
#include "order.h"
#include "stock.h"
#include "cart.h"

int main() {

    Item i1("Bread", 0.95);
    Item i2("Milk", 0.55);

    Order receipt, receipt2;
    try {
        receipt.add(i1,1);
        receipt.add(i2,5);
        receipt2.add(i1,3);
    } catch ( const std::invalid_argument &e ) {
        std::cerr << e.what() << std::endl;
    }

    Stock s;
    s.receive(receipt);
    s.receive(receipt2);

    Order shipment;
    try {
        shipment.add(i1,3);
        shipment.add(i2,5);
        s.dispatch(shipment);
    } catch ( const std::exception &e ) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << s.getAvailable(i1) << std::endl;
    } catch ( const std::exception &e ) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << s << std::endl;

    try {
        Cart c;
        c.add(i1);
        c.add(i2,2);
        c.change(i1,3);
        c.remove(i2);
        c.add(i2,2);

        std::cout << "CART: " << std::endl << c << std::endl;

        std::cout << "Total price " << c.getTotal1() << std::endl;
        std::cout << "Total price " << c.getTotal2() << std::endl;

        c.clear();
        c.add(i1,1);

        std::cout << "STOCK: " << std::endl << s << std::endl;

        Order shipment2 = c.checkOut();
        s.dispatch(shipment2);

        std::cout << "Total transactions "
                  << s.countAllTransactions()
                  << std::endl;

        auto breadTransactions1 = s.countItemTransactions1(i1);
        auto milkTransactions1 = s.countItemTransactions1(i2);
        auto breadTransactions2 = s.countItemTransactions2(i1);
        auto milkTransactions2 = s.countItemTransactions2(i2);

        std::cout << "Bread transactions "
                  << breadTransactions1.size()
                  << std::endl;

        std::cout << "Milk transactions "
                  << milkTransactions1.size()
                  << std::endl;

        std::cout << "Bread transactions "
                  << breadTransactions2.size()
                  << std::endl;

        std::cout << "Milk transactions "
                  << milkTransactions2.size()
                  << std::endl;

    } catch ( const std::exception &e ) {
        std::cout << "Exception " << e.what() << std::endl;
    }

    return 0;
}
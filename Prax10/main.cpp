#include <iostream>
#include "item.h"
#include "order.h"
#include "stock.h"

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

    return 0;
}
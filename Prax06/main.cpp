#include <iostream>
#include "tree.h"

int main() {

    MyTree tree;

    std::cout << "(5*3) + (2*8) = "
              << tree.evaluateExpression()
              << std::endl;

    std::cout << tree.toString() << std::endl;

    std::cout << "Number of leafs in the tree is "
              << tree.countLeafs() << std::endl;

    return 0;
}
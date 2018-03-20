#ifndef HW01_MYLINKEDLIST_H
#define HW01_MYLINKEDLIST_H

#include <cstddef>
#include <ostream>
#include "Node.h"

class MyLinkedList {
public:
    MyLinkedList();
    MyLinkedList(int n, int v);
    MyLinkedList(const MyLinkedList &myLinkedListCopy);

    size_t getLength() const;
    void push_front(int i);
    void push_back(int i);
    void insert(size_t position, int element);
    void remove(size_t number);
    static void applyUnaryOperator(MyLinkedList &list, int (*unaryOperator)(int));

    friend std::ostream& operator<<(std::ostream& os, const MyLinkedList &myLinkedList);
    int& operator[](std::size_t index);
    const int& operator[](std::size_t index) const;
    MyLinkedList& operator=(const MyLinkedList &myLinkedListCopy);
    bool operator==(const MyLinkedList& myLinkedList);

    ~MyLinkedList();
private:
    Node *currentNode;
};

#endif //HW01_MYLINKEDLIST_H

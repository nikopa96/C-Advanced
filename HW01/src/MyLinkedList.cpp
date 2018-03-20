#include <iostream>
#include "MyLinkedList.h"

MyLinkedList::MyLinkedList() : currentNode(nullptr) {}

MyLinkedList::MyLinkedList(int n, int v) : currentNode(nullptr) {
    for (int i = 0; i < n; i++) {
        push_back(v);
    }
}

MyLinkedList::MyLinkedList(const MyLinkedList &myLinkedListCopy) : currentNode(nullptr) {
    Node *firstNode = myLinkedListCopy.currentNode;
    while (firstNode) {
        push_back(firstNode->value);
        firstNode = firstNode->nextNode;
    }
}

size_t MyLinkedList::getLength() const {
    size_t length = 0;
    Node *firstNode = this->currentNode;

    while (firstNode) {
        length++;
        firstNode = firstNode->nextNode;
    }

    return length;
}

void MyLinkedList::push_front(int i) {
    auto *newNode = new Node();
    newNode->value = i;
    newNode->nextNode = this->currentNode;
    this->currentNode = newNode;
}

void MyLinkedList::push_back(int i) {
    Node *firstNode = this->currentNode;

    auto *backNode = new Node();
    backNode->value = i;

    if (firstNode == nullptr) {
        backNode->nextNode = this->currentNode;
        this->currentNode = backNode;
    } else {
        while (firstNode) {
            if (firstNode->nextNode == nullptr) {
                firstNode->nextNode = backNode;
                break;
            }

            firstNode = firstNode->nextNode;
        }
    }
}

void MyLinkedList::insert(size_t position, int element) {
    Node *firstNode = this->currentNode;

    auto *newNode = new Node();
    newNode->value = element;

    if (firstNode == nullptr || position == 0) {
        newNode->nextNode = this->currentNode;
        this->currentNode = newNode;
    } else {
        for (int i = 1; i <= position; i++) {
            if (i == position) {
                newNode->nextNode = firstNode->nextNode;
                firstNode->nextNode = newNode;
            } else {
                firstNode = firstNode->nextNode;
            }
        }
    }
}

void MyLinkedList::remove(size_t position) {
    Node *firstNode = this->currentNode;
    auto *newNode = new Node();

    for (int i = 0; i < position; i++) {
        newNode = firstNode;
        firstNode = firstNode->nextNode;
    }

    if (position > 0) {
        newNode->nextNode = firstNode->nextNode;
    } else {
        this->currentNode = firstNode->nextNode;
    }

    delete firstNode;
}

void MyLinkedList::applyUnaryOperator(MyLinkedList &list, int (*unaryOperator)(int)) {
    Node *firstNode = list.currentNode;

    while (firstNode) {
        firstNode->value = unaryOperator(firstNode->value);
        firstNode = firstNode->nextNode;
    }
}

std::ostream &operator<<(std::ostream &os, const MyLinkedList &myLinkedList) {
    Node *firstNode = myLinkedList.currentNode;

    while (firstNode) {
        os << firstNode->value << " ";
        firstNode = firstNode->nextNode;
    }

    return os;
}

int &MyLinkedList::operator[](std::size_t index) {
    Node *firstNode = this->currentNode;

    for (int i = 0; i <= index; i++) {
        if (i == index) {
            return firstNode->value;
        } else {
            firstNode = firstNode->nextNode;
        }
    }
}

const int &MyLinkedList::operator[](std::size_t index) const {
    Node *firstNode = this->currentNode;

    for (int i = 0; i <= index; i++) {
        if (i == index) {
            return firstNode->value;
        } else {
            firstNode = firstNode->nextNode;
        }
    }
}

MyLinkedList& MyLinkedList::operator=(const MyLinkedList &myLinkedListCopy) {
    this->currentNode = nullptr;

    Node *firstNode = myLinkedListCopy.currentNode;
    while (firstNode) {
        push_back(firstNode->value);
        firstNode = firstNode->nextNode;
    }

    return *this;
}

bool MyLinkedList::operator==(const MyLinkedList &myLinkedList) {

    Node *firstNode = this->currentNode;
    Node *copiedFirstNode = myLinkedList.currentNode;

    while (firstNode) {
        if (firstNode->value != copiedFirstNode->value) {
            return false;
        }

        if ((firstNode->nextNode == nullptr && copiedFirstNode->nextNode != nullptr)
            || (firstNode->nextNode != nullptr && copiedFirstNode->nextNode == nullptr)) {
            return false;
        }

        copiedFirstNode = copiedFirstNode->nextNode;
        firstNode = firstNode->nextNode;
    }

    return true;
}

MyLinkedList::~MyLinkedList() {
    Node *firstNode = this->currentNode;

    while (firstNode) {
        Node *nextNode = firstNode->nextNode;
        delete firstNode;
        firstNode = nextNode;
    }

}

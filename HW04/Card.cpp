#include "Card.h"

bool Card::onPickedUp() {
    return isPicked;
}

bool Card::onDroped() {
    return isDroped;
}

void Card::setCardPickedState() {
    this->isPicked = true;
    this->isDroped = false;
}

void Card::setCardDropedState() {
    this->isPicked = false;
    this->isDroped = false;
}

std::string ModifierCard::getCardType() {
    return cardType;
}

std::string ActionCard::getCardType() {
    return cardType;
}

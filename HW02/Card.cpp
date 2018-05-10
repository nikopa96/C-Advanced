#include <iostream>
#include "Card.h"
#include "Player.h"

void Card::onPickedUp(Player &player) {

}

void Card::onDroped(Player &player) {

}

void Card::setCardPickedState() {
    this->isPicked = true;
    this->isDroped = false;
}

void Card::setCardDropedState() {
    this->isPicked = false;
    this->isDroped = false;
}

void VitalityCard::onPickedUp(Player &player) {
    if (isPicked) {
        player.increaseVitality();
        player.increaseMaxVitality();
    }
}

void VitalityCard::onDroped(Player &player) {
    if (isDroped) {
        player.maxVitality--;
    }
}

void PrizeCard::onPickedUp(Player &player) {
    if (isPicked) {
        player.point++;
    }
}

void PrizeCard::onDroped(Player &player) {

}

void RestlessExplorerCard::onPickedUp(Player &player) {
    if (isPicked) {
        player.vitality++;
    }
}

void RestlessExplorerCard::onDroped(Player &player) {

}

void ZippyCard::onPickedUp(Player &player) {
    if (isPicked) {
        player.vitality++;
    }
}

void ZippyCard::onDroped(Player &player) {

}

void HypnoticCard::onPickedUp(Player &player) {
    if (isPicked) {
        player.vitality = 0;
    }
}

void HypnoticCard::onDroped(Player &player) {

}

void StickyCard::onPickedUp(Player &player) {

}

void StickyCard::onDroped(Player &player) {
    setCardPickedState();
}

void DistractCard::onPickedUp(Player &player) {

}

void DistractCard::onDroped(Player &player) {
    if (isPicked) {
        player.randomDrop();
    }
}

std::string StickyCard::getCardType() const {
    return "StickyCard";
}

std::string PrizeCard::getCardType() const {
    return "PrizeCard";
}

std::string VitalityCard::getCardType() const {
    return "VitalityCard";
}

std::string RestlessExplorerCard::getCardType() const {
    return "RestlessExplorerCard";
}

std::string DistractCard::getCardType() const {
    return "DistractCard";
}

std::string RewindCard::getCardType() const {
    return "RewindCard";
}

std::string ZippyCard::getCardType() const {
    return "ZippyCard";
}

std::string HypnoticCard::getCardType() const {
    return "HypnoticCard";
}

std::string DispelCard::getCardType() const {
    return "DispelCard";
}

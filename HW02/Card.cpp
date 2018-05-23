#include <iostream>
#include <sstream>
#include <random>
#include <algorithm>
#include "Card.h"
#include "Player.h"

void Card::onPickedUp(Player &player) {

}

void Card::onDroped(Player &player) {

}

void Card::setCardPickedState() {
    this->isPicked = true;
}

void Card::setCardDropedState() {
    this->isPicked = false;
}

void Card::doAction(Player &player) {
    if (isPicked) {
        onPickedUp(player);
    } else {
        onDroped(player);
    }
}

void VitalityCard::onPickedUp(Player &player) {
    player.vitality++;
    player.maxVitality++;
}

void VitalityCard::onDroped(Player &player) {
    player.maxVitality = 3;

    if (player.vitality > player.maxVitality) {
        player.vitality = player.maxVitality;
    }
}

void PrizeCard::onPickedUp(Player &player) {
    player.point++;
}

void PrizeCard::onDroped(Player &player) {
}

void RestlessExplorerCard::onPickedUp(Player &player) {
    if (savedPlayerVitality) {
        player.vitality = savedPlayerVitality;
    } else {
        savedPlayerVitality = player.vitality;
        savedPlayerVitality++;
    }
}

void RestlessExplorerCard::onDroped(Player &player) {
}

void ZippyCard::onPickedUp(Player &player) {
    player.vitality++;

    player.cardStorageForPlayer.pop_back();
}

void ZippyCard::onDroped(Player &player) {
}

void HypnoticCard::onPickedUp(Player &player) {
    player.vitality = 0;

    player.cardStorageForPlayer.pop_back();
}

void HypnoticCard::onDroped(Player &player) {

}

void StickyCard::onPickedUp(Player &player) {
}

void StickyCard::onDroped(Player &player) {
}

void DistractCard::onPickedUp(Player &player) {
    player.cardStorageForPlayer.pop_back();

    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> randomNumber(0, player.cardStorageForPlayer.size() - 1);

    size_t randomNumberOfElement = randomNumber(rng);
    std::shared_ptr<Card> removedCard = player.cardStorageForPlayer[randomNumberOfElement];

    std::cout << removedCard.get()->getCardType() << " (" << removedCard.get() << ")" << " has been removed" << std::endl;

    player.cardStorageForPlayer.erase(player.cardStorageForPlayer.begin() + randomNumberOfElement);
}

void DistractCard::onDroped(Player &player) {
}

void DispelCard::onPickedUp(Player &player) {
}

void DispelCard::activateForPlayer(Player &player) {
    std::cout << "CONGRATULATIONS!!! " << player.name << " has exit from Wonderland!" << std::endl;

    size_t amountOfPrizeCards = 0;
    for (int i = 0; i < player.cardStorageForPlayer.size(); i++) {
        if (player.cardStorageForPlayer[i]->getCardType() == "PrizeCard") {
            amountOfPrizeCards++;
        }
    }

    std::cout << "AMOUNT OF PRIZECARDS: " << amountOfPrizeCards << std::endl;

    std::stringstream ss;
    ss << "game over";
    throw std::runtime_error(ss.str());
}

void DispelCard::onDroped(Player &player) {
}

void RewindCard::onPickedUp(Player &player) {
    player.current = player.start;
    player.current->enter(&player);

    player.cardStorageForPlayer.pop_back();
}

void RewindCard::onDroped(Player &player) {
    Card::onDroped(player);
}

std::string StickyCard::getCardType() const {
    return "sticky";
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

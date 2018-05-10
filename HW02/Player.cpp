#include <sstream>
#include <thread>
#include <iostream>
#include <algorithm>
#include "Player.h"

Player::Player(const std::string &playerName, std::shared_ptr<Tile> &&tile) {
    name = playerName;
    vitality = defaultVitality;
    maxVitality = defaultVitality;
    current = start = std::move(tile);
    current->enter(this);
}


std::ostream &operator<<(std::ostream &os, const Player &player) {
    return os << player.name;
}

void Player::forward() {
    modifierCardsManager();

    if ( ! current->next ) {
        std::stringstream ss;
        ss << *current
           << " is the last tile in the sequence, "
           << name << " cannot move forward.";
        throw std::runtime_error(ss.str());
    }

    if (vitality == 0) {
        std::stringstream ss;
        ss << name << ": I am too tired to move";
        throw std::runtime_error(ss.str());
    }

    current->leave(this);
    current = current->next;
    current->enter(this);

    decreaseVitality();
}

void Player::backward() {
    modifierCardsManager();

    if ( ! current->prev ) {
        std::stringstream ss;
        ss << *current
           << " is the first tile in the sequence, "
           << name << " cannot move backward";
        throw std::runtime_error(ss.str());
    }

    if (vitality == 0) {
        std::stringstream ss;
        ss << name << ": I am too tired to move";
        throw std::runtime_error(ss.str());
    }

    current->leave(this);
    current = current->prev;
    current->enter(this);

    decreaseVitality();
}

void Player::sleep() {
    std::cout << name << " is sleeping" << std::endl;
    vitality = defaultVitality;
}

void Player::reset() {
    current->leave(this);
    current = start;
    current->enter(this);
}

void Player::operator()() {
    try {
        for (auto i=0; i<3; i++) {
            forward();
            forward();
            forward();
            reset();
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
        }

    } catch ( const std::exception &e ) {
        std::cerr << e.what() << std::endl;
    }
}

size_t Player::getVitality() {
    return vitality;
}

void Player::increaseVitality() {
    vitality++;
}

void Player::decreaseVitality() {
    vitality--;
}

size_t Player::getMaxVitality() {
    return maxVitality;
}

void Player::increaseMaxVitality() {
    maxVitality++;
}

size_t Player::getCardsByName(std::string cardName) {
    auto it = cardStorageForPlayer.begin();

    while (it != cardStorageForPlayer.end()) {
        if (it->get()->getCardType() == cardName) {
            std::cout << it->get()->getCardType() << std::endl;
        }
        it++;
    }
}

std::shared_ptr<Card> Player::getCardByName(std::string cardName) {
    auto it = cardStorageForPlayer.begin();

    while (it != cardStorageForPlayer.end()) {
        if (it->get()->getCardType() == cardName) {
            return *it;
        }
        it++;
    }
}

std::vector<std::shared_ptr<Card>> Player::getCards() {
    return cardStorageForPlayer;
}

void Player::pickUp() {
    if (current->cardStorage.empty()) {
        std::stringstream ss;
        ss << *current
           << ": this tile has no cards";
        throw std::runtime_error(ss.str());
    }

    if (cardStorageForPlayer.size() > 5) {
        std::stringstream ss;
        ss << *current
           << ": Cards must be less than 5";
        throw std::runtime_error(ss.str());
    }

    current->cardStorage[0]->setCardPickedState();
    cardStorageForPlayer.push_back(current->cardStorage[0]);

    std::cout << "==== TEST ==== Added card to player's card storage: " << current->cardStorage[0] << std::endl;

    current->cardStorage.erase(current->cardStorage.begin());

    std::cout << "==== TEST ==== Tile's current vector size: " << current->cardStorage.size() << std::endl;
    std::cout << "==== TEST ==== Player's current vector size: " << cardStorageForPlayer.size() << std::endl;

    modifierCardsManager();
}

void Player::drop(std::shared_ptr<Card> card) {
    if (cardStorageForPlayer.empty()) {
        std::stringstream ss;
        ss << name << ": has no cards";
        throw std::runtime_error(ss.str());
    }

    auto it = cardStorageForPlayer.begin();
    while (it != cardStorageForPlayer.end()) {
        if (*it == card) {
            card->setCardDropedState();
            it = cardStorageForPlayer.erase(it);
        } else {
            ++it;
        }
    }
}

void Player::modifierCardsManager() {
    if (!cardStorageForPlayer.empty()) {
        const std::string vitalityCardType = "VitalityCard";

        std::for_each(cardStorageForPlayer.begin(), cardStorageForPlayer.end(),
                      [this, &vitalityCardType](std::shared_ptr<Card> &card) {
                          if (card.get()->getCardType() == vitalityCardType) {
                              card->onPickedUp(*this);
                              card->onDroped(*this);
                          }

                      }
        );

    }
}

void Player::randomDrop() {
    if (!cardStorageForPlayer.empty()) {
        cardStorageForPlayer.erase(cardStorageForPlayer.begin());
    }
}

FlyingPlayer::FlyingPlayer(const std::string &playerName, std::shared_ptr<Tile> &&tile) : Player(playerName, std::move(tile)) {}

void FlyingPlayer::pickUp() {
    if (current->cardStorage.empty()) {
        std::stringstream ss;
        ss << *current
           << ": this tile has no cards";
        throw std::runtime_error(ss.str());
    }

    if (cardStorageForPlayer.size() > 3) {
        std::stringstream ss;
        ss << *current
           << ": Cards must be less than 3";
        throw std::runtime_error(ss.str());
    }

    current->cardStorage[0]->setCardPickedState();
    cardStorageForPlayer.push_back(current->cardStorage[0]);

    std::cout << "==== TEST ==== Added card to player's card storage: " << current->cardStorage[0] << std::endl;

    current->cardStorage.erase(current->cardStorage.begin());

    std::cout << "==== TEST ==== Tile's current vector size: " << current->cardStorage.size() << std::endl;
    std::cout << "==== TEST ==== Player's current vector size: " << cardStorageForPlayer.size() << std::endl;

    modifierCardsManager();
}

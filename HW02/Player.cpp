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
    std::cout << name << " initial vitality is: " << vitality << std::endl;
    current->enter(this);
}

std::string Player::getName() {
    return name;
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    return os << player.name;
}

void Player::forward() {
    runCardModifier();

    if ( ! current->next ) {
        std::stringstream ss;
        ss << "EXCEPTION: " << *current
           << " is the last tile in the sequence, "
           << name << " cannot move forward.";
        throw std::runtime_error(ss.str());
    }

    if (vitality == 0) {
        std::stringstream ss;
        ss << "EXCEPTION: " << name << ": I am too tired to move";
        throw std::runtime_error(ss.str());
    }

    vitality--;

    current->leave(this);
    current = current->next;
    current->enter(this);
}

void Player::backward() {
    runCardModifier();

    if ( ! current->prev ) {
        std::stringstream ss;
        ss << "EXCEPTION: " << *current
           << " is the first tile in the sequence, "
           << name << " cannot move backward";
        throw std::runtime_error(ss.str());
    }

    if (vitality == 0) {
        std::stringstream ss;
        ss << "EXCEPTION: " << name << ": I am too tired to move";
        throw std::runtime_error(ss.str());
    }

    vitality--;

    current->leave(this);
    current = current->prev;
    current->enter(this);
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
    std::cout << "what" << std::endl;

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

size_t Player::getMaxVitality() {
    return maxVitality;
}

size_t Player::getCardsByName(std::string cardName) {
    size_t rangeOfCards = 0;
    auto it = cardStorageForPlayer.begin();

    while (it != cardStorageForPlayer.end()) {
        if (it->get()->getCardType() == cardName) {
            rangeOfCards++;
        }
        it++;
    }

    return rangeOfCards;
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
        ss << "EXCEPTION: " << *current
           << ": this tile has no cards";
        throw std::runtime_error(ss.str());
    }

    if (cardStorageForPlayer.size() >= 5) {
        std::stringstream ss;
        ss << "EXCEPTION: " << name
           << ": can have max 5";
        throw std::runtime_error(ss.str());
    }

    cardStorageForPlayer.push_back(current->cardStorage[0]);

    std::cout << "Added card to " << name <<" card storage: " << current->cardStorage[0]->getCardType() <<
              " (" << cardStorageForPlayer.back() << ") " << std::endl;

    current->cardStorage.erase(current->cardStorage.begin());

    std::cout << current->name << " current vector size: " << current->cardStorage.size() << std::endl;
    std::cout << name <<" current vector size: " << cardStorageForPlayer.size() << std::endl;

    cardStorageForPlayer.back()->setCardPickedState();
    cardStorageForPlayer.back()->doAction(*this);
}

void Player::drop(std::shared_ptr<Card> card) {
    if (cardStorageForPlayer.empty()) {
        std::stringstream ss;
        ss << "EXCEPTION: " << name << ": has no cards";
        throw std::runtime_error(ss.str());
    }

    auto it = cardStorageForPlayer.begin();
    while (it != cardStorageForPlayer.end()) {
        if (*it == card) {
            card->setCardDropedState();
            card->doAction(*this);

            if (card->getCardType() != "sticky") {
                std::cout << name << " has droped " << it->get()->getCardType() << " (" << *it << ") " << std::endl;

                current->cardStorage.push_back(*it);

                it = cardStorageForPlayer.erase(it);
                return;
            } else {
                std::stringstream ss;
                ss << "EXCEPTION: " << name << ": this card" << " (" << card << ") " << "is " << card->getCardType() << ". You cannot drop the card!";
                throw std::runtime_error(ss.str());
            }
        } else {
            ++it;
        }
    }

    std::stringstream ss;
    ss << "EXCEPTION: " << name << ": this card " << card->getCardType() << " (" << card << ") " << "does not found";
    throw std::runtime_error(ss.str());
}

void Player::runCardModifier() {
    if (!cardStorageForPlayer.empty()) {
        for (int i = 0; i < cardStorageForPlayer.size(); i++) {
            cardStorageForPlayer[i]->doAction(*this);
        }
    }
}

FlyingPlayer::FlyingPlayer(const std::string &playerName, std::shared_ptr<Tile> &&tile) : Player(playerName, std::move(tile)) {}

void FlyingPlayer::pickUp() {
    if (current->cardStorage.empty()) {
        std::stringstream ss;
        ss << "EXCEPTION: " << *current
           << ": this tile has no cards";
        throw std::runtime_error(ss.str());
    }

    if (cardStorageForPlayer.size() >= 3) {
        std::stringstream ss;
        ss << "EXCEPTION: " << name
           << ": can have max 3";
        throw std::runtime_error(ss.str());
    }

    cardStorageForPlayer.push_back(current->cardStorage[0]);

    std::cout << "Added card to " << name <<" card storage: " << current->cardStorage[0]->getCardType() <<
              " (" << cardStorageForPlayer.back() << ") " << std::endl;

    current->cardStorage.erase(current->cardStorage.begin());

    std::cout << current->name << " current vector size: " << current->cardStorage.size() << std::endl;
    std::cout << name <<" current vector size: " << cardStorageForPlayer.size() << std::endl;

    cardStorageForPlayer.back()->setCardPickedState();
    cardStorageForPlayer.back()->doAction(*this);
}

void FlyingPlayer::forward() {
    runCardModifier();

    if ( ! current->next ) {
        std::stringstream ss;
        ss << "EXCEPTION: " << *current
           << " is the last tile in the sequence, "
           << name << " cannot move forward.";
        throw std::runtime_error(ss.str());
    }

    current->leave(this);
    current = current->next;
    current->enter(this);
}

void FlyingPlayer::backward() {
    runCardModifier();

    if ( ! current->prev ) {
        std::stringstream ss;
        ss << "EXCEPTION: " << *current
           << " is the first tile in the sequence, "
           << name << " cannot move backward";
        throw std::runtime_error(ss.str());
    }

    current->leave(this);
    current = current->prev;
    current->enter(this);
}

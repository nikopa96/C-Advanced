#include <sstream>
#include <thread>
#include <iostream>
#include "Player.h"
#include "Card.h"
#include "Tile.h"

Player::Player(const std::string &playerName, std::shared_ptr<Tile> &&tile) {
    name = playerName;
    currentTile = start = std::move(tile);
}

size_t Player::getVitality() {
    return vitality;
}

size_t Player::getMaxVitality() {
    return maxVitality;
}

void Player::increaseVitality() {
    vitality++;
}

void Player::increaseMaxVitality() {
    maxVitality++;
}

void Player::forward() {
    if (!currentTile->next) {
        std::stringstream ss;
        ss << *currentTile
           << " is the last tile in the sequence, "
           << name << " cannot move forward.";
        throw std::runtime_error(ss.str());
    }

    currentTile->leave(this);
    currentTile = currentTile->next;
    currentTile->enter(this);
}

void Player::backward() {
    if (!currentTile->prev) {
        std::stringstream ss;
        ss << *currentTile
           << " is the first tile in the sequence, "
           << name << " cannot move backward";
        throw std::runtime_error(ss.str());
    }

    currentTile->leave(this);
    currentTile = currentTile->prev;
    currentTile->enter(this);
}

void Player::sleep() {
    std::cout << name << "is sleeping" << std::endl;
}

void Player::pickUp() {
    if (currentTile->cardStorage.empty()) {
        std::stringstream ss;
        ss << *currentTile
           << "this tile has not cards";
        throw std::runtime_error(ss.str());
    }

    cardStorageForPlayer.push_back(currentTile->cardStorage[0]);
}

void Player::reset() {

}

size_t Player::getCardsByName(std::string cardName) {
    return 0;
}

void Player::drop(std::shared_ptr<const Card> card) {

}

std::shared_ptr<const Card> Player::getCardByName(std::string cardName) {
    return std::shared_ptr<const Card>();
}

std::vector<std::shared_ptr<const Card>> Player::getCards() {
    return cardStorageForPlayer;
}

std::ostream &operator<<(std::ostream &os, const std::vector<std::shared_ptr<const Card>> &cardStorageForPlayerVector) {
    return os;
}

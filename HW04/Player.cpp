#include <sstream>
#include <thread>
#include <iostream>
#include "Player.h"

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

void Player::backward() {
    if (!currentTile->prev) {
        std::stringstream ss;
        ss << *currentTile
           << " is the first tile in the sequence, "
           << name << " cannot move backward";
        throw std::runtime_error(ss.str());
    }
}

void Player::forward() {
    if (!currentTile->next) {
        std::stringstream ss;
        ss << *currentTile
           << " is the last tile in the sequence, "
           << name << " cannot move forward.";
        throw std::runtime_error(ss.str());
    }
}

void Player::sleep() {

}

void Player::pickUp() {
    std::cout << "ok" << std::endl;
}

void Player::reset() {

}

std::vector<Card> Player::getCards() {
    return std::vector<Card>();
}

size_t Player::getCardsByName(std::string cardName) {
    return 0;
}

void Player::drop(std::shared_ptr<const Card> card) {

}

std::shared_ptr<const Card> Player::getCardByName(std::string cardName) {
    return std::shared_ptr<const Card>();
}

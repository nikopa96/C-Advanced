#include "Tile.h"
#include <iostream>
#include <random>
#include <chrono>
#include <sstream>
#include "Player.h"

Tile::Tile(const std::string &tileName) {
    name = tileName;
}

std::ostream &operator<<(std::ostream &os, const Tile &t) {
    return os << t.name;
}

void Tile::enter(Player *player) {
    std::cout << *player << " entered tile " << name << std::endl;
}

void Tile::leave(Player *player) {
    std::cout << *player << " left tile " << name << std::endl;
}

void Tile::addCard(std::shared_ptr<Card> card) {
    std::cout << "Tile ADD CARD: " << card << std::endl;
    cardStorage.push_back(card);
}

std::shared_ptr<const Card> Tile::getFirstCard() {
    return cardStorage[0];
}

std::vector<std::shared_ptr<Card>> Tile::getCardStorage() const {
    return cardStorage;
}

void Tile::reset() {
    cardStorage.clear();
}

void ExitWonderlandTile::enter(Player *player) {
    std::cout << "SUCCESS! " << *player << " has left the WONDERLAND!" << std::endl;
}

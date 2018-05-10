#include <iostream>
#include "Tile.h"
#include "Player.h"

Tile::Tile() = default;

ExitWonderlandTile::ExitWonderlandTile() = default;

Tile::Tile(const std::string &tileName) {
    name = tileName;
}

std::string Tile::getTileNameTest() {
    return name;
}

std::ostream &operator<<(std::ostream &os, const Tile &t) {
    return os << t.name;
}

void Tile::addCard(std::shared_ptr<const Card> card) {
    cardStorage.push_back(card);
}

void Tile::enter(Player *player) {
//    std::cout << player << " is walking forward to " << name << std::endl;
}

void Tile::leave(Player *player) {
//    std::cout << player << " is walking backward to " << name << std::endl;
}

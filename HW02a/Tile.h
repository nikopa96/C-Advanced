#ifndef PRAX12_TILE_H
#define PRAX12_TILE_H

#include <string>
#include <memory>
#include <ostream>
#include <vector>
#include <list>
#include "Card.h"
#include "Player.h"

class Tile {
    friend class Board;
    friend class Player;
public:
    Tile();
    explicit Tile(const std::string &tileName);
    friend std::ostream &operator<< (std::ostream &os, const Tile &t);
    void addCard(std::shared_ptr<const Card> card);
    std::string getTileNameTest();

    void enter(Player *player);
    void leave(Player *player);
protected:
    std::vector<std::shared_ptr<const Card>> cardStorage;

    std::string name;
    std::shared_ptr<Tile> prev, next;
};

class ExitWonderlandTile : public Tile {
public:
    ExitWonderlandTile();
};

#endif //PRAX12_TILE_H

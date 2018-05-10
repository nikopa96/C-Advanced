#ifndef PRAX12_TILE_H
#define PRAX12_TILE_H

#include <string>
#include <memory>
#include <ostream>
#include <vector>
#include "Card.h"

class Player;

class Tile {
    friend class Board;
    friend class Player;
    friend class FlyingPlayer;
public:
    Tile() = default;
    explicit Tile(const std::string &tileName);
    virtual void enter(Player *player);
    void leave(Player *player);
    void addCard(std::shared_ptr<Card> card);

    void reset();

    std::shared_ptr<const Card> getFirstCard();
    std::vector<std::shared_ptr<Card>> getCardStorage() const;

    friend std::ostream &operator<< (std::ostream &os, const Tile &t);
protected:
    std::vector<std::shared_ptr<Card>> cardStorage;
    std::string name;
    std::shared_ptr<Tile> prev, next;
};

class ExitWonderlandTile : public Tile {
public:
    ExitWonderlandTile() = default;
    void enter(Player *player) override;
};

#endif //PRAX12_TILE_H

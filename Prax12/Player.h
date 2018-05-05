#ifndef PRAX12_PLAYER_H
#define PRAX12_PLAYER_H

#include <string>
#include "Tile.h"

class Player {
    friend class LotteryTile;
    friend class HotelTile;
    friend class GhettoTile;
    friend class ResetTile;
public:
    Player(const std::string &playerName, std::shared_ptr<Tile> &&tile);
    friend std::ostream &operator<< (std::ostream &os, const Player &player);
    void forward();
    void backward();
    void reset();
    void operator()();
private:
    std::string name;
    size_t coins;
    std::shared_ptr<Tile> start, current;
};

#endif //PRAX12_PLAYER_H

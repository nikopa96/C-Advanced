#ifndef PRAX12_TILE_H
#define PRAX12_TILE_H

#include <string>
#include <memory>
#include <ostream>

class Player;

class Tile {
    friend class Board;
    friend class Player;
public:
    explicit Tile(const std::string &tileName);
    friend std::ostream &operator<< (std::ostream &os, const Tile &t);
    virtual void enter(Player *player) = 0;
    virtual void leave(Player *player) = 0;
protected:
    std::string name;
    std::shared_ptr<Tile> prev, next;
};

class LotteryTile : public Tile {
public:
    explicit LotteryTile(const std::string &tileName) : Tile(tileName) {}
    void enter(Player *player) override;
    void leave(Player *player) override;
};

class HotelTile : public Tile {
public:
    explicit HotelTile(const std::string &tileName) : Tile(tileName) {}
    void enter(Player *player) override;
    void leave(Player *player) override;
};

class GhettoTile : public Tile {
public:
    explicit GhettoTile(const std::string &tileName) : Tile(tileName) {}
    void enter(Player *player) override;
    void leave(Player *player) override;
};

class ResetTile : public Tile {
public:
    explicit ResetTile(const std::string &tileName) : Tile(tileName) {}
    void enter(Player *player) override;
    void leave(Player *player) override;
};

#endif //PRAX12_TILE_H

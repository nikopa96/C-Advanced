#ifndef PRAX12_PLAYER_H
#define PRAX12_PLAYER_H

#include <string>
#include "Tile.h"

class Player {
public:
    Player(const std::string &playerName, std::shared_ptr<Tile> &&tile);

    size_t getVitality();
    size_t getMaxVitality();
    void increaseVitality();
    void increaseMaxVitality();

    size_t getCardsByName(std::string cardName);
    std::shared_ptr<const Card> getCardByName(std::string cardName);
    std::vector<Card> getCards();

    void drop(std::shared_ptr<const Card> card);

    void backward();
    void forward();
    void sleep();
    void pickUp();
    void reset();
private:
    constexpr static size_t defaultVitality = 3;
    size_t vitality = defaultVitality;
    size_t maxVitality = defaultVitality;
    std::vector<std::shared_ptr<const Card>> cardStorage;

    std::string name;
    std::shared_ptr<Tile> start;
    std::shared_ptr<Tile> currentTile;
};

#endif //PRAX12_PLAYER_H

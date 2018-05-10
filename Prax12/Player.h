#ifndef PRAX12_PLAYER_H
#define PRAX12_PLAYER_H

#include <string>
#include "Tile.h"

class Player {
    friend class Tile;
    friend class PrizeCard;
    friend class VitalityCard;
    friend class RestlessExplorerCard;
    friend class ZippyCard;
    friend class HypnoticCard;
    friend class DistractCard;
public:
    Player(const std::string &playerName, std::shared_ptr<Tile> &&tile);
    friend std::ostream &operator<< (std::ostream &os, const Player &player);

    void forward();
    void backward();
    void reset();
    void operator()();

    void pickUp();
    void drop(std::shared_ptr<Card> card);
    void randomDrop();
    void sleep();

    size_t getVitality();
    size_t getMaxVitality();
    void increaseVitality();
    void decreaseVitality();
    void increaseMaxVitality();

    size_t getCardsByName(std::string cardName);
    std::shared_ptr<Card> getCardByName(std::string cardName);
    std::vector<std::shared_ptr<Card>> getCards();

    void modifierCardsManager();

protected:
    constexpr static size_t defaultVitality = 3;

    size_t point;
    size_t vitality;
    size_t maxVitality;
    std::vector<std::shared_ptr<Card>> cardStorageForPlayer;

    std::string name;
    std::shared_ptr<Tile> start, current;
};

class FlyingPlayer : public Player {
public:
    FlyingPlayer(const std::string &playerName, std::shared_ptr<Tile> &&tile);
    void pickUp();
};

#endif //PRAX12_PLAYER_H

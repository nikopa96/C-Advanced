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
    friend class DispelCard;
    friend class RewindCard;
public:
    Player(const std::string &playerName, std::shared_ptr<Tile> &&tile);
    friend std::ostream &operator<< (std::ostream &os, const Player &player);
    virtual void forward();
    virtual void backward();
    void reset();
    void operator()();
    virtual void pickUp();
    void drop(std::shared_ptr<Card> card);
    void sleep();
    std::string getName();
    size_t getVitality();
    size_t getMaxVitality();
    size_t getCardsByName(std::string cardName);
    std::shared_ptr<Card> getCardByName(std::string cardName);
    std::vector<std::shared_ptr<Card>> getCards();
    void runCardModifier();
protected:
    constexpr static size_t defaultVitality = 3;

    size_t point = 0;
    size_t vitality;
    size_t maxVitality;
    std::vector<std::shared_ptr<Card>> cardStorageForPlayer;

    std::string name;
    std::shared_ptr<Tile> start, current;
};

class FlyingPlayer : public Player {
public:
    FlyingPlayer(const std::string &playerName, std::shared_ptr<Tile> &&tile);
    void forward() override;
    void backward() override;
    void pickUp() override;
};

#endif //PRAX12_PLAYER_H

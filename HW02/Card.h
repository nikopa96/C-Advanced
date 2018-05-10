#ifndef PRAX12_CARD_H
#define PRAX12_CARD_H

#include <string>
#include <memory>

class Player;

class Card {
public:
    virtual std::string getCardType() const = 0;
    virtual void onPickedUp(Player &player);
    virtual void onDroped(Player &player);
    void setCardPickedState();
    void setCardDropedState();
protected:
    bool isPicked;
    bool isDroped;
};

class ModifierCard : public Card {

};

class ActionCard : public Card {

};

class PrizeCard : public ModifierCard {
public:
    std::string getCardType() const override;
    void onPickedUp(Player &player) override;
    void onDroped(Player &player) override;
};

class VitalityCard : public ModifierCard {
public:
    std::string getCardType() const override;
    void onPickedUp(Player &player) override;
    void onDroped(Player &player) override;
};


class StickyCard : public ModifierCard {
public:
    std::string getCardType() const override;
};

class DispelCard : public ModifierCard {
public:
    std::string getCardType() const override;
};

class RestlessExplorerCard : public ModifierCard {
public:
    std::string getCardType() const override;
    void onPickedUp(Player &player) override;
    void onDroped(Player &player) override;
};

class DistractCard : public ActionCard {
public:
    std::string getCardType() const override;
};

class RewindCard : public ActionCard {
public:
    std::string getCardType() const override;
};

class ZippyCard : public ActionCard {
public:
    std::string getCardType() const override;
    void onPickedUp(Player &player) override;
    void onDroped(Player &player) override;
};

class HypnoticCard : public ActionCard {
public:
    std::string getCardType() const override;
};

#endif //PRAX12_CARD_H

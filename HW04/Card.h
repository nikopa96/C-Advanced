#ifndef HW02_CARD_H
#define HW02_CARD_H

#include <string>

class Card {
public:
    virtual std::string getCardType() = 0;
    bool onPickedUp();
    bool onDroped();
    void setCardPickedState();
    void setCardDropedState();
protected:
    std::string cardType;
    bool isPicked;
    bool isDroped;
};

class ModifierCard : public Card {
public:
    std::string getCardType() override;
};

class ActionCard : public Card {
    std::string getCardType() override;
};

class PrizeCard : public ModifierCard {
private:
    std::string cardType = "PrizeCard";
};

class VitalityCard : public ModifierCard {
private:
    std::string cardType = "VitalityCard";
};

class StickyCard : public ModifierCard {
private:
    std::string cardType = "StickyCard";
};

class DispelCard : public ModifierCard {
private:
    std::string cardType = "DispelCard";
};

class RestlessExplorerCard : public ModifierCard {
private:
    std::string cardType = "RestlessExplorerCard";
};

class DistractCard : public ActionCard {
private:
    std::string cardType = "DistractCard";
};

class RewindCard : public ActionCard {
private:
    std::string cardType = "RewindCard";
};

class ZippyCard : public ActionCard {
    std::string cardType = "ZippyCard";
};

class HypnoticCard : public ActionCard {
    std::string cardType = "HypnoticCard";
};


#endif //HW02_CARD_H

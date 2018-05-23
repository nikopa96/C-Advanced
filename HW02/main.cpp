#include <iostream>
#include <thread>
#include <vector>
#include "Board.h"
#include "Player.h"

int main() {

    Board b;
    auto t1 = std::make_shared<Tile>("Narrow path");
    auto t2 = std::make_shared<Tile>("Old tree");
    auto t3 = std::make_shared<Tile>("Rabbit hole");
    auto t4 = std::make_shared<Tile>("Bottom of rabbit hole");
    auto t5 = std::make_shared<Tile>("Wonderland woods");
    std::shared_ptr<Tile> exit = std::make_shared<ExitWonderlandTile>();
    b.append(t1).append(t2).append(t3).append(t4).append(t5).append(exit);

    std::unique_ptr<Player> alice;

    try {
        alice = std::make_unique<Player>("Alice", b.getStartTile());
        alice->backward();  // this should throw an exception
    } catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }

    // this code should throw an exception as well, as
    // Alice should be unable to move after she reaches tile "Bottom of the rabbit hole".
    try {
        std::cout << std::endl << std::endl;
        std::cout << "---- TEST 1 ----" << std::endl;
        alice = std::make_unique<Player>("Alice", b.getStartTile());
        alice->forward();
        alice->forward();
        alice->forward();
        alice->forward();
    } catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }

    // this code should throw an exception as well, as
    // Alice does not meet the requirements to exit the Wonderland.
    try {
        std::cout << std::endl << std::endl;
        std::cout << "---- TEST 2 ----" << std::endl;
        alice = std::make_unique<Player>("Alice", b.getStartTile());
        alice->forward();
        alice->forward();
        alice->forward();
        alice->sleep();
        alice->forward();
        alice->forward();
    } catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }

    // Now Alice should be able to move over all the map of Wonderland.
    try {
        std::cout << std::endl << std::endl;
        std::cout << "---- TEST 3 ----" << std::endl;
        alice = std::make_unique<Player>("Alice", b.getStartTile());
        alice->forward();
        alice->forward();
        alice->forward();
        alice->sleep();
        alice->forward();
        alice->backward();
        alice->backward();
        alice->sleep();
        alice->backward();
        alice->backward();
    } catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }

    // it should be impossible to create instances of Card, ModifierCard, ActionCard
    // Card c;
    // ModifierCard c;
    // ActionCard c;

    // this code should throw an exception as tile t1 has only 2 prize cards
    // and Alice cannot pick up 3 of them. The same should happen if Alice
    // tries to pick up a card on an empty tile that has no cards.
    try {
        std::cout << std::endl << std::endl;
        std::cout << "---- TEST 4 ----" << std::endl;
        std::shared_ptr<Card> pc = std::make_shared<PrizeCard>();
        t1->addCard(pc);
        t1->addCard(pc);
        alice = std::make_unique<Player>("Alice", b.getStartTile());
        alice->pickUp();
        alice->pickUp();
        alice->forward();
        alice->pickUp();
    } catch ( const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // this code should throw an exception as alice tries to pick up more than 5 cards
    try {
        std::cout << std::endl << std::endl;
        std::cout << "---- TEST 5 ----" << std::endl;
        std::shared_ptr<Card> pc = std::make_shared<PrizeCard>();
        t1->addCard(pc); t1->addCard(pc); t1->addCard(pc);
        t1->addCard(pc); t1->addCard(pc); t1->addCard(pc);
        alice = std::make_unique<Player>("Alice", b.getStartTile());
        alice->pickUp();
        alice->pickUp();
        alice->pickUp();
        alice->pickUp();
        alice->pickUp();
        alice->pickUp();
    } catch ( const std::exception &e) {
        std::cout << e.what() << std::endl;
        t1->reset();  // delete all cards
    }

    // this code should throw an exception, as Alice does not have a nonexistent card
    try {
        std::cout << std::endl << std::endl;
        std::cout << "---- TEST 6 ----" << std::endl;
        alice = std::make_unique<Player>("Alice", b.getStartTile());
        std::shared_ptr<Card> pnonexistent = std::make_shared<PrizeCard>();
        alice->drop(pnonexistent);
    } catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }

    // vitality card affects the vitality and maxVitality values.
    try {
        std::cout << std::endl << std::endl;
        std::cout << "---- TEST 7 ----" << std::endl;
        alice = std::make_unique<Player>("Alice", b.getStartTile());
        std::shared_ptr<Card> vc = std::make_shared<VitalityCard>();
        t2->addCard(vc);
        alice->forward();
        std::cout << alice->getVitality() << std::endl;         // returns 2
        std::cout << alice->getMaxVitality() << std::endl;      // returns 3
        alice->pickUp();                                        // vitality card
        std::cout << alice->getVitality() << std::endl;         // returns 3
        std::cout << alice->getMaxVitality() << std::endl;      // returns 4
        alice->drop(alice->getCardByName("VitalityCard"));
        std::cout << alice->getVitality() << std::endl;         // returns 3
        std::cout << alice->getMaxVitality() << std::endl;      // returns 3
    } catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }

    // cannot drop a sticky card
    try {
        std::cout << std::endl << std::endl;
        std::cout << "---- TEST 8 ----" << std::endl;
        alice = std::make_unique<Player>("Alice", b.getStartTile());
        std::shared_ptr<Card> sc = std::make_shared<StickyCard>();
        t3->addCard(sc);
        alice->forward();
        alice->forward();
        alice->pickUp();
        alice->drop(alice->getCardByName("sticky"));
    } catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }

    // can enter the ExitWonderlandTile only having the Dispel card
    try {
        std::cout << std::endl << std::endl;
        std::cout << "---- TEST 9 ----" << std::endl;
        alice = std::make_unique<Player>("Alice", b.getStartTile());
        std::shared_ptr<Card> dc = std::make_shared<DispelCard>();
        t4->addCard(dc);
        alice->forward();
        alice->forward();
        alice->forward();
        alice->pickUp();

        auto dispelCard = std::dynamic_pointer_cast<DispelCard>(dc);
        dispelCard->activateForPlayer(*alice);                      //DispelCard on Alice storage, but must be activated

        alice->sleep();
        alice->forward();
        alice->forward();
    } catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }

    // restless explorer card allows Alice to travel without getting tired
    // the following code should not throw an exception
    try {
        std::cout << std::endl << std::endl;
        std::cout << "---- TEST 10 ----" << std::endl;
        alice = std::make_unique<Player>("Alice", b.getStartTile());
        std::shared_ptr<Card> rec = std::make_shared<RestlessExplorerCard>();
        std::shared_ptr<Card> dc = std::make_shared<DispelCard>();
        t1->addCard(rec);
        t1->addCard(dc);
        alice->pickUp();  // restless explorer card
        alice->pickUp();  // dispel card
        alice->forward();
        alice->forward();
        alice->forward();
        alice->forward();
        alice->forward();
    } catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }

    // the distract card drops any other card randomly
    try {
        std::cout << std::endl << std::endl;
        std::cout << "---- TEST 11 ----" << std::endl;
        alice = std::make_unique<Player>("Alice", b.getStartTile());
        std::shared_ptr<Card> p1 = std::make_shared<PrizeCard>();
        std::shared_ptr<Card> p2 = std::make_shared<PrizeCard>();
        std::shared_ptr<Card> p3 = std::make_shared<PrizeCard>();
        std::shared_ptr<Card> dc = std::make_shared<DistractCard>();
        t1->addCard(p1);
        t1->addCard(p2);
        t1->addCard(p3);
        t1->addCard(dc);
        alice->pickUp();   // prize card
        alice->pickUp();   // prize card
        alice->pickUp();   // prize card

        std::vector<std::shared_ptr<Card>> playerCardStorage1 = alice->getCards(); // 3 cards
        for (int i = 0; i < playerCardStorage1.size(); i++) {
            std::cout << playerCardStorage1[i]->getCardType() << " (" << playerCardStorage1[i] << ") " << std::endl;
        }

//        alice->getCards(); // 3 cards
        alice->pickUp();   // distract card
//        alice->getCards(); // 2 cards

        std::vector<std::shared_ptr<Card>> playerCardStorage2 = alice->getCards(); // 3 cards
        for (int i = 0; i < playerCardStorage2.size(); i++) {
            std::cout << playerCardStorage2[i]->getCardType() << " (" << playerCardStorage2[i] << ") " << std::endl;
        }

    } catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }

    // the rewind card puts a player back at the start tile
    try {
        std::cout << std::endl << std::endl;
        std::cout << "---- TEST 12 ----" << std::endl;
        alice = std::make_unique<Player>("Alice", b.getStartTile());
        std::shared_ptr<Card> rc = std::make_shared<RewindCard>();
        t5->addCard(rc);
        alice->forward();
        alice->forward();
        alice->forward();
        alice->sleep();
        alice->forward();
        alice->pickUp();
        // alice should be in "Narrow Path" tile now, and has 0 cards

        std::vector<std::shared_ptr<Card>> playerCardStorage = alice->getCards(); // should return an empty container
        for (int i = 0; i < playerCardStorage.size(); i++) {
            std::cout << playerCardStorage[i]->getCardType() << " (" << playerCardStorage[i] << ") " << std::endl;
        }

//        alice->getCards();  // should return an empty container
        alice->backward();  // should throw an exception
    } catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }

    // the zippy card increases the vitality value by 1
    try {
        std::cout << std::endl << std::endl;
        std::cout << "---- TEST 13 ----" << std::endl;
        alice = std::make_unique<Player>("Alice", b.getStartTile());
        std::shared_ptr<Card> zc = std::make_shared<ZippyCard>();
        t1->addCard(zc);
        alice->pickUp();                                                           // zippy card
        std::cout << alice->getVitality() << std::endl;                            // should return 4
        std::cout << alice->getMaxVitality() << std::endl;                         // should return 3

        std::vector<std::shared_ptr<Card>> playerCardStorage = alice->getCards();  // should return an empty container
        for (int i = 0; i < playerCardStorage.size(); i++) {
            std::cout << playerCardStorage[i]->getCardType() << " (" << playerCardStorage[i] << ") " << std::endl;
        }

//        alice->getCards();       // should return an empty container
    } catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }

    // the hypnotic card takes away all the vitality
    try {
        std::cout << std::endl << std::endl;
        std::cout << "---- TEST 14 ----" << std::endl;
        alice = std::make_unique<Player>("Alice", b.getStartTile());
        std::shared_ptr<Card> hc = std::make_shared<HypnoticCard>();
        t1->addCard(hc);
        alice->pickUp();         // hypnotic card
        std::cout << alice->getVitality() << std::endl;    // should return 0
        std::cout << alice->getMaxVitality() << std::endl; // should return 3

        std::vector<std::shared_ptr<Card>> playerCardStorage = alice->getCards();  // should return an empty container
        for (int i = 0; i < playerCardStorage.size(); i++) {
            std::cout << playerCardStorage[i]->getCardType() << " (" << playerCardStorage[i] << ") " << std::endl;
        }

//        alice->getCards();       // should return an empty container
    } catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }

    // a flying player can have up to 3 cards
    try {
        std::cout << std::endl << std::endl;
        std::cout << "---- TEST 15 ----" << std::endl;
        std::unique_ptr<FlyingPlayer> bob = std::make_unique<FlyingPlayer>("Bob", b.getStartTile());
        std::shared_ptr<Card> pc = std::make_shared<PrizeCard>();
        t5->addCard(pc); t5->addCard(pc); t5->addCard(pc); t5->addCard(pc);
        bob->forward();   // t2
        bob->forward();   // t3
        bob->forward();   // t4
        bob->forward();   // t5
        bob->pickUp();    // prize card
        bob->pickUp();    // prize card
        bob->pickUp();    // prize card

        std::cout << bob->getCardsByName("PrizeCard") << std::endl;
        std::cout << bob->getCardByName("PrizeCard") << std::endl;

        bob->pickUp();    // exception, bob cannot pick more cards
    } catch ( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
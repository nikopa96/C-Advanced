#include <iostream>
#include <thread>
#include "Room.h"

std::mutex msgmutex;

int main() {

    std::shared_ptr<Room> entrance = std::make_shared<Entrance>("ENTRANCE", 10);
    std::shared_ptr<Room> a1 = std::make_shared<WhiteRoom>("A1 - white", 2);
    std::shared_ptr<Room> a2 = std::make_shared<RedRoom>("A2 - red", 3);
    std::shared_ptr<Room> b1 = std::make_shared<RedRoom>("B1 - red", 3);
    std::shared_ptr<Room> b2 = std::make_shared<WhiteRoom>("B2 - white", 2);

    entrance->addNeighbourRoom(b2);

    b2->addNeighbourRoom(a2);
    b2->addNeighbourRoom(b1);

    a2->addNeighbourRoom(a1);
    a2->addNeighbourRoom(b2);

    a1->addNeighbourRoom(a2);
    a1->addNeighbourRoom(b1);

    b1->addNeighbourRoom(a1);
    b1->addNeighbourRoom(b2);

    std::vector<std::thread> players;

    size_t neutralMoodLevel = 1;
    size_t goodMoodLevel = 2;
    size_t angryMoodLevel = 3;

    std::string goodIdea = "good_idea";
    std::string memeIdea = "meme";

    Warrior alice("Alice", entrance);
    alice.setMoodLevel(neutralMoodLevel);
    alice.setIdea(goodIdea);

    Monster john("John", entrance);
    john.setMoodLevel(neutralMoodLevel);

    Wizard bob("Bob", entrance);
    bob.setMoodLevel(neutralMoodLevel);

    Monster carol("Carol", entrance);
    carol.setMoodLevel(neutralMoodLevel);

    Monster eve("Eve", entrance);
    eve.setMoodLevel(neutralMoodLevel);

    Wizard george("George", entrance);
    george.setMoodLevel(neutralMoodLevel);

    Warrior harry("Harry", entrance);
    harry.setMoodLevel(neutralMoodLevel);

    players.emplace_back(alice);
    players.emplace_back(john);
    players.emplace_back(bob);
    players.emplace_back(carol);
    players.emplace_back(eve);
    players.emplace_back(george);
    players.emplace_back(harry);


    for ( auto &t : players ) {
        if ( t.joinable() ) {
            t.join();
        }
    }

    return 0;
}

#include <iostream>
#include <thread>
#include "Room.h"

std::mutex msgmutex;

int main() {

    auto rp = std::make_shared<Room>("Orange",3);
    auto rp2 = std::make_shared<Room>("Green",2);
    rp->setNext(rp2);

    std::vector<std::thread> players;
    for ( auto &name : { "Alice","Bob","Carol","Dave","Eve","George","Harry" } ) {
        players.emplace_back(Player(name,rp));
    }

    for ( auto &t : players ) {
        if ( t.joinable() ) {
            t.join();
        }
    }

    return 0;
}
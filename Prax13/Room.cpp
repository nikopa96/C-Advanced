#include <iostream>
#include <algorithm>
#include "Room.h"

extern std::mutex msgmutex;

Room::Room(const std::string &roomName, size_t max) {
    name = roomName;
    maxPlayers = max;
}

void Room::enter(Player &player) {
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk,[this, &player]{
        auto sz = players.size();
        std::lock_guard<std::mutex> ml(msgmutex);
        if ( sz < maxPlayers ) {
            std::cout << player.name << " entered the room "
                      << name << " with " << sz << " players." << std::endl;
            return true;
        } else {
            std::cout << player.name << " is waiting to enter the room "
                      << name << " which already has " << sz << " players." << std::endl;
            return false;
        }
    });

    // here we own the lock and can do whatever we like to the shared resource
    players.push_back(player);
}

void Room::leave(Player &player) {
    {
        std::lock_guard<std::mutex> lk(m);
        auto it = std::find(players.begin(),players.end(),player);
        if ( it == players.end() ) {
            return;
        }

        players.erase(it);
        std::lock_guard<std::mutex> ml(msgmutex);
        std::cout << player.name << " left the room "
                  << name << std::endl;
    }
    cv.notify_all();
}

void Room::setNext(std::shared_ptr<Room> ptr) {
    next = ptr;
}

std::shared_ptr<Room> Room::getNext() {
    return next;
}

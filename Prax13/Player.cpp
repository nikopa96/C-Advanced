#include "Player.h"
#include "Room.h"
#include <thread>
#include <chrono>
#include <iostream>

Player::Player(const std::string &playerName, std::shared_ptr<Room> ptr) {
    name = playerName;
    room = ptr;
}

void Player::operator()() {
    room->enter(*this);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    room->leave(*this);
    auto nextRoom = room->getNext();
    if ( nextRoom ) {
        nextRoom->enter(*this);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        nextRoom->leave(*this);
    }
}

bool operator==(const Player &lhs, const Player &rhs) {
    return lhs.name == rhs.name;
}

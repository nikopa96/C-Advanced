#include <sstream>
#include <thread>
#include <iostream>
#include "Player.h"

Player::Player(const std::string &playerName, std::shared_ptr<Tile> &&tile) {
    name = playerName;
    current = start = std::move(tile);
    coins = 0;
    current->enter(this);
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    return os << player.name;
}

void Player::forward() {
    if ( ! current->next ) {
        std::stringstream ss;
        ss << *current
           << " is the last tile in the sequence, "
           << name << " cannot move forward.";
        throw std::runtime_error(ss.str());
    }

    current->leave(this);
    current = current->next;
    current->enter(this);
}

void Player::backward() {
    if ( ! current->prev ) {
        std::stringstream ss;
        ss << *current
           << " is the first tile in the sequence, "
           << name << " cannot move backward";
        throw std::runtime_error(ss.str());
    }

    current->leave(this);
    current = current->prev;
    current->enter(this);
}

void Player::reset() {
    current->leave(this);
    current = start;
    current->enter(this);
}

void Player::operator()() {
    try {
        for (auto i=0; i<3; i++) {
            forward();
            forward();
            forward();
            reset();
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
        }

    } catch ( const std::exception &e ) {
        std::cerr << e.what() << std::endl;
    }
}

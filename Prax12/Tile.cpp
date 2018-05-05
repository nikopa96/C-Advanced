#include "Tile.h"
#include <iostream>
#include <random>
#include <chrono>
#include <sstream>
#include "Player.h"

Tile::Tile(const std::string &tileName) {
    name = tileName;
}

std::ostream &operator<<(std::ostream &os, const Tile &t) {
    return os << t.name;
}

void LotteryTile::enter(Player *player) {
    std::default_random_engine generator(
        std::chrono::high_resolution_clock::now().time_since_epoch().count()
    );
    std::uniform_int_distribution<int> distribution(20,60);

    // create PRNG out of a random engine and distribution
    auto giveMeMoney = std::bind(distribution,generator);

    auto win = giveMeMoney();
    player->coins += win;

    std::cout << *player << " entered lottery tile " << name
              << " and got " << win << " coins" << std::endl;
}

void LotteryTile::leave(Player *player) {
    std::cout << *player << " left lottery tile " << name << std::endl;
}

void HotelTile::enter(Player *player) {
    if ( player->coins < 12 ) {
        std::stringstream ss;
        ss << *player << " does not have enough coins to pay for accommodation";
        throw std::runtime_error(ss.str());
    }

    player->coins -= 12;
    std::cout << *player << " entered hotel tile " << name
              << " and paid 12 coins" << std::endl;
}

void HotelTile::leave(Player *player) {
    std::cout << *player << " left hotel tile " << name << std::endl;
}

void GhettoTile::enter(Player *player) {
    player->coins /= 2;
    std::cout << *player << " entered a ghetto tile " << name << ", got robbed and lost "
              << player->coins << " coins" << std::endl;
}

void GhettoTile::leave(Player *player) {
    std::cout << *player << " leaves ghetto tile " << name << std::endl;
}

void ResetTile::enter(Player *player) {
    std::cout << *player << " entered reset tile " << name << std::endl;
    player->reset();
}

void ResetTile::leave(Player *player) {
    std::cout << *player << " left reset tile " << name << std::endl;
}



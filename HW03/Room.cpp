#include <iostream>
#include <algorithm>
#include <random>
#include "Room.h"

extern std::mutex msgmutex;

Room::Room(const std::string &roomName, size_t max) {
    name = roomName;
    maxPlayers = max;
}

void Room::enter(Player &player) {
}

void Room::leave(Player &player) {
    {
        std::lock_guard<std::mutex> lk(m);
        auto it = std::find(playersOnCurrentRoom.begin(), playersOnCurrentRoom.end(), &player);

        if (it == playersOnCurrentRoom.end()) {
            return;
        }

        playersOnCurrentRoom.erase(it);

        std::lock_guard<std::mutex> ml(msgmutex);
        std::cout << player.name << " left the room "
                  << name << std::endl;
    }
    cv.notify_all();
}

Room::Room(const std::string &roomName) {
}

void Room::addNeighbourRoom(std::shared_ptr<Room> room) {
    neighboursRooms.push_back(room);
}

std::shared_ptr<Room> Room::getNeighbourRoom() {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> randomNumber(0, neighboursRooms.size() - 1);

    return neighboursRooms[randomNumber(rng)];
}

WhiteRoom::WhiteRoom(const std::string &roomName, size_t max) : Room(roomName, max) {
    name = roomName;
    maxPlayers = max;
}

void WhiteRoom::enter(Player &player) {
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk,[this, &player]{
        auto sz = playersOnCurrentRoom.size();
        std::lock_guard<std::mutex> ml(msgmutex);
        if (sz < maxPlayers) {
            bool additionalConditions = player.checkAdditionalConditions(*this, player, playersOnCurrentRoom);

            if (additionalConditions) {
                std::cout << player.name << " entered the room "
                          << name << " with " << sz << " players. " << "NB! Without " << player.name << std::endl;

                auto playersVector = playersOnCurrentRoom;
                player.doActionWhiteRoom(playersVector);

                return true;
            } else {
                return false;
            }

        } else {
            std::cout << player.name << " is waiting to enter the room "
                      << name << " which already has " << sz << " players." << std::endl;

            if (dynamic_cast<Monster*>(&player)) {
                auto monster = dynamic_cast<Monster*>(&player);
                monster->decreaseMood();
            }

            return false;
        }
    });

    playersOnCurrentRoom.push_back(&player);

}

RedRoom::RedRoom(const std::string &roomName, size_t max) : Room(roomName, max) {
    name = roomName;
    maxPlayers = max;
}

void RedRoom::enter(Player &player) {
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk,[this, &player]{
        auto sz = playersOnCurrentRoom.size();
        std::lock_guard<std::mutex> ml(msgmutex);

        if (sz < maxPlayers) {
            bool additionalConditions = player.checkAdditionalConditions(*this, player, playersOnCurrentRoom);

            if (additionalConditions) {
                std::cout << player.name << " entered the room "
                          << name << " with " << sz << " players. " << "NB! Without " << player.name << std::endl;

                auto playersVector = playersOnCurrentRoom;

                player.doActionRedRoom(sz, playersVector);

                return true;
            } else {
                return false;
            }

        } else {
            std::cout << player.name << " is waiting to enter the room "
                      << name << " which already has " << sz << " players." << std::endl;

            if (dynamic_cast<Monster*>(&player)) {
                auto monster = dynamic_cast<Monster*>(&player);
                monster->decreaseMood();
            }

            return false;
        }
    });

    playersOnCurrentRoom.push_back(&player);
}

Entrance::Entrance(const std::string &roomName, size_t max) : Room(roomName, max) {
    name = roomName;
    maxPlayers = max;
}

void Entrance::enter(Player &player) {
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk,[this, &player]{
        auto sz = playersOnCurrentRoom.size();
        std::lock_guard<std::mutex> ml(msgmutex);
        if (sz < maxPlayers) {
            std::cout << player.name << " entered the room "
                      << name << " with " << sz << " players. " << "NB! Without " << player.name << std::endl;

            player.doActionEntranceRoom();

            return true;
        } else {
            std::cout << player.name << " is waiting to enter the room "
                      << name << " which already has " << sz << " players." << std::endl;
            return false;
        }
    });

    playersOnCurrentRoom.push_back(&player);

}

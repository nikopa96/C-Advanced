#ifndef PRAX13_ROOM_H
#define PRAX13_ROOM_H

#include <condition_variable>
#include <vector>
#include "Player.h"

class Room {
public:
    Room(const std::string &roomName, size_t max);
    void enter(Player &player);
    void leave(Player &player);
    void setNext(std::shared_ptr<Room> ptr);
    std::shared_ptr<Room> getNext();
private:
    std::condition_variable cv;
    std::mutex m;
    std::vector<Player> players;
    std::shared_ptr<Room> next;
    std::string name;
    size_t maxPlayers;
};

#endif //PRAX13_ROOM_H

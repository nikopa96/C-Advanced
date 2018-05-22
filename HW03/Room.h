#ifndef HW03_ROOM_H
#define HW03_ROOM_H

#include <condition_variable>
#include <vector>
#include "Player.h"

class Room {
    friend class Player;
    friend class Warrior;
    friend class Wizard;
    friend class Monster;
public:
    explicit Room(const std::string &roomName);
    Room(const std::string &roomName, size_t max);
    virtual void enter(Player &player);
    void leave(Player &player);

    void addNeighbourRoom(std::shared_ptr<Room> room);
    std::shared_ptr<Room> getNeighbourRoom();

    std::vector<Player*> playersOnCurrentRoom;
protected:
    std::condition_variable cv;
    std::mutex m;
    std::string name;
    size_t maxPlayers;
    std::vector<std::shared_ptr<Room>> neighboursRooms;
};

class WhiteRoom : public Room {
public:
    WhiteRoom(const std::string &roomName, size_t max);
    void enter(Player &player) override;
};

class RedRoom : public Room {
public:
    RedRoom(const std::string &roomName, size_t max);
    void enter(Player &player) override;
};

class Entrance : public Room {
public:
    Entrance(const std::string &roomName, size_t max);
    void enter(Player &player) override;
};


#endif //HW03_ROOM_H

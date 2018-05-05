#ifndef PRAX13_PLAYER_H
#define PRAX13_PLAYER_H

#include <string>
#include <memory>

// forward-declaring class Room
class Room;

class Player {
    friend class Room;
public:
    Player(const std::string &playerName, std::shared_ptr<Room> ptr);
    void operator()();
    friend bool operator== ( const Player &lhs, const Player &rhs );
private:
    std::string name;
    std::shared_ptr<Room> room;
};

#endif //PRAX13_PLAYER_H

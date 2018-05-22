#ifndef HW03_PLAYER_H
#define HW03_PLAYER_H

#include <string>
#include <memory>
#include <vector>

class Room;

class Player {
    friend class Room;
    friend class WhiteRoom;
    friend class RedRoom;
    friend class Entrance;
    friend class Warrior;
    friend class Wizard;
    friend class Monster;
public:
    Player(const std::string &playerName, std::shared_ptr<Room> ptr);
    void operator()();
    friend bool operator== ( const Player &lhs, const Player &rhs );
    virtual std::string getPlayerType();
    virtual void doActionWhiteRoom(std::vector<Player*> &players);
    virtual void doActionRedRoom(unsigned long &sz, std::vector<Player*> &players);
    virtual void doActionEntranceRoom();
    size_t getRandomTime();
    virtual bool checkAdditionalConditions(Room &currentRoom, Player &player, std::vector<Player*> &players);
    void setMoodLevel(size_t newMoodLevel);
    virtual void fightWithMonsterPlayer(Player &randomPlayer, size_t actionTime);
    std::string getMoodLevelAsString();
    void setIdea(const std::string &newIdea);
    std::string getIdea();
protected:
    std::string name;
    std::shared_ptr<Room> initialRoom;
    std::shared_ptr<Room> currentRoom;
    std::shared_ptr<Room> nextRoom;
    size_t vitality = 1;
    size_t moodLevel = 1;
    std::string idea;
};


class Warrior : public Player {
public:
    Warrior(const std::string &playerName, std::shared_ptr<Room> ptr);
    std::string getPlayerType() override;
    void doActionWhiteRoom(std::vector<Player*> &players) override;
    void doActionRedRoom(unsigned long &sz, std::vector<Player*> &players) override;
    void doActionEntranceRoom() override;
    bool checkAdditionalConditions(Room &currentRoom, Player &player, std::vector<Player*> &players) override;
};


class Wizard : public Player {
public:
    Wizard(const std::string &playerName, std::shared_ptr<Room> ptr);
    std::string getPlayerType() override;
    void doActionWhiteRoom(std::vector<Player*> &players) override;
    void doActionRedRoom(unsigned long &sz, std::vector<Player*> &players) override;
    void doActionEntranceRoom() override;
    bool checkAdditionalConditions(Room &currentRoom, Player &player, std::vector<Player*> &players) override;
};


class Monster : public Player {
public:
    Monster(const std::string &playerName, std::shared_ptr<Room> ptr);
    std::string getPlayerType() override;
    void doActionWhiteRoom(std::vector<Player*> &players) override;
    void doActionRedRoom(unsigned long &sz, std::vector<Player*> &players) override;
    void doActionEntranceRoom() override;
    bool checkAdditionalConditions(Room &currentRoom, Player &player, std::vector<Player*> &players) override;
    void fightWithMonsterPlayer(Player &randomPlayer, size_t actionTime) override;
    void decreaseMood();
};

#endif //HW03_PLAYER_H

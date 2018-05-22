#include <chrono>
#include <thread>
#include <iostream>
#include <random>
#include <algorithm>
#include "Player.h"
#include "Room.h"

Player::Player(const std::string &playerName, std::shared_ptr<Room> ptr) {
    name = playerName;
    initialRoom = ptr;
}

Wizard::Wizard(const std::string &playerName, std::shared_ptr<Room> ptr) : Player(playerName, ptr) {
    name = playerName;
    initialRoom = ptr;
}

Monster::Monster(const std::string &playerName, std::shared_ptr<Room> ptr) : Player(playerName, ptr) {
    name = playerName;
    initialRoom = ptr;
}

Warrior::Warrior(const std::string &playerName, std::shared_ptr<Room> ptr) : Player(playerName, ptr) {
    name = playerName;
    initialRoom = ptr;
}

void Player::operator()() {
    initialRoom->enter(*this);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    initialRoom->leave(*this);

    currentRoom = initialRoom->getNeighbourRoom();

    while (currentRoom) {
        currentRoom->enter(*this);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        currentRoom->leave(*this);

        currentRoom = nextRoom;
    }
}

bool operator==(const Player &lhs, const Player &rhs) {
    return lhs.name == rhs.name;
}

std::string Player::getPlayerType() {
    return std::string();
}

void Player::doActionWhiteRoom(std::vector<Player*> &players) {

}

void Player::doActionRedRoom(unsigned long &sz, std::vector<Player*> &players) {

}

void Player::doActionEntranceRoom() {

}

size_t Player::getRandomTime() {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> randomNumber(1, 2);

    return randomNumber(rng);
}

bool Player::checkAdditionalConditions(Room &currentRoom, Player &player, std::vector<Player*> &players) {
    return false;
}

void Player::setMoodLevel(size_t newMoodLevel) {
    moodLevel = newMoodLevel;
}

std::string Player::getMoodLevelAsString() {
    const size_t neutral_mood = 1;
    const size_t good_mood = 2;
    const size_t angry_mood = 3;

    switch (moodLevel) {
        case neutral_mood:
            return "neutral";
        case good_mood:
            return "good";
        case angry_mood:
            return "angry";
        default:
            return "undefined";
    }
}

void Player::fightWithMonsterPlayer(Player &monster, size_t actionTime) {
    if (monster.moodLevel == 1 || monster.moodLevel == 2) {
        if (vitality <= monster.vitality) {
            vitality--;
            monster.vitality++;

            std::cout << monster.name << " is stronger than " << name << " / " <<
                      monster.name << " vitality is " << monster.vitality << " " << name <<
                      " vitality is " << vitality << " / " << "Time: " << actionTime <<
                      " / Monster Mode: " << monster.getMoodLevelAsString() << std::endl;

            if (vitality == 0) {
                nextRoom = initialRoom;
                vitality = 1;
            }

        } else if (vitality > monster.vitality) {
            vitality++;
            monster.vitality--;

            std::cout << name << " is stronger than " << monster.name << " / " <<
                      monster.name << " vitality is " << monster.vitality << " " << name <<
                      " vitality is " << vitality << " / " << "Time: " << actionTime <<
                      " / Monster Mode: " << monster.getMoodLevelAsString() << std::endl;;

            if (monster.vitality == 0) {
                monster.nextRoom = monster.initialRoom;
                monster.vitality = 1;
            }

            nextRoom = currentRoom->getNeighbourRoom();
        }
    } else {
        vitality--;
        monster.vitality++;

        std::cout << monster.name << " is stronger than " << name << " / " <<
                  monster.name << " vitality is " << monster.vitality << " " << name <<
                  " vitality is " << vitality << " / " << "Time: " << actionTime <<
                  " / Monster Mode: " << monster.getMoodLevelAsString() << std::endl;

        if (vitality == 0) {
            nextRoom = initialRoom;
            vitality = 1;
        }
    }
}

void Player::setIdea(const std::string &newIdea) {
    idea = newIdea;
}

std::string Player::getIdea() {
    return idea;
}

std::string Warrior::getPlayerType() {
    return "Warrior";
}

void Warrior::doActionWhiteRoom(std::vector<Player*> &players) {
    size_t actionTime = getRandomTime();

    std::cout << name << " (" << getPlayerType() << ") is improving his strength and weapon handling skills" << " " <<
              actionTime << " sec." << std::endl;

    if (moodLevel >= 1 && moodLevel < 2) {
        moodLevel++;
        std::cout << name << " has upgraded his/her mood until: " << getMoodLevelAsString() << std::endl;
    }

    if (!players.empty()) {
        std::mt19937 rng;
        rng.seed(std::random_device()());
        std::uniform_int_distribution<std::mt19937::result_type> randomNumber(0, players.size() - 1);

        Player *anotherPlayer = players[randomNumber(rng)];

        if (anotherPlayer->getIdea().empty() || getIdea().empty()) {
            if (!anotherPlayer->getIdea().empty()) {
                setIdea(anotherPlayer->getIdea());
                std::cout << anotherPlayer->name << " has given an idea to: " << name << ": " << getIdea() << std::endl;
            } else {
                anotherPlayer->setIdea(getIdea());
                std::cout << name << " has given an idea to: " << anotherPlayer->name << ": " << getIdea() << std::endl;
            }

            if (anotherPlayer->getIdea() == "good_idea" && getIdea() == "good_idea") {
                if (anotherPlayer->moodLevel >= 1 && anotherPlayer->moodLevel < 2) {
                    anotherPlayer->moodLevel++;
                    moodLevel++;
                    std::cout << anotherPlayer->name << " has upgraded his/her mood until: " << anotherPlayer->getMoodLevelAsString() << std::endl;
                    std::cout << name << " has upgraded his/her mood until: " << getMoodLevelAsString() << std::endl;
                }
            }
        } else {
            std::cout << name << " has an Idea: " << getIdea() << std::endl;
            std::cout << anotherPlayer->name << " has an Idea: " << anotherPlayer->getIdea() << std::endl;
        }
    }

    std::this_thread::sleep_for(std::chrono::seconds(actionTime));
    nextRoom = currentRoom->getNeighbourRoom();
}

void Warrior::doActionRedRoom(unsigned long &sz, std::vector<Player*> &players) {
    size_t actionTime = getRandomTime();

    if (sz == 0) {
        std::cout << name << " (" << getPlayerType() << ") howls from boredom" << " " << actionTime <<
                  " sec." << std::endl;
        nextRoom = currentRoom->getNeighbourRoom();
    } else {
        const std::string monsterString = "Monster";

        for (int i = 0; i < players.size(); i++) {
            if (players[i]->getPlayerType() == monsterString) {
                Player *monster = players[i];

                switch (moodLevel) {
                    case 1:
                        fightWithMonsterPlayer(*monster, actionTime);
                        break;
                    case 2:
                        vitality++;
                        monster->vitality--;

                        std::cout << name << " is stronger than " << monster->name << " / " <<
                                  monster->name << " vitality is " << monster->vitality << " " << name <<
                                  " vitality is " << vitality << " / " << "Time: " << actionTime <<
                                  " /  Warrior Mood: " << getMoodLevelAsString() << std::endl;;

                        if (monster->vitality == 0) {
                            monster->nextRoom = monster->initialRoom;
                            monster->vitality = 1;
                        }

                        nextRoom = currentRoom->getNeighbourRoom();
                        break;
                    default:
                        break;
                }

                return;
            }
        }

        nextRoom = currentRoom->getNeighbourRoom();
    }
}

void Warrior::doActionEntranceRoom() {
    if (currentRoom) {
        nextRoom = currentRoom->getNeighbourRoom();
    }
}

bool Warrior::checkAdditionalConditions(Room &currentRoom, Player &player, std::vector<Player*> &players) {
    return true;
}

std::string Wizard::getPlayerType() {
    return "Wizard";
}

void Wizard::doActionWhiteRoom(std::vector<Player*> &players) {
    size_t actionTime = getRandomTime();

    if (!players.empty()) {
        std::mt19937 rng;
        rng.seed(std::random_device()());
        std::uniform_int_distribution<std::mt19937::result_type> randomNumber(0, players.size() - 1);

        Player *anotherPlayer = players[randomNumber(rng)];

        if (anotherPlayer->getIdea().empty() || getIdea().empty()) {
            if (!anotherPlayer->getIdea().empty()) {
                setIdea(anotherPlayer->getIdea());
                std::cout << anotherPlayer->name << " has given an idea to: " << name << ": " << getIdea() << std::endl;
            } else {
                anotherPlayer->setIdea(getIdea());
                std::cout << name << " has given an idea to: " << anotherPlayer->name << ": " << getIdea() << std::endl;
            }

            if (anotherPlayer->getIdea() == "good_idea" && getIdea() == "good_idea") {
                if (anotherPlayer->moodLevel >= 1 && anotherPlayer->moodLevel < 2) {
                    anotherPlayer->moodLevel++;
                    moodLevel++;
                    std::cout << anotherPlayer->name << " has upgraded his/her mood until: " << anotherPlayer->getMoodLevelAsString() << std::endl;
                    std::cout << name << " has upgraded his/her mood until: " << getMoodLevelAsString() << std::endl;
                }
            }
        } else {
            std::cout << name << " has an Idea: " << getIdea() << std::endl;
            std::cout << anotherPlayer->name << " has an Idea: " << anotherPlayer->getIdea() << std::endl;
        }
    }

    std::cout << name << " (" << getPlayerType() << ") trains to use magical spells" << " " << actionTime <<
              " sec." << std::endl;
    nextRoom = currentRoom->getNeighbourRoom();
}

void Wizard::doActionRedRoom(unsigned long &sz, std::vector<Player*> &players) {
    size_t actionTime = getRandomTime();

    if (sz == 0) {
        std::cout << name << " (" << getPlayerType() << ") howls from boredom" << " " << actionTime <<
                  " sec." << std::endl;
        nextRoom = currentRoom->getNeighbourRoom();
    } else {
        const std::string monsterString = "Monster";

        for (int i = 0; i < players.size(); i++) {

            if (players[i]->getPlayerType() == "Monster") {
                std::cout << "test" << std::endl;

                Player *monster = players[i];
                fightWithMonsterPlayer(*monster, actionTime);

                return;
            }
        }

        nextRoom = currentRoom->getNeighbourRoom();
    }

}

void Wizard::doActionEntranceRoom() {
    if (currentRoom) {
        nextRoom = currentRoom->getNeighbourRoom();
    }
}

bool Wizard::checkAdditionalConditions(Room &currentRoom, Player &player, std::vector<Player*> &players) {
    size_t vectorSize = players.size();

    size_t numberOfAnotherPlayers = 0;
    size_t numberOfMonsters = 0;

    for (int i = 0; i < vectorSize; i++) {
        if (dynamic_cast<Monster*>(players[i])) {
            numberOfMonsters++;
        } else {
            numberOfAnotherPlayers++;
        }
    }

    if (numberOfAnotherPlayers >= numberOfMonsters) {
        return true;
    } else {
        std::cout << "Room " << currentRoom.name << ", where " << player.name << " (Wizard) wants to enter: " << "Monsters: " << numberOfMonsters <<
                  " Another players: " << numberOfAnotherPlayers << " / " << player.name << " is waiting" << "\t" << std::endl;

        return false;
    }
}

std::string Monster::getPlayerType() {
    return "Monster";
}

void Monster::doActionWhiteRoom(std::vector<Player*> &players) {
    size_t actionTime = getRandomTime();

    for (int i = 0; i < players.size(); i++) {
        if (dynamic_cast<Wizard*>(players[i])) {
            if (moodLevel >= 1 && moodLevel < 3) {
                moodLevel++;
                std::cout << name << " has upgraded his/her mood until: " << getMoodLevelAsString() << std::endl;
                break;
            }
        }
    }

    switch (moodLevel) {
        case 1:
            std::cout << name << " (" << getPlayerType() << ") sleeps, snoring occasionally" << " " << actionTime <<
                      " sec." << " / " << "Mood: " << getMoodLevelAsString() << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(actionTime));
            break;
        case 2:
            std::cout << name << " (" << getPlayerType() << ") sings, snoring occasionally" << " " << actionTime <<
                      " sec." << " / " << "Mood: " << getMoodLevelAsString() << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(actionTime));
            break;
        default:
            break;
    }

    if (!players.empty()) {
        std::mt19937 rng;
        rng.seed(std::random_device()());
        std::uniform_int_distribution<std::mt19937::result_type> randomNumber(0, players.size() - 1);

        Player *anotherPlayer = players[randomNumber(rng)];

        if (anotherPlayer->getIdea().empty() || getIdea().empty()) {
            if (!anotherPlayer->getIdea().empty()) {
                setIdea(anotherPlayer->getIdea());
                std::cout << anotherPlayer->name << " has given an idea to: " << name << ": " << getIdea() << std::endl;
            } else {
                anotherPlayer->setIdea(getIdea());
                std::cout << name << " has given an idea to: " << anotherPlayer->name << ": " << getIdea() << std::endl;
            }

            if (anotherPlayer->getIdea() == "good_idea" && getIdea() == "good_idea") {
                if (anotherPlayer->moodLevel >= 1 && anotherPlayer->moodLevel < 2) {
                    anotherPlayer->moodLevel++;
                    moodLevel++;
                    std::cout << anotherPlayer->name << " has upgraded his/her mood until: " << anotherPlayer->getMoodLevelAsString() << std::endl;
                    std::cout << name << " has upgraded his/her mood until: " << getMoodLevelAsString() << std::endl;
                }
            }
        } else {
            std::cout << name << " has an Idea: " << getIdea() << std::endl;
            std::cout << anotherPlayer->name << " has an Idea: " << anotherPlayer->getIdea() << std::endl;
        }
    }

    nextRoom = currentRoom->getNeighbourRoom();
}

void Monster::doActionRedRoom(unsigned long &sz, std::vector<Player*> &players) {
    size_t actionTime = getRandomTime();

    for (int i = 0; i < players.size(); i++) {
        if (dynamic_cast<Wizard*>(players[i])) {
            if (moodLevel >= 1 && moodLevel < 3) {
                moodLevel++;
                std::cout << name << " has upgraded his/her mood until: " << getMoodLevelAsString() << std::endl;
                break;
            }
        }
    }

    if (sz == 0) {
        switch (moodLevel) {
            case 1:
                std::cout << name << " (" << getPlayerType() << ") sleeps, snoring occasionally" << " " << actionTime <<
                          " sec." << " / " << "Mood: " << getMoodLevelAsString() << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(actionTime));
                break;
            case 2:
                std::cout << name << " (" << getPlayerType() << ") sings, snoring occasionally" << " " << actionTime <<
                          " sec." << " / " << "Mood: " << getMoodLevelAsString() << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(actionTime));
                break;
            default:
                break;
        }
        nextRoom = currentRoom->getNeighbourRoom();
    } else {
        std::mt19937 rng;
        rng.seed(std::random_device()());
        std::uniform_int_distribution<std::mt19937::result_type> randomNumber(0, players.size() - 1);

        Player *randomPlayer = players[randomNumber(rng)];
        fightWithMonsterPlayer(*randomPlayer, actionTime);
    }
}

void Monster::doActionEntranceRoom() {
    if (currentRoom) {
        nextRoom = currentRoom->getNeighbourRoom();
    }
}

bool Monster::checkAdditionalConditions(Room &currentRoom, Player &player, std::vector<Player*> &players) {
    return true;
}

void Monster::fightWithMonsterPlayer(Player &randomPlayer, size_t actionTime) {
    switch (moodLevel) {
        case 1:
            if (vitality < randomPlayer.vitality) {
                vitality--;
                randomPlayer.vitality++;

                std::cout << randomPlayer.name << " is stronger than " << name << " / " <<
                          randomPlayer.name << " vitality is " << randomPlayer.vitality << " " << name <<
                          " vitality is " << vitality << " / " << actionTime << " sec." << std::endl;

                std::this_thread::sleep_for(std::chrono::seconds(actionTime));

                if (vitality == 0) {
                    nextRoom = initialRoom;
                    vitality = 1;
                }

            } else if (vitality >= randomPlayer.vitality) {
                vitality++;
                randomPlayer.vitality--;

                std::cout << name << " is stronger than " << randomPlayer.name << " / " << randomPlayer.name
                          << " vitality is " << randomPlayer.vitality << " " << name <<
                          " vitality is " << vitality << " / " << actionTime << " sec." << std::endl;

                std::this_thread::sleep_for(std::chrono::seconds(actionTime));

                if (randomPlayer.vitality == 0) {
                    randomPlayer.nextRoom = randomPlayer.initialRoom;
                    randomPlayer.vitality = 1;
                }

                nextRoom = currentRoom->getNeighbourRoom();
            }
            break;
        case 2:
            if (dynamic_cast<Monster*>(&randomPlayer)) {
                std::cout << name << " (Monster) sees another Monster - " << randomPlayer.name <<
                          " and does not fight with him, because the Monster has a good mood" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(actionTime));
                nextRoom = currentRoom->getNeighbourRoom();
            } else {
                if (vitality < randomPlayer.vitality) {
                    vitality--;
                    randomPlayer.vitality++;

                    std::cout << randomPlayer.name << " is stronger than " << name << " / " <<
                              randomPlayer.name << " vitality is " << randomPlayer.vitality << " " << name <<
                              " vitality is " << vitality << " / " << actionTime << " sec. " <<  " / Monster Mood: good" << std::endl;

                    std::this_thread::sleep_for(std::chrono::seconds(actionTime));

                    if (vitality == 0) {
                        nextRoom = initialRoom;
                        vitality = 1;
                    }

                } else if (vitality >= randomPlayer.vitality) {
                    vitality++;
                    randomPlayer.vitality--;

                    std::cout << name << " is stronger than " << randomPlayer.name << " / " << randomPlayer.name
                              << " vitality is " << randomPlayer.vitality << " " << name <<
                              " / " << actionTime << " sec. / vitality is " << vitality << std::endl;

                    std::this_thread::sleep_for(std::chrono::seconds(actionTime));

                    if (randomPlayer.vitality == 0) {
                        randomPlayer.nextRoom = randomPlayer.initialRoom;
                        randomPlayer.vitality = 1;
                    }

                    nextRoom = currentRoom->getNeighbourRoom();
                }
            }
            break;
        case 3:
            vitality++;
            randomPlayer.vitality--;

            std::cout << name << " is stronger than " << randomPlayer.name << " / " << randomPlayer.name
                      << " vitality is " << randomPlayer.vitality << " " << name <<
                      " vitality is " << vitality << " / " << actionTime << " sec." << " / Monster Mood: angry" << std::endl;

            std::this_thread::sleep_for(std::chrono::seconds(actionTime));

            if (randomPlayer.vitality == 0) {
                randomPlayer.nextRoom = randomPlayer.initialRoom;
                randomPlayer.vitality = 1;
            }

            nextRoom = currentRoom->getNeighbourRoom();
            break;
        default:
            break;
    }
}

void Monster::decreaseMood() {
    if (moodLevel >= 2 && moodLevel <= 3) {
        moodLevel--;
        std::cout << name << " has decreased his/her mood until: " << getMoodLevelAsString() << std::endl;
    }
}


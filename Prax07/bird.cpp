#include <sstream>
#include <iostream>
#include "bird.h"

size_t Pidgeon::counter = 0;
size_t Penguin::counter = 0;

Bird::Bird(const std::string &birdName, size_t birdId)
        : name(birdName), id(birdId) {

    std::stringstream ss;
    ss << this->name << " ";
    ss << this->id;
    this->displayName = ss.str();

}

void Bird::run() {
    std::cout << this->displayName << " is running" << std::endl;
}

void Bird::makeNoise() {
    std::cout << this->displayName << " is making noise" << std::endl;
}

void Bird::flapWings() {
    std::cout << this->displayName << " is flapping wings" << std::endl;
}

void FlyingBird::fly() {
    std::cout << this->displayName << " is flying" << std::endl;
}

void FlyingBird::doEverything() {
    this->run();
    this->makeNoise();
    this->flapWings();
    this->fly();
}

void SwimmingBird::swim() {
    std::cout << this->displayName << " is swimming" << std::endl;
}

void SwimmingBird::doEverything() {
    this->run();
    this->makeNoise();
    this->flapWings();
    this->swim();
}

Bird *BirdFactory::makeBird(BirdType type) {

    switch ( type ) {

        case t_PIDGEON:
            return new Pidgeon;

        case t_PENGUIN:
            return new Penguin;

        default:
            throw std::string("Invalid bird type");
    }

}

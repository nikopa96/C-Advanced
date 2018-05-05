#include <iostream>
#include <vector>
#include "bird.h"

int main() {

    // cannot instantiate Bird
    // Bird b("bird",0);

    std::vector<Bird*> flock;

    try {
        flock.push_back(BirdFactory::makeBird(t_PIDGEON));
        flock.push_back(BirdFactory::makeBird(t_PIDGEON));
        flock.push_back(BirdFactory::makeBird(t_PENGUIN));
        flock.push_back(BirdFactory::makeBird(t_PENGUIN));
        Bird *b = BirdFactory::makeBird(t_DUCK);
    } catch ( const std::string &e ) {
        std::cerr << "Exception: " << e << std::endl;
    }

    for ( auto *bird : flock ) {
        bird->doEverything();
        std::cout << std::endl;
    }

    return 0;
}
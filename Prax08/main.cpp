#include <iostream>
#include "playgound.h"
#include "bird.h"
#include <vector>

int main() {

    //E e(0);

    std::vector<Bird*> flock;

    try {
        flock.push_back(BirdFactory::makeBird(t_PIDGEON));
        flock.push_back(BirdFactory::makeBird(t_PENGUIN));
        flock.push_back(BirdFactory::makeBird(t_DUCK));
        flock.push_back(BirdFactory::makeBird(t_DUCK));
        flock.push_back(BirdFactory::makeBird(t_OSTRICH));
    } catch (const std::string &e) {
        std::cerr << "[EXCEPTION]: " << e << std::endl;
    }

    std::cout << "A flock has " << flock.size() << " birds" << std::endl;

    for ( auto i=0; i<flock.size(); i++ ) {
        flock[i]->doEverything();
        //flock.at(i)->doEverything();
    }

    for ( auto it = flock.begin(); it != flock.end(); it++ ) {
        //Bird *bptr = *it;
        //bptr->doEverything();
        (*it)->doEverything();
    }

    for ( auto bird : flock ) {
        bird->doEverything();
    }

    return 0;
}
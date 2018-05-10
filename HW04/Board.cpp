#include <iostream>
#include "Board.h"

std::shared_ptr<Tile> Board::getStartTile() {
    if (!start) {
        throw std::runtime_error("A board has no start tile");
    }

    return start;
}

Board &Board::append(std::shared_ptr<Tile> &tile) {
    if (!start) {
        last = start = std::move(tile);
    } else {
        last->next = std::move(tile);
        last->next->prev = last;
        last = last->next;
    }

    std::cout << last << std::endl;

    return *this;
}

Board &Board::append(std::shared_ptr<ExitWonderlandTile> &tile) {
    if ( ! start ) {
        last = start = std::move(tile);
    } else {
        last->next = std::move(tile);
        last->next->prev = last;
        last = last->next;
    }

    std::cout << last << std::endl;
    return *this;
}

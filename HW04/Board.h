#ifndef PRAX12_BOARD_H
#define PRAX12_BOARD_H

#include "Tile.h"

class Board {
public:
    Board() = default;
    std::shared_ptr<Tile> getStartTile();
    Board &append(std::shared_ptr<Tile> &tile);
    Board &append(std::shared_ptr<ExitWonderlandTile> &tile);
private:
    std::shared_ptr<Tile> start;
    std::shared_ptr<Tile> last;
};

#endif //PRAX12_BOARD_H

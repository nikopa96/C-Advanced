#include <iostream>
#include <thread>
#include <vector>
#include "Board.h"
#include "Player.h"


// Player(const std::string &s, std::shared_ptr<Tile> &tile);   LVALUE REFERENCE TILE
// auto startTile = b.getStartTile();
// Player p("Peeter", startTile);

// Player(const std::string &s, std::shared_ptr<Tile> &&tile);   RVALUE REFERENCE TILE
// Player p("Peeter", b.getStartTile());

int main() {

    Board b;
    b.append(std::make_shared<LotteryTile>("A"))
     .append(std::make_shared<HotelTile>("B"))
     .append(std::make_shared<GhettoTile>("C"))
     .append(std::make_shared<ResetTile>("D"));

    std::vector<std::thread> players;
    for ( auto &s : { "Alice", "Bob", "Carol", "Eve", "David", "Peter" } ) {
        players.emplace_back(Player(s,b.getStartTile()));
    }

    for ( auto &t : players ) {
        if (t.joinable()) {
            t.join();
        }
    }

    return 0;
}
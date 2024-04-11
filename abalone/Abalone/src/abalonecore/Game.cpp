#include "Game.h"
#include <iostream>

using namespace aba;

Game::Game() {
    status_ = IN_PROGRESS;
    initMarbles();
}

inline const std::vector<Marble> Game::marbles() const {
    return marbles_;
}

inline GameStatus Game::status() const {
    return status_;
}

inline Player Game::currentPlayer() {
    return currentPlayer_;
}

Player Game::winner() {
    return PLAYER_1;
}

bool Game::isOver() {
    return true;
}

bool Game::onBoard(Position pos) {
    return pos.x() >= -4
            && pos.x() <= 4
            && pos.y() >= -4
            && pos.y() <= 4
            && pos.z() >= -4
            && pos.z() <= 4;
}
void Game::initMarbles() {
    Direction d = Direction::RIGHT;
    Player player = PLAYER_1;
    Position pos = Position(-4, 4, 0);
    int nbHexa = 61; //number of hexagons on the board
    for(int i = 0; i < nbHexa; i++) {
        if(i == 17) {
            player = PLAYER_2;
        }
        if(pos.y() >= 3
                || pos.y() <= -3
                || (pos.y() == -2 && (pos.x() >= 0 && pos.x() <= 2))
                || (pos.y() == 2 && (pos.x() >= -2 && pos.x() <= 0)) ) {
            marbles_.push_back(Marble(pos, player));
        }

        if(!onBoard(pos.nextPos(d))) {
            if(d == Direction::RIGHT) {
                d = Direction::LEFT;
                if(pos.y() > 0) {
                    pos.moveTo(Direction::RIGHT_DOWN);
                }else {
                    pos.moveTo(Direction::LEFT_DOWN);
                }
            }else {
                d = Direction::RIGHT;
                if(pos.y() > 0) {
                    pos.moveTo(Direction::LEFT_DOWN);
                } else {
                    pos.moveTo(Direction::RIGHT_DOWN);
                }
            }
        } else {
            pos.moveTo(d);
        }
    }
}

void Game::move(Position tomove, Position first, Position last) {
    tomove.moveTo(first.getDirection(last, first));
}



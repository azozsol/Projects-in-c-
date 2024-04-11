#include "Position.h"

Position::Position(int x, int y, int z) :
    x_{x}, y_{y}, z_{z}
{}

Position::Position(const Position &position) :
    x_{position.x()}, y_{position.y()}, z_{position.z()}
{}



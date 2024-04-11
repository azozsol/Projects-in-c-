#ifndef POSITION_H
#define POSITION_H

#include <math.h>
#include <string>
#include "Direction.h"

/**
 * @brief Position of a single marble on the board.
 */
class Position {
private :
    int x_, y_, z_;

public:

    /**
     * @brief Constructor of a Position
     * @param x axe x
     * @param y axe y
     * @param z axe z
     */
    Position(int x, int y, int z);

    /**
     * @brief Copy constructor of a Position
     * @param x axe x
     * @param y axe y
     * @param z axe z
     */
    Position(const Position &position);

    /**
     * @brief Getter of x.
     * @return an int
     */
    inline int x() const;

    /**
     * @brief Getter of y.
     * @return an int
     */
    inline int y() const;

    /**
     * @brief Getter of z.
     * @return an int
     */
    inline int z() const;

    /**
     * @brief Checks if two positions are equals.
     * @param a a position
     * @param b the position to compare to
     * @return true if they are equals, false otherwise
     */
    inline bool equals(Position a, Position b);

    /**
     * @brief Move a position in a given Direction.
     * @param d a given Direction
     */
    inline void moveTo(Direction d);

    /**
     * @brief Gives the next position to the current one.
     * @return a Position
     */
    inline Position nextPos(Direction d);

    /**
     * @brief Gets the direction of a movement between 2 positions.
     * @param start
     * @param end
     * @return
     */
    inline Direction getDirection(Position start, Position end);

    /**
     * @brief Gets the distance between to positions.
     * @param first the first position
     * @param second the second position
     * @return an integer
     */
    inline int distance(Position first, Position second);

    /**
     * @brief The to string method of Position.
     * @return a String.
     */
    inline std::string toString();
};

inline int Position::x() const {
    return x_;
}

inline int Position::y() const {
    return y_;
}

inline int Position::z() const {
    return z_;
}

inline bool Position::equals(Position a, Position b) {
    return a.x() == b.x()
            && a.y() == b.y()
            && a.z() == b.z();
}

inline void Position::moveTo(Direction d) {
    auto movement = Movement(d);
    x_ += movement.deltaX();
    y_ += movement.deltaY();
    z_ += movement.deltaZ();
}

inline Position Position::nextPos(Direction d) {
    Position next = Position(x_, y_, z_);
    next.moveTo(d);
    return next;
}

inline Direction Position::getDirection(Position start, Position end) {
    for(int i = 0; i < 6; i++) {
        auto d = Direction(i);
        auto next = start.nextPos(d);
        if(Position::equals(next, end)) {
            return d;
        }
    }
    return Direction::RIGHT;
}

inline int Position::distance(Position first, Position second) {
    return std::sqrt( (first.x() - second.x()) * (first.x() - second.x())
                      + (first.y() - second.y()) * (first.y() - second.y())
                      + (first.z() - second.z()) * (first.z() - second.z()) );
}

inline std::string Position::toString() {
    return std::to_string(x_) + ", " + std::to_string(y_) + ", " + std::to_string(z_);
}

#endif // POSITION_H

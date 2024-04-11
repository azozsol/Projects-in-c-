#ifndef MARBLE_H
#define MARBLE_H

#include <string>
#include "Position.h"
#include "Player.h"

/**
 * @brief The marble to play with.
 */
class Marble {

private:
    Position position_;
    Player player_;

public:

    /**
     * @brief Constructor of Marble
     * @param pos a given position
     * @param pl the marble's owner
     */
    Marble(Position position, Player player);

    /**
     * @brief Getter of player
     * @return a Player
     */
    inline Player player() const;

    /**
     * @brief Getter of position
     * @return a Position
     */
    inline Position position() const;

    /**
     * @brief Calls the Position method to move the marble's position.
     * @param d a given Direction
     */
    inline void moveTo(Direction d);

    /**
     * @brief The to string method of Marble.
     * @return a String.
     */
    inline std::string toString();
};

inline Player Marble::player() const {
    return player_;
}

inline Position Marble::position() const {
    return position_;
}

inline void Marble::moveTo(Direction d) {
    position_.moveTo(d);
}

inline std::string Marble::toString() {
    std::string p;
    if(player_ == PLAYER_1) {
        p = " [PLAYER_1]";
    }else {
        p = " [PLAYER_2]";
    }
    return position_.toString() + p;
}

#endif // MARBLE_H

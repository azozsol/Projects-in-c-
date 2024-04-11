#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "Player.h"
#include "Position.h"
#include "Marble.h"

namespace aba {

/**
 * @brief Interface of the game, contains the mandatory functions to run a game
 *        between to players.
 */
class Model {

    /**
     * @brief moves a player's marble.
     */
    virtual void move(Position tomove,
                      Position first,
                      Position last = Position(-5, -5, -5)
                      ) = 0;

    /**
     * @brief Checks if the game is over.
     * @return true if it'd over, false otherwise.
     */
    virtual bool isOver() = 0;

    /**
     * @brief Checks who is the winner.
     * @return A Player
     */
    virtual Player winner() = 0;

    /**
     * @brief Indicates who is the current player
     * @return the current player
     */
    virtual Player currentPlayer() = 0;

    /**
     * @brief Gives the marbles of the game
     * @return a vector of Marbles
     */
    virtual const std::vector<Marble> marbles() const = 0;
};

}
#endif // MODEL_H

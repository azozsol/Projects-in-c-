#ifndef GAME_H
#define GAME_H

#include <string>
#include "Model.h"
#include "GameStatus.h"
#include "Observable.h"

/**
 * @brief The main class of the game.
 */
class Game : public aba::Model,  public Observable{

private:
    std::vector<Marble> marbles_;

    GameStatus status_ = NOT_STARTED;

    Player currentPlayer_ = PLAYER_1;

    /* Initializes the marbles with their positions and Player.
     *
    */
    void initMarbles();

    /**
     * @brief Checks if a position is on the 'board'.
     * @param pos a given position.
     * @return true if the position is on the board, false otherwise.
     */
    bool onBoard(Position pos);

    /**
     * @brief Checks if a position is free or used by a marble.
     * @param pos The position to check
     * @return true if it is free, false otherwise.
     */
    bool isFree(Position pos);

public:

    /**
     * @brief Constructor of Game.
     */
    Game();

    Player winner();

    bool isOver();

    /**
     * @brief Getter if of marbles.
     * @return all marbles of the game
     */
    inline const std::vector<Marble> marbles() const;

    /**
     * @brief Getter of status.
     * @return the current status of the game
     */
    inline GameStatus status() const;

    /**
     * @brief Getter of player.
     * @return the current playing player
     */
    inline Player currentPlayer();

    /**
     * @brief Moves a marble to a given position.
     * @param tomove the position where to move the marble
     * @param first the position of the marble to move
     * @param last if there are multiple marbles to move, the first position
     *             indicates the first marble from them and the second position
     *             indicates the last one.
     */
    void move(Position tomove,
              Position first,
              Position last = Position(-5, -5, -5)
              );
};
#endif // GAME_H

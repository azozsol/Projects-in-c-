#ifndef DIRECTION_H
#define DIRECTION_H

#include <vector>
#include "Position.h"


/**
 * @brief The Direction enum : Directions in which to move the marbles.
 *        The format is x, y, z.
 */
enum class Direction {
    RIGHT = 0,
    LEFT = 1,
    RIGHT_UP = 2,
    RIGHT_DOWN = 3,
    LEFT_UP = 4,
    LEFT_DOWN = 5

};

/**
 * @brief A movement in a direction with its values.
 */
struct Movement {
private:

  int deltaX_;
  int deltaY_;
  int deltaZ_;

public:

  Movement(Direction d) {
      switch (d) {
      case Direction::RIGHT :
          deltaX_ = 1;
          deltaY_ = 0;
          deltaZ_ = -1;
          break;
      case Direction::LEFT :
          deltaX_ = -1;
          deltaY_ = 0;
          deltaZ_ = 1;
          break;
      case Direction::RIGHT_UP :
          deltaX_ = 0;
          deltaY_ = 1;
          deltaZ_ = -1;
          break;
      case Direction::RIGHT_DOWN :
          deltaX_ = 1;
          deltaY_ = -1;
          deltaZ_ = 0;
          break;
      case Direction::LEFT_UP :
          deltaX_ = -1;
          deltaY_ = 1;
          deltaZ_ = 0;
          break;
      case Direction::LEFT_DOWN :
          deltaX_ = 0;
          deltaY_ = -1;
          deltaZ_ = 1;
          break;
      }
  }
  inline int deltaX() const {
      return deltaX_;
  }

  inline int deltaY() const {
      return deltaY_;
  }

  inline int deltaZ () const {
      return deltaZ_;
  }
};

#endif // DIRECTION_H

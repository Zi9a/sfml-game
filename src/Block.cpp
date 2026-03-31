#include "Block.h"
#include <SFML/System/Vector2.hpp>

void Block::bounceInside(const sf::Vector2f &windowSize) {
  position = rectangle.getPosition();
  rectangleDimension = rectangle.getSize();

  if (position.x + rectangleDimension.x > windowSize.x) {
    velocity.x = -velocity.x;
  }
  if (position.y + rectangleDimension.y > windowSize.y) {
    velocity.y = -velocity.y;
  }
  if (position.x < 0.f) {
    velocity.x = -velocity.x;
  }
  if (position.y < 0.f) {
    velocity.y = -velocity.y;
  }
}

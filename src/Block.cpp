#include "Block.h"
#include "configuration.h"
#include <SFML/System/Vector2.hpp>


void Block::boundsCheck(sf::RenderWindow& window) {
  float circleRadius{circle.getRadius()};
  circlePosition = circle.getPosition();
  sf::Vector2f windowBounds{window.getSize()};

  // right
  if (circlePosition.x + circleRadius * 2 > windowBounds.x) {
    circlePosition.x = windowBounds.x - circleRadius * 2;
    circleVelocity.x = -circleVelocity.x;
  }
  // down
  if (circlePosition.y + circleRadius * 2 > windowBounds.y) {
    circlePosition.y = windowBounds.y - circleRadius * 2;
    circleVelocity.y = -circleVelocity.y;
  }

  // left
  if(circlePosition.x < 0) {
    circleVelocity.x = -circleVelocity.x;
  }

  // up
  if(circlePosition.y < 0) {
    circleVelocity.y = -circleVelocity.y;
  }

  circle.setPosition(circlePosition);
}

void Block::move() {
  circleVelocity.y += conf::gravityConstant * conf::deltaTime;
  circleVelocity.x *= 0.999;
  circleVelocity.y *= 0.999;

  sf::Vector2f nextPosition = {
    circleVelocity.x * conf::deltaTime,
    circleVelocity.y * conf::deltaTime
  };

  circle.move(nextPosition);
}

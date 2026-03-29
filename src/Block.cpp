#include "Block.h"
#include "configuration.h"

void Block::bounceInside() {
  auto rectangleDimension{rectangle.getSize()};

  if (position.x + rectangleDimension.x > conf::windowSize.x) {
    velocity_x = -velocity_x;
  }
  if (position.y + rectangleDimension.y > conf::windowSize.y) {
    velocity_y = -velocity_y;
  }

  if (position.x < 0.f) {
    velocity_x = -velocity_x;
  }
  if (position.y < 0.f) {
    velocity_y = -velocity_y;
  }
}

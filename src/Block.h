#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

class Block {
public:
  sf::RectangleShape rectangle{};
  float dt{1};

  float velocity_x{1};
  float velocity_y{1};

  float time{};
  sf::Vector2f position{0, 0};
  void bounceInside();
};

#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

class Block {
public:
  sf::RectangleShape rectangle{};
  sf::Vector2f velocity{200, 200};
  sf::Vector2f position{0, 100};
  sf::Vector2f rectangleDimension{rectangle.getSize()};
  float deltaTime{0.01};
  void bounceInside(const sf::Vector2f &);
};

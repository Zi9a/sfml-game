#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

class Block {
private: 
  sf::CircleShape circle{};
  sf::Vector2f circleVelocity{};
  sf::Vector2f circlePosition{};

public:
  Block() = default;
  Block(float radius, sf::Vector2f velocity, sf::Vector2f position, sf::Color color)
  : circle{radius}
  , circleVelocity{velocity}
  , circlePosition{position}
  {
    circle.setPosition(position);
    circle.setFillColor(color);
  }

  void setBlock(float radius, sf::Vector2f velocity, sf::Vector2f position, sf::Color color) {
    circle.setRadius(radius);
    circleVelocity  = velocity;
    circlePosition = position;
    circle.setPosition(circlePosition);
    circle.setFillColor(color);
  }

  void draw(sf::RenderWindow& window) const {
    window.draw(circle);
  }

  void boundsCheck(sf::RenderWindow&);
  void move();
};

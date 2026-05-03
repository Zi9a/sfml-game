#pragma once
#include "Block.h"
#include "configuration.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

class Game {
private:
  sf::RenderWindow window{};
  Block block{
    conf::radius,
    conf::circleVelocity,
    conf::circlePosition,
    conf::circleColor
  };

public:
  Game();
  ~Game() {};

  void run();
  void initWindow();
  void handleEvent();
  void displayObject();

  void vertex();
};

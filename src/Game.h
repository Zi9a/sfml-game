#pragma once
#include "Block.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

class Game {
private:
  sf::RenderWindow window{};
  Block block{};

public:
  Game();
  ~Game() {};

  void run();
  void initWindow();
  void handleEvent();

  void drawObject();
  void drawObject2();
};

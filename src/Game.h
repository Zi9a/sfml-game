#pragma once
#include "Block.h"
#include "configuration.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

class Game {
private:
  sf::RenderWindow window{};
  std::vector<Block> block{conf::numberOfBalls};

public:
  Game();
  ~Game() {};

  void run();
  void initWindow();
  void handleEvent();
  void displayObject();

  void initBlock();
  void vertex(Block&);
};

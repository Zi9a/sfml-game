#pragma once
#include "Block.h"
#include "configuration.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

class Game {
private:
  sf::RenderWindow window{};
  std::vector<Block> block{conf::numberOfBalls};

  sf::Texture background{};
  sf::Sprite sprite{background};

  sf::Texture ballTexture{};

public:

  Game();
  ~Game() {};

  void run();
  void initWindow();
  void handleEvent();
  void displayObject();

  void initBackground();
  void initBlock();
  void drawBalls(Block&);
};

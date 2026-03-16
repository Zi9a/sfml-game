#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class Game {
private:
  sf::RenderWindow window;

public:
  Game();
  void run();
  void initWindow();
  void handleEvent();
};

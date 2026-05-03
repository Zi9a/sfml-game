#include "Game.h"
#include "Block.h"
#include "configuration.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstddef>

Game::Game()
    : window{sf::RenderWindow(conf::fitToScreen, conf::title,
                              sf::Style::Default)} {}

void Game::run() {
  this->initWindow();

  while (window.isOpen()) {
    this->handleEvent();

    window.clear();
    this->displayObject();
    window.display();
  }
}

void Game::initWindow() {
  this->window.setFramerateLimit(conf::maxFrameRate);
  this->window.setPosition(conf::windowPosition);
}

void Game::handleEvent() {
  while (const std::optional event = window.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      window.close();
    } else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
      if (keyPressed->scancode == sf::Keyboard::Scan::Escape) {
        window.close();
      }
    }
  }
}

void Game::displayObject() {
  block.move();
  block.boundsCheck(window);
  block.draw(window);
}


void Game::vertex() {
}

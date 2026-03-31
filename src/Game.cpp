#include "Game.h"
#include "Block.h"
#include "configuration.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstddef>

Game::Game()
    : window{sf::RenderWindow(conf::fitToScreen, conf::title,
                              sf::Style::Default)} {}

void Game::run() {
  this->initWindow();
  Block block;

  while (window.isOpen()) {
    this->handleEvent();

    window.clear();
    drawObjectCircle();
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

void Game::drawObjectSquare() {
  sf::Vector2f windowSize{window.getSize()};

  block.rectangle.setFillColor(sf::Color::Yellow);
  block.rectangle.setSize({200, 200});
  block.rectangle.move(
      {block.velocity.x * block.deltaTime, block.velocity.y * block.deltaTime});

  block.bounceInside(windowSize);
  window.draw(block.rectangle);
}

void Game::drawObjectCircle() {
  static sf::CircleShape circle{100, 6};

  circle.setOrigin({0, 0});
  float deltaTime{0.05};

  static sf::Vector2f velocity{1000.f, 1000.f / 2};
  sf::Vector2f position{circle.getPosition()};
  float radius{circle.getRadius()};

  if (position.x + 2 * radius > window.getSize().x) {
    velocity.x = -velocity.x;
    circle.setFillColor(sf::Color::Red);
  }

  if (position.y + 2 * radius > window.getSize().y) {
    velocity.y = -velocity.y;
    circle.setFillColor(sf::Color::Green);
  }

  if (position.x < 0.f) {
    velocity.x = -velocity.x;
    circle.setFillColor(sf::Color::Blue);
  }
  if (position.y < 0.f) {
    velocity.y = -velocity.y;
    circle.setFillColor(sf::Color::Cyan);
  }

  circle.move({velocity * deltaTime});
  window.draw(circle);
}

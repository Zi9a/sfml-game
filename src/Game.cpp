#include "Game.h"
#include "Block.h"
#include "configuration.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
#include <algorithm>
#include <cstddef>
#include <iterator>

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
  constexpr int numberOfCircle{100};
  static sf::CircleShape circle[numberOfCircle];
  static sf::Vector2f velocity[numberOfCircle]{};
  static sf::Vector2f position{100, 100};

  static bool once{true};
  if (once) {
    for (int i{}; i < numberOfCircle; ++i) {
      velocity[i] = {1.f, 1.f};
    }
    once = false;
  }

  float radius{2};

  for (int i{0}; i < std::size(circle); ++i) {
    position = circle[i].getPosition();
    circle[i].setRadius(radius);
    circle[i].setRadius(radius);
    circle[i].setFillColor(sf::Color::Red);

    if (position.x + 2 * radius > window.getSize().x) {
      velocity[i].x = -velocity[i].x;
    }
    if (position.y + 2 * radius > window.getSize().y) {
      velocity[i].y = -velocity[i].y;
    }
    if (position.x < 0.f) {
      velocity[i].x = -velocity[i].x;
    }
    if (position.y < 0.f) {
      velocity[i].y = -velocity[i].y;
    }

    float factor{static_cast<float>(i % 1 + i / 100.f)};
    circle[i].move({velocity[i].x * factor, velocity[i].y * factor});
    window.draw(circle[i]);
  }
}

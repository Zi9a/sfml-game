#include "Game.h"
#include "Block.h"
#include "configuration.h"
#include "random.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstddef>
#include <iostream>

Game::Game()
    : window{sf::RenderWindow(conf::fitToScreen, conf::title,
                              sf::Style::Default)} {}

void Game::run() {
  this->initWindow();
  this->initBackground();
  this->initBlock();

  while (window.isOpen()) {
    this->handleEvent();

    window.clear();
    window.draw(sprite);
    for (auto &blocks : block) {
      drawBalls(blocks);
    }
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
  // block.move();
  // block.boundsCheck(window);
  // block.draw(window);
}

void Game::drawBalls(Block& block) {
  block.move();
  block.boundsCheck(window);
  block.draw(window);
}

void Game::initBlock() {
  if (!ballTexture.loadFromFile( "/Users/ziyadhandu/code/sfml-game/res/img/ball-texture.png")) {
    std::cout << "- Failed to load ball-texture Image \n";
    return;
  }
  std::cout << "- ball-texture Image Loaded\n";
  for (auto& blocks : block) {
    sf::Vector2f position{
        static_cast<float>(Random::get(0, window.getSize().x)),
        static_cast<float>(Random::get(0, window.getSize().y / 2))
    };
    blocks.setBlock(
      conf::radius,
      conf::circleVelocity,
                  position,
      conf::circleColor,
      ballTexture
    );
  }
}

void Game::initBackground() {
  if (!background.loadFromFile( "/Users/ziyadhandu/code/sfml-game/res/img/background-brick.png")) {
    std::cout << "- Failed to load Background Image \n";
    return;
  }
  std::cout << "- Background Image Loaded\n";
  background.setRepeated(true);
  sprite.setTexture(background, true);
  sprite.setTextureRect(
      sf::IntRect(
        {0, 0},
        {
          static_cast<int>(window.getSize().x),
          static_cast<int>(window.getSize().y)
        }
      )
  );
}

  void Block::setBlock(float radius, sf::Vector2f velocity, sf::Vector2f position, sf::Color color, const sf::Texture& ballTexture) {
    circle.setRadius(radius);
    circleVelocity  = velocity;
    circlePosition = position;
    circle.setPosition(circlePosition);
    circle.setFillColor(color);
    circle.setTexture(&ballTexture, true);
  }

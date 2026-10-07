#include "Game.h"
#include "Configurations.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/WindowEnums.hpp>

// constructors & destructors
Game::Game() { initWindow(); }

Game::~Game() { delete window; }

/*!
 * Initialize Window
 * Initializes the main Game Window
 * Sets the background Image
 * Sets the background Music
 * plays the background Music
 * */
void Game::initWindow() {
  this->window = new sf::RenderWindow(this->videoMode, "game",
                                      sf::Style::Titlebar | sf::Style::Close |
                                          sf::Style::Resize);
  this->window->setFramerateLimit(60);
  if (!this->m_backgroundTexture.loadFromFile( Config::backgroundTextureFileName )) {
    std::cout << "Backgorund Image Loading Error" << '\n';
  }

  if (!this->m_backgroundMusic.openFromFile("assets/background_music.mp3")) {
    std::cout << "Backgorund Music Loading Error" << '\n';
  }
  m_backgroundMusic.setVolume(10);
  m_backgroundMusic.play(); // FIXME: periodic crackling sound, MacOS
  m_backgroundMusic.setLooping(true);
}

/*!
 * Main Update Function
 * Update the board for the next frame
 * */
void Game::update() {
  pollEvents();

  if (!board.isSolved()) {
    board.moveTile(*window);
  } else {
    board.replay();
  }

  updateMousePosition();
}

/*!
 * Main Render Function
 * Renders The game objects
 * */
void Game::render() {
  window->clear(sf::Color(128, 128,128)); // clears the previous frame
  
  this->m_background.setSize(static_cast<sf::Vector2f>(window->getSize()));
  this->m_background.setTexture(&this->m_backgroundTexture);
  this->window->draw(m_background);

  if (!board.isSolved()) {
    board.displayBoard(*window);
  } else {
    board.displayWinText(*window);
  }

  window->display(); // displays the new frame
}

/*! Event Handelling */
void Game::pollEvents() {
  while (const std::optional event = window->pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      window->close();
    }

    /**
     * Close the window when the escape key is pressed
     * */
    if (const auto *KeyPressed{event->getIf<sf::Event::KeyPressed>()}) {
      if (KeyPressed->code == sf::Keyboard::Key::Escape) {
        window->close();
      }
    }
  }
}

void Game::updateMousePosition() {
  /**
   * @return void
   *  
   * updates the mosue position
   *  - window mouse positon
   *
   * */
  mousePositionWindow = sf::Mouse::getPosition(*window);
  mousePositionView = window->mapPixelToCoords(mousePositionWindow);
}

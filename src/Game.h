#pragma once

#include <SFML/Audio/AudioResource.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Audio/Music.hpp>
#include "Board.h"

///////////////////////////////////////////////////////////////
/// \brief Main Game Object
/// Handles the game objects and operates the window functions
///
///////////////////////////////////////////////////////////////

class Game{
private:
  // window objects
  sf::RenderWindow* window{ nullptr };
  sf::VideoMode videoMode{ sf::VideoMode::getDesktopMode() };

  // background
  sf::RectangleShape m_background{};
  sf::Music m_backgroundMusic{};
  sf::Texture m_backgroundTexture{ "assets/placeholder.jpg" };

  // window mouse position
  sf::Vector2i mousePositionWindow{};
  sf::Vector2f mousePositionView{};

  // Game Board
  Board board{};

  // private functions
  void initWindow();

public:
  // constructors & destructors
  Game();
  ~Game();

  // Getters
  const bool isRunning() const {
    /*! \brief return false if the window is closed */
    return window->isOpen();
  }

  // functions
  void pollEvents();
  void updateMousePosition();
  void update();
  void render();
};

#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include "Point.h"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "Configurations.h"


class Board {
private:
  // Tiles array
  std::array<std::array<Tile, Config::gridSize>, Config::gridSize> tiles{};

  // Win Condition
  sf::Font m_font{};
  sf::Text m_winText{m_font};

  sf::SoundBuffer m_soundBuffer{};
  sf::Sound m_tileSlideSound{m_soundBuffer};

  // private functions
  void initText();
  void initTiles();
  void initAudio();

public:
  Board() {
    initTiles();
    initText();
    shuffle();
    initAudio();
  }

  void shuffle();
  void replay();

  inline static int count_total_steps{};

  void displayBoard(sf::RenderWindow& target);
  void displayWinText(sf::RenderWindow& target);
  void printText(std::string_view text, int size, sf::RenderWindow& target, int yOffset = 0, sf::Color textColor = sf::Color::White);

  friend std::ostream& operator<<(std::ostream&, Board&);

  void moveTile(sf::RenderWindow& target);
  Point locateEmptyTile() const;
  Point getTilePoint(const Tile&) const;
  bool isSolved() const;
};

#endif // !BOARD_H

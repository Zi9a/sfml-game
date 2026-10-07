#include "Board.h"
#include "Configurations.h"
#include "Direction.h"
#include "Point.h"
#include "Tile.h"
#include "random.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <sstream>
#include <string_view>

void Board::initTiles() {
  int tileNumber{1};
  for (int y{0}; y < Config::gridSize; ++y) {
    for (int x{0}; x < Config::gridSize; ++x) {
      this->tiles[y][x].renderTileNumber(tileNumber++);
      this->tiles[y][x].renderTileTexture();
    }
  }
}

void Board::initAudio() {
  if (!this->m_soundBuffer.loadFromFile("assets/tile_slide_sound.mp3")) {
    std::cout << "Sound Loading Error" << '\n';
  }
  this->m_tileSlideSound.setBuffer(this->m_soundBuffer);
}

///////// Boooyah! Baby..... ///////////
void Board::shuffle() {
  Point emptyTilePoint{ locateEmptyTile() };
  for (int i{ 0 }; i < Config::randomizationLevel; ++i) {
    Direction direction{ static_cast<Direction::Type>(Random::get(0, Direction::MaxDirection - 1)) };
    Point adjacentTilePoint{ emptyTilePoint.getAdjacentCell(direction.getType()) };
    if (adjacentTilePoint.pointOutOfBound()) {
      continue;
    }

    Tile& emptyTile{ this->tiles[emptyTilePoint.getX()][emptyTilePoint.getY()] };
    Tile& adjacentTile{ this->tiles[adjacentTilePoint.getX()][adjacentTilePoint.getY()] };
    adjacentTile.move(emptyTile);
    emptyTilePoint = adjacentTilePoint;
  }
}

void Board::displayBoard(sf::RenderWindow &target) {
  const sf::Vector2f size = static_cast<sf::Vector2f>(target.getSize());
  const sf::Vector2f centerOfWindow{size.x / 2.f, size.y / 2.f};
  const sf::Vector2f boardOffset{Config::boardSize.x / 2.f,
                                 Config::boardSize.y / 2.f};

  for (int y{0}; y < Config::gridSize; ++y) {
    for (int x{0}; x < Config::gridSize; ++x) {
      sf::Vector2f position{
          x * Config::tileSize.x + centerOfWindow.x - boardOffset.x,
          y * Config::tileSize.y + centerOfWindow.y - boardOffset.y};
      tiles[y][x].drawTile(target, position);
    }
  }

}

void Board::initText() {
  if (!this->m_font.openFromFile("assets/game_font_2.ttf")) {
    std::cout << "Font Load Error" << '\n';
    return;
  }

  m_winText.setFillColor(sf::Color::White);
  this->m_winText.setFont(this->m_font);
}

void Board::replay() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
    this->shuffle();
    Config::countSteps = 0;
  }
}

void Board::printText(std::string_view text, int size, sf::RenderWindow& target, int yOffset, sf::Color textColor){ //  yOffset = 0
  this->m_winText.setCharacterSize(size);
  this->m_winText.setString(text);
  this->m_winText.setFillColor(textColor);

  auto windowSize { target.getSize() };
  auto textBounds { this->m_winText.getLocalBounds() };

  this->m_winText.setPosition({
    windowSize.x / 2.f - textBounds.getCenter().x,
    windowSize.y / 2.f - textBounds.getCenter().y +  yOffset
  });
  target.draw(this->m_winText);
}

void Board::displayWinText(sf::RenderWindow& target) {
  // RGB(0, 51, 102)
  printText("YOU WIN", 100, target, 0, sf::Color::White);
  printText("Click Space To Play Again Or Esc To Close", 50, target, 50, sf::Color::White);

  std::stringstream ss{};
  ss <<  "You Took " << Config::countSteps << " Steps";
  printText(ss.str(), 50, target, 100, sf::Color::White);

}

std::ostream &operator<<(std::ostream &out, Board &board) {
  std::cout << "\033[2J\033[1;1H" << '\n';
  for (int x{0}; x < Config::gridSize; ++x) {
    for (int y{0}; y < Config::gridSize; ++y) {
      std::cout << board.tiles[x][y];
    }
    out << '\n';
  }

  return out;
}

Point Board::locateEmptyTile() const {
  Point point{};
  for (int y{0}; y < Config::gridSize; ++y) {
    for (int x{0}; x < Config::gridSize; ++x) {
      if (tiles[y][x].isEmpty()) {
        return Point{x, y};
      }
    }
  }
  return Point{-1, -1};
}

Point Board::getTilePoint(const Tile& tile) const {
  for (int y{0}; y < Config::gridSize; ++y) {
    for (int x{0}; x < Config::gridSize; ++x) {
      if (&tiles[y][x] == &tile) {
        return Point{x, y};
      }
    }
  }
  return {-1, -1};
};

void Board::moveTile(sf::RenderWindow &target) {
  if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) { return; }

  sf::Vector2f mousePosition{ target.mapPixelToCoords(sf::Mouse::getPosition(target))};
  for (int y{0}; y < Config::gridSize; ++y) {
    for (int x{0}; x < Config::gridSize; ++x) {
      if (!this->tiles[y][x].contains(mousePosition)) { continue; }

      Point emptyTilePosition{locateEmptyTile()};
      Point tilePoint{getTilePoint(this->tiles[y][x])};

      if (!tilePoint.isAdjacentCell(emptyTilePosition)) { continue; }

      Tile &emptyTile{ this->tiles[emptyTilePosition.getY()][emptyTilePosition.getX()]};

      this->tiles[y][x].move(emptyTile);
      this->m_tileSlideSound.play();

      Config::countSteps++;
    }
  }
}

bool Board::isSolved() const {
  for (int y{}; y < Config::gridSize; ++y) {
    for (int x{}; x < Config::gridSize; ++x) {
      if (this->tiles[y][x].getNum() != Config::solvedBoard[y][x]) {
        return false;
      }
    }
  }
  return true;
}

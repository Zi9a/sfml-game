#include "Tile.h"

#include "Configurations.h"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <sstream>
#include <utility>


void Tile::initTile() {
  this->m_tile.setOutlineColor(sf::Color::Black);
  this->m_tile.setOutlineThickness(1.f);

  if (this->m_tileNumber == 0) {
    this->m_tile.setFillColor(sf::Color::Transparent);
    this->m_tile.setOutlineColor(sf::Color::Transparent);
  }
  this->m_tile.setTexture(&m_texture);
}

void Tile::setTileTextNumber() {
  std::stringstream stream{""};
  if (this->m_tileNumber != 0) {
    stream << this->m_tileNumber;
  }
  this->m_textNumber.setString(stream.str());
}

std::ostream &operator<<(std::ostream &out, Tile tile) {
  if (tile.getNum() > 9) {
    out << " " << tile.getNum() << " ";
  } else if (tile.getNum() > 0) {
    out << "  " << tile.getNum() << " ";
  } else if (tile.getNum() == 0) {
    out << "    ";
  }
  return out;
}

bool operator==(const Tile &t1, const Tile &t2) {
  if (t1.m_tileNumber == t2.m_tileNumber) {
    return true;
  }
  return false;
}

bool operator!=(const Tile &t1, const Tile &t2) { return !(t1 == t2); }

void Tile::drawTile(sf::RenderTarget &target, sf::Vector2f tilePosition) {
  this->m_tile.setPosition(tilePosition);
  target.draw(m_tile);

  auto rectangleBounds{this->m_tile.getGlobalBounds()};
  auto textBounds{this->m_textNumber.getLocalBounds()};

  this->m_textNumber.setPosition(rectangleBounds.getCenter() -
                                 textBounds.getCenter());
  target.draw(m_textNumber);
}

void Tile::renderTileTexture() {
  if (!this->m_texture.loadFromFile(Config::tileTextureFileName)) {
    std::cout << "Error Loading Texture" << '\n';
  }
  this->initTile();
}

void Tile::renderTileNumber(int tileNumber = 0) {
  if (tileNumber < Config::gridSize * Config::gridSize) {
    this->m_tileNumber = tileNumber;
  }

  if (!this->m_font.openFromFile("assets/game_font_2.ttf")) {
    std::cout << "Error Loading Font File" << '\n';
  }

  this->m_textNumber.setFont(m_font);
  this->m_textNumber.setFillColor(sf::Color::White);
  this->m_textNumber.setCharacterSize(70);
  this->setTileTextNumber();
}

bool Tile::contains(sf::Vector2f mousePosition) const {
  auto tileBounds{this->m_tile.getGlobalBounds()};
  return tileBounds.contains(mousePosition);
}


void Tile::updateTileTexture() {
  if (this->m_tileNumber == 0) {
    this->m_tile.setFillColor(sf::Color::Transparent);
    this->m_tile.setOutlineColor(sf::Color::Transparent);
  } else {
    this->m_tile.setFillColor(sf::Color::White);
    this->m_tile.setOutlineColor(sf::Color::Black);
  }
}

void Tile::move(Tile &emptyTile) {
  std::swap(this->m_tileNumber, emptyTile.m_tileNumber);
  this->setTileTextNumber();
  emptyTile.setTileTextNumber();

  std::swap(m_texture, emptyTile.m_texture);
  this->m_tile.setTexture(&m_texture);
  emptyTile.m_tile.setTexture(&emptyTile.m_texture);

  this->updateTileTexture();
  emptyTile.updateTileTexture();
}

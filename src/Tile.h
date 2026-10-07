#ifndef TILE_H
#define TILE_H

#include "Configurations.h"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstddef>
#include <iostream>

class Tile {
private:
  // tile texture
  sf::Texture m_texture{"assets/placeholder.jpg"};
  sf::RectangleShape m_tile{Config::tileSize};

  // Tile Number
  sf::Font m_font{"assets/game_font.ttf"};
  sf::Text m_textNumber{m_font};
  int m_tileNumber{};

  // private member functions
  void initTile();
  void setTileTextNumber();

public:
  // constructors
  Tile() = default;

  // member functions
  void updateTileTexture();
  void renderTileTexture();
  void renderTileNumber(int);
  void drawTile(sf::RenderTarget &, sf::Vector2f);
  void move(Tile &);

  bool contains(sf::Vector2f) const;

  bool isEmpty() const { return this->m_tileNumber == 0; }

  // getters
  int getNum() const { return this->m_tileNumber; }

  // operator overloads
  friend std::ostream &operator<<(std::ostream &, Tile);

  friend bool operator==(const Tile &, const Tile &);
  friend bool operator!=(const Tile &, const Tile &);
  operator int() { return m_tileNumber; }
};

#endif // !TILE_H

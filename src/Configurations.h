#ifndef CONIFIGURATION_H
#define CONIFIGURATION_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <array>

namespace Config {
constexpr int randomizationLevel{ 1000 };

constexpr int gridSize{ 4 }; // 4 x 4 grid
constexpr sf::Vector2f tileSize{100, 100};
constexpr sf::Vector2f boardSize{ tileSize.x * gridSize, tileSize.y * gridSize};

constexpr inline auto generateSolvedBoard() {
  std::array<std::array<int, gridSize>, gridSize> board{};
  int number{ 1 };
  for (int y{}; y < gridSize; ++y) {
    for (int x{}; x < gridSize; ++x) {
      board[y][x] = number++;
    }
  }
  board[gridSize - 1][gridSize - 1] = 0;
  return board;
}

constexpr inline std::array<std::array<int, gridSize>, gridSize> solvedBoard{ generateSolvedBoard() };

inline int countSteps{ 0 };
constexpr inline std::string_view backgroundTextureFileName{ "assets/black_background_image.png" };
constexpr inline std::string_view tileTextureFileName{ "assets/black_tile.png"};

}; // namespace Config

#endif // !CONIFIGURATION

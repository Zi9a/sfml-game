#include "Direction.h"
#include <iostream>
#include <map>

namespace UserInput {
void clearInputBuffer() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void clearInput() {
  if (!std::cin) {
    std::cin.clear();
  }
  clearInputBuffer();
}

bool isValidInput(char c) {
  return c == 'h' || c == 'j' || c == 'k' || c == 'l' || c == 'q';
}

char getValidInput() {
  char c;
  std::cout << "valid command: ";
  std::cin >> c;
  clearInput();
  return c;
}

char getCommandFromUser() {
  Direction direction{};
  char c{};
  while(!isValidInput(c)) {
    c = getValidInput();
  }

  return c;
}

Direction charToDirection(const char character) {
  const std::map<char, Direction::Type> commands{
      {'k', Direction::Up},
      {'j', Direction::Down},
      {'h', Direction::Left},
      {'l', Direction::Right},
  };
  return Direction{commands.at(character)};
}

} // namespace UserInput

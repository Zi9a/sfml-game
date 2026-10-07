#include "Direction.h"
#include "random.h"
#include <map>

std::ostream& operator<<(std::ostream& out, const Direction& direction) {
  out << direction.directionToName();
  return out;
}

std::string_view Direction::directionToName() const {
  switch (this->m_direction) {
  case Direction::Up: return "Up";
  case Direction::Down: return "Down";
  case Direction::Right: return "Right";
  case Direction::Left: return "Left";
  default: return "";
  }
}

Direction operator-(const Direction& direction) {
  std::map<Direction::Type, Direction::Type> oppositeDirection{
    {Direction::Up, Direction::Down},
    {Direction::Down, Direction::Up},
    {Direction::Right, Direction::Left},
    {Direction::Left, Direction::Right},
  };
  return Direction{oppositeDirection.at(direction.m_direction)};
}

Direction Direction::generateRandomDirection() {
  Type random{ static_cast<Type>(Random::get(0, Direction::MaxDirection - 1)) };
  return Direction{ random };
}

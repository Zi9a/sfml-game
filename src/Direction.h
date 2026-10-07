#ifndef DIRECTION_H
#define DIRECTION_H


#include <ostream>
class Direction {
public:
  enum Type {
    Up,
    Down,
    Left,
    Right,
    MaxDirection,
  };

  Direction() = default;
  explicit Direction(Type direction) : m_direction{direction} {}
  explicit Direction(const Direction& direction) : m_direction{direction.m_direction} {}

  friend std::ostream& operator<<(std::ostream&, const Direction&);
  friend Direction operator-(const Direction& direction);

  Direction::Type getType() const {
    return m_direction;
  }

  std::string_view directionToName() const;
  static Direction generateRandomDirection();

private:
  Type m_direction{};
};

#endif // !DIRECTIONS_H

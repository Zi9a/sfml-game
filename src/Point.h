#ifndef POINT_H
#define POINT_H

#include "Direction.h"
#include <ostream>

class Point{
private:
  int m_x{};
  int m_y{};

public:
  Point() = default;
  Point(const Point& point) : m_x{ point.m_x }, m_y{ point.m_y } {}
  Point(int x, int y) : m_x{x}, m_y{y} {}

  friend bool operator==(Point, Point);
  friend bool operator!=(Point, Point);
  friend bool operator>(Point, Point);
  friend bool operator<(Point, Point);

  friend Point operator+(Point, Point);
  friend Point operator-(Point, Point);

  friend std::ostream& operator<<(std::ostream&, Point);

  Point getAdjacentCell(Direction::Type) const;
  bool isAdjacentCell(const Point&);

  int getX() const;
  int getY() const;

  bool pointOutOfBound() const;
};

#endif // !POINT_H

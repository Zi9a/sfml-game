#include "Point.h"
#include "Direction.h"
#include "Configurations.h"
#include <cstdlib>
#include <iostream>
#include <unordered_map>

bool operator==(Point p1, Point p2) {
  return p1.m_x == p2.m_x && p1.m_y == p2.m_y;
}

bool operator!=(Point p1, Point p2) {
  return !(p1.m_x == p2.m_x && p1.m_y == p2.m_y);
}

Point Point::getAdjacentCell(Direction::Type direction) const {
  std::unordered_map<Direction::Type, Point> directionToPoint{
      {Direction::Up, Point{-1, 0}},
      {Direction::Down, Point{1, 0}},
      {Direction::Right, Point{0, 1}},
      {Direction::Left, Point{0, -1}},
  };
  return directionToPoint.at(direction) + *this;
}

bool Point::isAdjacentCell(const Point& emptyTilePoint) {
  Point distance{*this - emptyTilePoint}; 
  distance = { std::abs(distance.m_x), std::abs(distance.m_y) };

  if (distance.m_x > 1 || distance.m_y > 1) {
    return false;
  }
  return distance.m_x ^ distance.m_y;
}

Point operator+(Point p1, Point p2) {
  return Point{p1.m_x + p2.m_x, p1.m_y + p2.m_y};
}

Point operator-(Point p1, Point p2) {
  return Point{p1.m_x - p2.m_x, p1.m_y - p2.m_y};
}

std::ostream& operator<<(std::ostream& out, Point point) {
  out << "{" << point.m_x << ", " << point.m_y << "}";
  return out;
}

bool Point::pointOutOfBound() const {
  return this->m_x > Config::gridSize - 1 || this->m_y > Config::gridSize - 1 || this->m_x < 0 || this->m_y < 0;
}

int Point::getX() const {
  return this->m_x;
}

int Point::getY() const {
  return this->m_y;
}

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowEnums.hpp>

#include "Game.h"

int main() {
  Game game{};
  game.run();

  return 0;
}

/////////////////
// auto window = sf::RenderWindow(sf::VideoMode({1470, 956}), "CMake SFML
// Project",
//                                sf::Style::Default);
// auto [screen_width, screen_height] = window.getSize();
// /////////////////
//
// void drawRectangle(sf::RectangleShape &rectangle) {
//   window.clear();
//   rectangle.setFillColor(sf::Color::Yellow);
//
//   static float velocity_x = 500.f;
//   static float velocity_y = 120.f;
//
//   float deltaTime{0.01};
//
//   rectangle.move({velocity_x * deltaTime, velocity_y * deltaTime});
//
//   auto [x, y]{rectangle.getPosition()};
//
//   auto rectangle_dimension{rectangle.getSize()};
//
//   if (x + rectangle_dimension.x > screen_width) {
//     velocity_x = -velocity_x;
//   }
//   if (y + rectangle_dimension.y > screen_height) {
//     velocity_y = -velocity_y;
//   }
//
//   if (x < 0.f) {
//     velocity_x = -velocity_x;
//   }
//   if (y < 0.f) {
//     velocity_y = -velocity_y;
//   }
//
//   window.draw(rectangle);
//
//   window.display();
// }

// int main() {
//   window.setFramerateLimit(conf::maxFrameRate);
//   window.setPosition(conf::windowPosition);
//
//   std::array<sf::RectangleShape, 1> rectangle{
//       sf::RectangleShape{{250, 250}},
//   };
//
//   while (window.isOpen()) {
//     while (const std::optional event = window.pollEvent()) {
//       if (event->is<sf::Event::Closed>()) {
//         window.close();
//       } else if (const auto *keyPressed =
//                      event->getIf<sf::Event::KeyPressed>()) {
//         if (keyPressed->scancode == sf::Keyboard::Scan::Escape) {
//           window.close();
//         }
//       }
//     }
//
//     for (auto &rect : rectangle) {
//       drawRectangle(rect);
//     }
//   }
//
//   return 0;
// }

///////// ////// ////// //////
///////// ////// ////// //////
///////// ////// ////// //////

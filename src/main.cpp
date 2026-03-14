#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowEnums.hpp>

int main() {
  auto window = sf::RenderWindow(sf::VideoMode({1470, 956}),
                                 "CMake SFML Project", sf::Style::Default);
  window.setFramerateLimit(144);
  window.setPosition({0, 0});

  auto [screen_width, screen_height] = window.getSize();

  sf::CircleShape circle{100.f, 5};
  auto bounds = circle.getLocalBounds();
  circle.setOrigin({bounds.size.x, bounds.size.y});

  sf::CircleShape circle2{circle};
  auto bounds2 = circle2.getLocalBounds();
  circle2.setOrigin({bounds2.size.x, bounds2.size.y});

  sf::CircleShape circle3{circle};
  auto bounds3 = circle3.getLocalBounds();
  circle3.setOrigin({bounds3.size.x, bounds3.size.y});

  float dt = 0.01;

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      } else if (const auto *keyPressed =
                     event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scan::Escape) {
          window.close();
        }
      }
    }

    // this is bad code
    circle.setFillColor(sf::Color::Black);
    circle.setOutlineColor(sf::Color::Red);
    circle.setOutlineThickness(-10.f);
    circle.setPosition({(screen_width + dt) / (2.f), screen_height / 2.f});

    circle2.setFillColor(sf::Color::Black);
    circle2.setOutlineColor(sf::Color::Green);
    circle2.setOutlineThickness(-10.f);
    circle2.setPosition({(screen_width) / 2.f, screen_height / 2.f});

    circle3.setFillColor(sf::Color::Black);
    circle3.setOutlineColor(sf::Color::Blue);
    circle3.setOutlineThickness(-10.f);
    circle3.setPosition({(screen_width - dt) / (2.f), screen_height / 2.f});

    circle.rotate(sf::degrees(dt / 100));
    circle2.rotate(sf::degrees(dt / 100));
    circle3.rotate(sf::degrees(dt / 100));

    dt += 0.05;

    window.clear();

    window.draw(circle);
    window.draw(circle2);
    window.draw(circle3);

    window.display();
  }
}

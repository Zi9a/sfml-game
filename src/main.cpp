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
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowEnums.hpp>

#include <array>

template <typename T> class Rectangle {
public:
  void drawRectangle(T x, T y) {}
};

int main() {
  auto window = sf::RenderWindow(sf::VideoMode({1470, 956}),
                                 "CMake SFML Project", sf::Style::Default);
  window.setFramerateLimit(144);
  window.setPosition({0, 0});

  auto [screen_width, screen_height] = window.getSize();
  sf::RectangleShape something{{10, 10}};

  std::array<sf::RectangleShape, 10> rectangle{
      sf::RectangleShape{{250, 250}}, sf::RectangleShape{{250, 250}},
      sf::RectangleShape{{250, 250}}, sf::RectangleShape{{250, 250}},
      sf::RectangleShape{{250, 250}}, sf::RectangleShape{{250, 250}},
      sf::RectangleShape{{250, 250}}, sf::RectangleShape{{250, 250}},
      sf::RectangleShape{{250, 250}}, sf::RectangleShape{{250, 250}},
  };

  float dt{0.5};

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

    window.clear();

    float dx{0.1};
    float dy{0.1};

    for (auto idx{0}; idx < std::size(rectangle); ++idx) {
      rectangle[idx].move({dx, dt});
      dx += 0.1;
      dy += 0.1;

      if (idx % 2 == 0) {
        rectangle[idx].setFillColor(sf::Color::Yellow);
      } else if (idx % 5 == 0) {
        rectangle[idx].setFillColor(sf::Color::Red);
      } else {
        rectangle[idx].setFillColor(sf::Color::Green);
      }
      rectangle[idx].setPosition({idx * 100 + 100.f, 200});
      window.draw(rectangle[idx]);
    }

    window.display();
  }
}

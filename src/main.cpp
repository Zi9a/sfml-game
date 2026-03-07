#include <SFML/Graphics.hpp>
#include <SFML/Window/WindowEnums.hpp>

// use this command to set neovim built-in command make to build and run the
// code (only this file)
// set makeprg=cmake\ -B\ build\ &&\ cmake\ --build\ build\ &&\ ./build/bin/main

int main() {
  auto window = sf::RenderWindow(sf::VideoMode({720u, 360u}),
                                 "CMake SFML Project", sf::Style::Default);

  window.setFramerateLimit(144);
  window.setPosition({720, 0});

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear();
    window.display();
  }
}

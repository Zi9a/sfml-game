#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cstdint>
namespace conf {

uint32_t maxFrameRate{144};
sf::Vector2<int> windowSize{1470, 956};
sf::Vector2<int> windowPosition{0, 0};
sf::Vector2f windowSize_f = static_cast<sf::Vector2f>(windowSize);

// default window
auto defaultWindow{sf::RenderWindow(sf::VideoMode({1470, 956}),
                                    "Bouncing Block", sf::Style::Default)};

sf::VideoMode fitToScreen{sf::VideoMode({1470, 956})};
const char *title{"Bouncing Block"};
} // namespace conf

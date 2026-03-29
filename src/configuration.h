#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cstdint>
namespace conf {

constexpr uint32_t maxFrameRate{144};
constexpr sf::Vector2<int> windowSize{1470, 956};
constexpr sf::Vector2<int> windowPosition{0, 0};
constexpr sf::Vector2f windowSize_f = static_cast<sf::Vector2f>(windowSize);

// default window
// const auto defaultWindow{sf::RenderWindow( sf::VideoMode({1470, 956}),
// "Bouncing Block", sf::Style::Default) };

const sf::VideoMode fitToScreen{{1470, 956}};
const char *const title{"something"};
} // namespace conf

#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cstdint>
#include <string_view>

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

constexpr sf::Vector2f circleVelocity{100, 100};
constexpr sf::Vector2f circlePosition{0, static_cast<float>(windowSize.y) / 2};
constexpr sf::Color circleColor{sf::Color::White};
constexpr float radius{10};

constexpr float deltaTime{0.07};

constexpr float gravityConstant{100};

constexpr int numberOfBalls{10};
constexpr std::string_view ballTexturePath{"/Users/ziyadhandu/code/sfml-game/res/img/ball-texture.png"};

} // namespace conf

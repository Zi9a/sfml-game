cmake_minimum_required(VERSION 3.28)
project(game LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main 
    src/Board.cpp
    src/Direction.cpp
    src/Game.cpp
    src/main.cpp
    src/Point.cpp
    src/Tile.cpp
)
target_compile_features(main PRIVATE cxx_std_23)
target_link_libraries(main PRIVATE SFML::Graphics SFML::Audio SFML::Window SFML::System)

add_executable(
  MyApp MACOSX_BUNDLE 
    src/Board.cpp
    src/Direction.cpp
    src/Game.cpp
    src/main.cpp
    src/Point.cpp
    src/Tile.cpp
)
target_compile_features(MyApp PRIVATE cxx_std_23)
target_link_libraries(MyApp SFML::Graphics SFML::Audio SFML::Window SFML::System)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)

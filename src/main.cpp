#include "Game.h"

int main() {
  Game game{}; // create game object

  // start Game Loop
  while (game.isRunning()) {
    game.update();
    game.render();
  }

  return 0;
}

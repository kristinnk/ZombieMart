#include "includes.h"
#include "game_class.h"

int main(int argc, char **argv) {
  
  game_class game;
  
  bool quit = false;
  while ( !quit ) { // Game loop
    game.inputHandler();
    game.update();
    game.draw();
    
    // Turn off after one frame. remover
    // when keyboard handler has been
    // implemented
    quit = true;
  }
  
  return 0;
}

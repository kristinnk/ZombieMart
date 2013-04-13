#include "includes.h"
#include "game_class.h"

int main(int argc, char **argv) {
  std::cout << "Starting game..\n";
  game_class game;
  int target_fps = 60;
  
  bool quit = false;
  
  while ( !quit ) { // Game loop
    game.draw();
    
    if ( game.inputHandler() == MSG_QUIT ) {
        quit = true;
    };
    game.update();
    SDL_Delay( 1000 / target_fps );
  }
  std::cout << "Closing the game.\n";
  return 0;
}

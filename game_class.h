#include "SDL/SDL.h"
#include "player.h"

class game_class {
public:
  game_class();
  ~game_class();
  //void inputHandler();
  //void update();
  void draw();
  player_class player;
  
private:
  SDL_Surface* m_screen;
  int m_screenWidth;
  int m_screenHeight;
  int m_screenBPP;
  
  
};
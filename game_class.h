#include "SDL/SDL.h"
#include "player.h"

class game_class {
public:
  game_class();
  ~game_class();
  void inputHandler();
  void update();
  void draw();
  
private:
  SDL_Surface* screen;
  int m_screenWidth;
  int m_screenHeight;
  int m_screenBPP;
  
  player_class player;
  
};
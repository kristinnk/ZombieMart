#include "SDL/SDL.h"
#include "player.h"
#include "world.h"
#include "projectiles.h"

class game_class : public utility_class {
public:
  game_class();
  ~game_class();
  int inputHandler();
  void update();
  void draw();
  void check_collisions();
  player_class player;
  world_class world;
  
private:
  SDL_Surface* m_screen;
  int m_screenWidth;
  int m_screenHeight;
  int m_screenBPP;
  SDL_Event event;
  void clear_screen();
  std::vector<zombie_class> zombies;
  std::vector<projectile_class> projectiles;
};
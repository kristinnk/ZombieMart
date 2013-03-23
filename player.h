#include "includes.h"

class player_class {
public:
    player_class();
    void draw();
    void assign_surface(SDL_Surface *scr);
  
private:
    int m_posX;
    int m_posY;
    SDL_Surface* m_player_sprite;
    SDL_Surface* m_screen_pointer;
    
};
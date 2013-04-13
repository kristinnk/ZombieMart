#include "includes.h"

#ifndef __player_class
#define __player_class

class player_class : public image_handler, public creature_base {
public:
    player_class();
    ~player_class();
    void load_initial_values();
    void draw();
    void assign_surface(SDL_Surface *scr);
    void move();
    void setVectorDirection( int direction );
  
    int getPosX() { return m_posX; }
    int getPosY() { return m_posY; }
    
    int getVectorX() { return m_vectorX; }
    int getVectorY() { return m_vectorY; }
    
private:
    int m_posX;
    int m_posY;
    int m_vectorX;
    int m_vectorY;
    SDL_Surface* m_player_sprite;
    SDL_Surface* m_screen_pointer;
    int m_movement_ticker;
    int m_frame_nr;
    
};

#endif
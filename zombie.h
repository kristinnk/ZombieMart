#include "includes.h"

#ifndef __zombie_class
#define __zombie_class

class zombie_class : public creature_base, public image_handler {

public:
    zombie_class();
    void assign_surface( SDL_Surface *scr) { m_screen_pointer = scr; }
    void assign_player_info( player_class *player_info ) { m_playerInfo = player_info; }
    void setPos( int x, int y ) { m_posX = x; m_posY = y; }
    int getPosX() { return m_posX; }
    int getPosY() { return m_posY; }
    void process_next_move();
    void draw();
    
private:
    player_class *m_playerInfo;
    SDL_Surface *m_zombieSprite;
    SDL_Surface *m_screen_pointer;
    int m_posX;
    int m_posY;
    int m_vectorX;
    int m_vectorY;
    int m_movement_ticker;
    int m_frame_nr;
};

#endif
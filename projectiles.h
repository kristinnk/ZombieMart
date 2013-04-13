#include "includes.h"

#ifndef __projectile_class
#define __projectile_class

enum{ TYPE_FIRE, TYPE_ICE, TYPE_ACID, TYPE_NONE };

class projectile_class : public image_handler {
public:
    projectile_class(SDL_Surface* screen_pointer, int type );
     
    int posX;
    int posY;
    int vectorX;
    int vectorY;
    int vectorSpeed;
    
    int width;
    int height;
    
    int damage;
    int type;
    
    void move();
    void draw();
    
private:
    SDL_Surface *m_sprite;
    SDL_Surface *m_screenPointer;
    
};

#endif
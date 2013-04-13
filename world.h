#include "includes.h"

class world_class : public image_handler {
public:
    world_class();
    void assign_surface(SDL_Surface *scr);
    void generate_stone_floor();
    void draw();
    void loadLevel( int level );
    
private:
    SDL_Surface* m_screen_pointer;
    //SDL_Surface* m_surfaces; 
    SDL_Surface* m_grey_floor_tile;
    SDL_Surface* m_wall_tile;
    SDL_Surface* m_grey_floor_surface; // temporary. Write better routines to deal with multiple textures.
};

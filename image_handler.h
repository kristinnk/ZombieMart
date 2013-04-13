#include "includes.h"

#ifndef __c_img_handler
#define __c_img_handler

class image_handler {
public:
    SDL_Surface* loadImageBMP( std::string filename );
    void applySurfaceXY( int x, int y, SDL_Surface* source, SDL_Surface* destination );
    void applySurfaceClipXY( SDL_Surface* source, int clip_x, int clip_y, int clip_w, int clip_h, SDL_Surface* destination, int dest_x, int dest_y );
    
private:
  
};

#endif
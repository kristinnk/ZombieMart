#include "image_handler.h"

SDL_Surface* image_handler::loadImageBMP(std::string filename)
{
  SDL_Surface* loaded_image = NULL;
  SDL_Surface* optimized_image  = NULL;
  
  loaded_image = SDL_LoadBMP( filename.c_str() );
  
  if ( loaded_image != NULL ) {
    optimized_image = SDL_DisplayFormat( loaded_image );
    SDL_FreeSurface( loaded_image );
    
    if ( optimized_image != NULL ) {
        Uint32 colorkey = SDL_MapRGB( optimized_image->format, 0xFF, 0, 0xFF );
        SDL_SetColorKey( optimized_image, SDL_SRCCOLORKEY, colorkey );
    }
    
  } else {
    std::cout << "!! Failed to load " << filename.c_str() << "\n";
  }
  
  return optimized_image;
}

void image_handler::applySurfaceXY(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, NULL, destination, &offset );
}

void image_handler::applySurfaceClipXY( SDL_Surface* source, int clip_x, int clip_y, int clip_w, int clip_h, SDL_Surface* destination, int dest_x, int dest_y )
{
    SDL_Rect dest_offset;
    SDL_Rect clip_offset;
    
    dest_offset.x = dest_x;
    dest_offset.y = dest_y;
    
    clip_offset.x = clip_x;
    clip_offset.y = clip_y;
    clip_offset.w = clip_w;
    clip_offset.h = clip_h;
    
    SDL_BlitSurface( source, &clip_offset, destination, &dest_offset );
    
}

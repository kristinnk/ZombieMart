#include "world.h"

world_class::world_class()
{

}


void world_class::assign_surface(SDL_Surface* scr)
{
    m_screen_pointer = scr;
    
    char *fileName = "assets/tiles/stonefloor.bmp";
    std::ifstream checker( fileName );
    if ( checker ) {
        m_grey_floor_tile = loadImageBMP( fileName );
    } else {
        m_grey_floor_tile = NULL;
        std::cout << "The tile sprite file was not found : " << fileName << "\n";
    }
    
    char *fileName2 = "assets/tiles/stone_tile.bmp";
    std::ifstream checker2( fileName2 );
    if ( checker2 ) {
        m_wall_tile = loadImageBMP( fileName2 );
    } else {
        m_wall_tile = NULL;
        std::cout << "The tile sprite file was not found : " << fileName2 << "\n";
    }
    
    generate_stone_floor();
}


void world_class::generate_stone_floor()
{
    // Empty surface
    SDL_Surface *tempSurface = SDL_CreateRGBSurface( SDL_SWSURFACE, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, 
                                                     m_screen_pointer->format->BitsPerPixel, 
                                                     m_screen_pointer->format->Rmask, 
                                                     m_screen_pointer->format->Gmask, 
                                                     m_screen_pointer->format->Bmask, 
                                                     0 );
    // Create temporary test world
    for (int x = 0; x < (RESOLUTION_WIDTH/32); x++ ) {
        for ( int y = 0; y < (RESOLUTION_HEIGHT/32); y++ ) {
            if ( x == 0 || x == (RESOLUTION_WIDTH/32-1) || y == 0 || y == (RESOLUTION_HEIGHT/32-1) ) {
                applySurfaceClipXY( m_wall_tile, 0, 0, 32, 32, tempSurface, x*32, y*32 );
            } else {
                applySurfaceClipXY( m_grey_floor_tile, 0, 0, 32, 32, tempSurface, x*32, y*32 );
            }
        }
    }
        
    m_grey_floor_surface = tempSurface;
}


void world_class::loadLevel(int level)
{

    char *fileName = "maps/level1.map";
    std::ifstream checker( fileName );
    if ( checker ) {
     
    } else {
        std::cout << "Level file not found : " << fileName << "\n";
    }
    
}


void world_class::draw()
{
    // Draw the world
    applySurfaceClipXY( m_grey_floor_surface, 0, 0, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, m_screen_pointer, 0, 0 );
}

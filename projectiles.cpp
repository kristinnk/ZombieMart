#include "projectiles.h"

void projectile_class::move()
{
    posX += vectorX * vectorSpeed;
    posY += vectorY * vectorSpeed;
}

projectile_class::projectile_class(SDL_Surface* screen_pointer, int type)
{
    m_screenPointer = screen_pointer;
    
    switch (type) {
        case TYPE_ACID: {
                            // Load bitmap
                            char *fileName = "assets/img/green_ball16x16.bmp";
                            std::ifstream checker( fileName );
                            if ( checker ) {
                                m_sprite = loadImageBMP( fileName );
                            } else {
                                m_sprite = NULL;
                                std::cout << "The acid projectile sprite file was not found.\n";
                            }
                        }
                        break;
        default:        break;
    }    
}

void projectile_class::draw()
{
    applySurfaceClipXY( m_sprite, 0, 0, 16, 16, m_screenPointer, posX+4, posY+8 );
}

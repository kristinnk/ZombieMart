#include "zombie.h"


zombie_class::zombie_class()
{
    char *fileName = "assets/img/zombie.bmp";
    std::ifstream checker( fileName );
    if ( checker ) {
        m_zombieSprite = loadImageBMP( fileName );
    } else {
        m_zombieSprite = NULL;
        std::cout << "The zombie sprite file was not found.\n";
    }
    
    m_vectorX = 0;
    m_vectorY = 0;
}

void zombie_class::draw()
{
    m_movement_ticker++;

    if ( m_movement_ticker > 20 ) {
        m_movement_ticker = 0;        
        
        if ( m_frame_nr == 0 ) {
            m_frame_nr = 1;
        } else {
            m_frame_nr = 0;
        }
    }    
    
    if ( m_vectorX > 0 ) { // right movement
        switch ( m_frame_nr ) {
            case 0: applySurfaceClipXY( m_zombieSprite, 0, 64, 32, 32, m_screen_pointer, m_posX, m_posY);
                    break;
            case 1: applySurfaceClipXY( m_zombieSprite, 32, 64, 32, 32, m_screen_pointer, m_posX, m_posY);
                    break;
            default: break;
        }
    } else
    if ( m_vectorX < 0 ) { // left movement
        switch ( m_frame_nr ) {
            case 0: applySurfaceClipXY( m_zombieSprite, 0, 96, 32, 32, m_screen_pointer, m_posX, m_posY);
                    break;
            case 1: applySurfaceClipXY( m_zombieSprite, 32, 96, 32, 32, m_screen_pointer, m_posX, m_posY);
                    break;
            default: break;
        }
    } else
    if ( m_vectorY < 0 ) { // up movement
        switch ( m_frame_nr ) {
            case 0: applySurfaceClipXY( m_zombieSprite, 32, 0, 32, 32, m_screen_pointer, m_posX, m_posY);
                    break;
            case 1: applySurfaceClipXY( m_zombieSprite, 32, 32, 32, 32, m_screen_pointer, m_posX, m_posY);                    
                    break;
            default: break;
        }
    } else
    if ( m_vectorY > 0 ) { // down movement
        switch ( m_frame_nr ) {
            case 0: applySurfaceClipXY( m_zombieSprite, 0, 0, 32, 32, m_screen_pointer, m_posX, m_posY);                    
                    break;
            case 1: applySurfaceClipXY( m_zombieSprite, 0, 32, 32, 32, m_screen_pointer, m_posX, m_posY);                    
                    break;
            default: break;
        }
    } else {
        applySurfaceClipXY( m_zombieSprite, 64, 64, 32, 32, m_screen_pointer, m_posX, m_posY);
    }
}

void zombie_class::process_next_move()
{
    if ( m_playerInfo->getPosX() < m_posX ) { 
        //m_vectorY = 0;
        m_vectorX = -1;
    }
    if ( m_playerInfo->getPosX() > m_posX ) { 
        //m_vectorY = 0;
        m_vectorX = 1;
    } 
    if ( m_playerInfo->getPosY() < m_posY ) { 
        m_vectorY = -1;
        //m_vectorX = 0;
    } 
    if ( m_playerInfo->getPosY() > m_posY ) { 
        m_vectorY = 1;
        //m_vectorX = 0;
    }
    
    if ( m_playerInfo->getPosX() == m_posX ) {
        m_vectorX = 0;
    }
    if ( m_playerInfo->getPosY() == m_posY ) {
        m_vectorY = 0;
    }
    
    m_posX += m_vectorX;
    m_posY += m_vectorY;
}
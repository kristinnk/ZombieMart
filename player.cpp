#include "player.h"

player_class::player_class()
{
  m_posX = 100;
  m_posY = 100;
  m_vectorX = 0;
  m_vectorY = 0;
  m_movement_ticker = 0;
  m_frame_nr = 0;
}


player_class::~player_class()
{
    SDL_FreeSurface( m_player_sprite );
}


void player_class::load_initial_values()
{
  // Check if the file exists. TODO: Replace with a file check function
  char *fileName = "assets/img/player.bmp";
  std::ifstream checker( fileName );
  if ( checker ) {
    //m_player_sprite = SDL_LoadBMP( fileName );
      m_player_sprite = loadImageBMP( fileName );
  } else {
    m_player_sprite = NULL;
    std::cout << "The player sprite file was not found.\n";
  }
}


void player_class::assign_surface(SDL_Surface* scr)
{
    m_screen_pointer = scr;
}


void player_class::setVectorDirection(int direction)
{
    int vectorLength = 3;
    switch ( direction ) {
        case UP:    m_vectorX = 0;
                    m_vectorY = vectorLength * -1;
                    break;
        case DOWN:  m_vectorX = 0;
                    m_vectorY = vectorLength; 
                    break;
        case LEFT:  m_vectorY = 0;
                    m_vectorX = vectorLength * -1;
                    break;
        case RIGHT: m_vectorY = 0;
                    m_vectorX = vectorLength;
                    break;
        case STOP:  m_vectorX = 0;
                    m_vectorY = 0;
                    break;
    }
}


void player_class::move()
{
    m_posX += m_vectorX;
    m_posY += m_vectorY;
}


void player_class::draw()
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
            case 0: applySurfaceClipXY( m_player_sprite, 0, 64, 32, 32, m_screen_pointer, m_posX, m_posY);
                    break;
            case 1: applySurfaceClipXY( m_player_sprite, 32, 64, 32, 32, m_screen_pointer, m_posX, m_posY);
                    break;
            default: break;
        }
    } else
    if ( m_vectorX < 0 ) { // left movement
        switch ( m_frame_nr ) {
            case 0: applySurfaceClipXY( m_player_sprite, 0, 96, 32, 32, m_screen_pointer, m_posX, m_posY);
                    break;
            case 1: applySurfaceClipXY( m_player_sprite, 32, 96, 32, 32, m_screen_pointer, m_posX, m_posY);
                    break;
            default: break;
        }
    } else
    if ( m_vectorY < 0 ) { // up movement
        switch ( m_frame_nr ) {
            case 0: applySurfaceClipXY( m_player_sprite, 32, 0, 32, 32, m_screen_pointer, m_posX, m_posY);
                    break;
            case 1: applySurfaceClipXY( m_player_sprite, 32, 32, 32, 32, m_screen_pointer, m_posX, m_posY);                    
                    break;
            default: break;
        }
    } else
    if ( m_vectorY > 0 ) { // down movement
        switch ( m_frame_nr ) {
            case 0: applySurfaceClipXY( m_player_sprite, 0, 0, 32, 32, m_screen_pointer, m_posX, m_posY);                    
                    break;
            case 1: applySurfaceClipXY( m_player_sprite, 0, 32, 32, 32, m_screen_pointer, m_posX, m_posY);                    
                    break;
            default: break;
        }
    } else {
        applySurfaceClipXY( m_player_sprite, 64, 64, 32, 32, m_screen_pointer, m_posX, m_posY);
    }
    
    
    //applySurfaceClipXY( m_player_sprite, 0, 0, 32, 32, m_screen_pointer, m_posX, m_posY );    
}

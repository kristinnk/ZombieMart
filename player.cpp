#include "player.h"

player_class::player_class()
{
  m_posX = 100;
  m_posY = 100;

  // Check if the file exists. TODO: Replace with a file check function
  char *fileName = "assets/img/green_ball16x16.bmp";
  std::ifstream checker( fileName );
  //std::ifstream checker( "assets/img/green_ball16x16.bmp" );
  if ( checker ) {
    m_player_sprite = SDL_LoadBMP( fileName );    
  } else {
    m_player_sprite = NULL;
    std::cout << "The file was not found.\n";
  }
}

void player_class::assign_surface(SDL_Surface* scr)
{
    m_screen_pointer = scr;
}


void player_class::draw()
{
    SDL_BlitSurface( m_player_sprite, NULL, m_screen_pointer, NULL);
}

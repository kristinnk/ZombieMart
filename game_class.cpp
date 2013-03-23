#include "game_class.h"

game_class::game_class()
{
  m_screenWidth = 640;
  m_screenHeight = 480;
  m_screenBPP = 32;
  
  SDL_Init( SDL_INIT_EVERYTHING );
  m_screen = SDL_SetVideoMode( m_screenWidth, m_screenHeight, m_screenBPP, SDL_SWSURFACE );
  player.assign_surface( m_screen );
}


game_class::~game_class()
{
  SDL_Quit();
}


void game_class::draw()
{
  player.draw();
  SDL_Flip( m_screen );
  SDL_Delay( 1000 );
}
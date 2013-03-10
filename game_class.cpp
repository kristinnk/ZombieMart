#include "game_class.h"

game_class::game_class()
{
  m_screenWidth = 800;
  m_screenHeight = 600;
  m_screenBPP = 32;
  
  SDL_Init( SDL_INIT_EVERYTHING );
  SDL_SetVideoMode( m_screenWidth, m_screenHeight, m_screenBPP, SDL_SWSURFACE );
}


game_class::~game_class()
{
  SDL_Quit();
}


void game_class::inputHandler()
{

}


void game_class::update()
{

}


void game_class::draw()
{
  SDL_Flip( screen );
  SDL_Delay( 1000 );
}
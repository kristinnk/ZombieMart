#include "player.h"

player_class::player_class()
{
  m_posX = 100;
  m_posY = 100;  
  m_player_sprite = SDL_LoadBMP( "assets/img/green_ball16x16.bmp" );
}

void player_class::draw()
{

}

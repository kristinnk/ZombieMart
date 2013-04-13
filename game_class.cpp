#include "game_class.h"

game_class::game_class()
{    
    m_screenWidth = RESOLUTION_WIDTH;
    m_screenHeight = RESOLUTION_HEIGHT;
    m_screenBPP = 32;

    SDL_Init( SDL_INIT_EVERYTHING );
    //m_screen = SDL_SetVideoMode( m_screenWidth, m_screenHeight, m_screenBPP, SDL_SWSURFACE | SDL_FULLSCREEN);
    m_screen = SDL_SetVideoMode( m_screenWidth, m_screenHeight, m_screenBPP, SDL_SWSURFACE | SDL_DOUBLEBUF );
    
    player.assign_surface( m_screen );
    player.load_initial_values();
    
    world.assign_surface( m_screen );
    
    SDL_WM_SetCaption( "ZombieMart : Shop till you drop.", NULL );
}


game_class::~game_class()
{
  SDL_Quit();
}


void game_class::clear_screen()
{
    SDL_FillRect( m_screen, NULL, SDL_MapRGB( m_screen->format, 32, 32, 32 ));
}



int game_class::inputHandler()
{
   while ( SDL_PollEvent( &event ) ) {        
        if ( event.type == SDL_KEYDOWN ) {
            switch ( event.key.keysym.sym ) {
                case SDLK_ESCAPE:   return MSG_QUIT;
                                    break;
                case SDLK_z:        {
                                        zombie_class tempZomb;
                                        tempZomb.setPos( 300, 300 );
                                        tempZomb.assign_surface( m_screen );
                                        tempZomb.assign_player_info( &player );
                                        zombies.push_back( tempZomb );
                                    }
                                    break;
                case SDLK_SPACE:        {
                                        projectile_class projectile( m_screen, TYPE_ACID );                                        
                                        projectile.posX = player.getPosX();
                                        projectile.posY = player.getPosY();
                                        projectile.vectorSpeed = 2;
                                        projectile.damage = 1;
                                        projectile.vectorX = player.getVectorX();
                                        projectile.vectorY = player.getVectorY();
                                        projectiles.push_back( projectile );
                                        std::cout << "Adding projectile \n";
                                    }
                                    break;
                default:            break;
            }
        } else if ( event.type == SDL_QUIT ) {
            return MSG_QUIT;
        }
    }
    
    // Handle keysym
    Uint8 *key_states = SDL_GetKeyState( NULL );
    
    if ( key_states[ SDLK_UP ] || key_states[ SDLK_w ] ) {
        player.setVectorDirection( UP );
    } else if ( key_states[ SDLK_DOWN ]  || key_states[ SDLK_s ] ) {
        player.setVectorDirection( DOWN );
    } else if ( key_states[ SDLK_LEFT ]  || key_states[ SDLK_a ] ) {
        player.setVectorDirection( LEFT );
    } else if ( key_states[ SDLK_RIGHT ] || key_states[ SDLK_d ] ) {
        player.setVectorDirection( RIGHT );
    }  else { 
        player.setVectorDirection( STOP );
    }
    return MSG_NOTHING;
}


void game_class::check_collisions()
{

    if ( !zombies.empty() ) {
        std::vector<zombie_class>::iterator zIt; // eww
        for ( zIt = zombies.begin(); zIt != zombies.end();) {
        //(*zIt).process_next_move();
        bool zErased = false;
        if ( !projectiles.empty() ) {
            std::vector<projectile_class>::iterator pIt;
            for ( pIt = projectiles.begin(); pIt != projectiles.end(); ) {
                (*pIt).move();
                
                bounding_box zombie;
                bounding_box shot;
                
                zombie.x = (*zIt).getPosX();
                zombie.y = (*zIt).getPosY();
                zombie.w = 32;
                zombie.h = 32;
                
                shot.x = (*pIt).posX;
                shot.y = (*pIt).posY;
                shot.w = 16;
                shot.h = 16;
                
                if ( collides( zombie, shot ) ) {
                    zombies.erase( zIt );
                    projectiles.erase( pIt );
                    zErased = true;
                }
                else {
                    pIt++;
                }
            }
        }  
        if ( !zErased )
            zIt++;
      }
    }
}


void game_class::update()
{
    player.move();
    
    if ( !zombies.empty() ) {
      std::vector<zombie_class>::iterator zIt; // eww
      for ( zIt = zombies.begin(); zIt != zombies.end(); zIt++ ) {
          (*zIt).process_next_move();
      }
    }      
    
    if ( !projectiles.empty() ) {
      std::vector<projectile_class>::iterator pIt; // eww
      for ( pIt = projectiles.begin(); pIt != projectiles.end(); pIt++ ) {
          (*pIt).move();
      }
    }      
    
    if ( !projectiles.empty() ) {
        std::vector<projectile_class>::iterator pIt;
        for ( pIt = projectiles.begin(); pIt != projectiles.end();) {
            bool erased = false;
            
            if ((*pIt).posX > (RESOLUTION_WIDTH) || (*pIt).posX < 0 || (*pIt).posY > (RESOLUTION_HEIGHT) || (*pIt).posY < 0) {
                projectiles.erase( pIt );
                erased = true;
            }
            
            if (!erased) {
                pIt++;
            }
        }
    }
    
    check_collisions(); // TODO > Work on this.
}


void game_class::draw()
{    
    clear_screen();
    world.draw();
    player.draw();
 
    if ( !zombies.empty() ) {
        std::vector<zombie_class>::iterator zIt; // eww
        for ( zIt = zombies.begin(); zIt != zombies.end(); zIt++ ) {
            (*zIt).draw();
        }
    }      
  
    if ( !projectiles.empty() ) {
        std::vector<projectile_class>::iterator zPro;
        for ( zPro = projectiles.begin(); zPro != projectiles.end(); zPro++ ) {
            (*zPro).draw();
        }
    }
      
  SDL_Flip( m_screen );  
}

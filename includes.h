#ifndef __ZM_Includes
#define __ZM_Includes

#include "SDL/SDL.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum { LEFT, RIGHT, UP, DOWN, STOP };
enum { MSG_NOTHING, MSG_QUIT };

const int RESOLUTION_WIDTH = 1024;
const int RESOLUTION_HEIGHT = 768;

#include "misc.h"
#include "image_handler.h"
#include "creature_base.h"
#include "projectiles.h"
#include "player.h"
#include "zombie.h"

#endif
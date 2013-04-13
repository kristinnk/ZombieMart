#include "includes.h"

#ifndef __creature_base
#define __creature_base

class creature_base { // TODO, adapt for creatures.
public:
    bool isDamaged();    
    void inflictDamage( int damage );
    void setStats( int startingHitpoints, int damageReduction );
    
private:
    int m_currentHitpoints;
    int m_maxHitpoints;
    int m_damageReduction;    
};

#endif
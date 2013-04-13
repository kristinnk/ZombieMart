#include "creature_base.h"
#include "player.h"

void creature_base::inflictDamage(int damage)
{
    if ( damage > m_damageReduction ) {
        damage -= m_damageReduction;
        m_currentHitpoints -= damage;
    }
}

bool creature_base::isDamaged()
{
    if ( m_currentHitpoints < m_maxHitpoints ) {
        return true;
    } else {
        return false;
    }
}

void creature_base::setStats(int startingHitpoints, int damageReduction)
{
    m_currentHitpoints = startingHitpoints;
    m_maxHitpoints = startingHitpoints;
    m_damageReduction = damageReduction;
}


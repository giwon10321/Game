//
//  Weapon.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "Weapon.h"

Weapon::Weapon(Sprite* _body, ALLIANCE _allianceType, float _damage):GameObject(_body,_allianceType),damage(_damage)
{
    
}

Weapon::~Weapon()
{
    
}
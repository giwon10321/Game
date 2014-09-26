//
//  Unit.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "Unit.h"


Unit::Unit():GameObject(NULL,TYPE1),HP(0),weapon(NULL)
{
    
}

Unit::Unit(Sprite* _body, ALLIANCE _allianceType, float _HP, Weapon* _weapon):GameObject(_body, _allianceType), HP(_HP),weapon(_weapon)
{
    
}

Unit::~Unit()
{
    
}
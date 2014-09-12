//
//  Tower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "Tower.h"

Tower::Tower(Sprite* _body, ALLIANCE _allianceType,  TOWER_TYPE _towerType, float _HP):GameObject(_body, _allianceType) , eTowerType(_towerType) , HP(_HP)
{
    
}

Tower::~Tower()
{
    
}
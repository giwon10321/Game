//
//  Tower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "Tower.h"

Tower::Tower(Sprite* _body, ALLIANCE _allianceType,  TOWER_TYPE _towerType, float _HP, int _range):GameObject(_body, _allianceType) , eTowerType(_towerType) , HP(_HP), range(_range)
{
    
}

Tower::~Tower()
{
    
}

GameObject Tower::getNearestSpriteInRange(std::vector<GameObject> objects)
{
    
}
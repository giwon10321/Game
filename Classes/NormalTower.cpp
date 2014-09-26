//
//  NormalTower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "NormalTower.h"

NormalTower::NormalTower(Layer* _gameLayer, Point _position, ALLIANCE _allianceType,  TOWER_TYPE _towerType):AttackTower(_gameLayer, _position, _allianceType, _towerType)
{
    
}

NormalTower::~NormalTower()
{
    
}

NormalTower* NormalTower::initNormalTower()
{
    return this;
}
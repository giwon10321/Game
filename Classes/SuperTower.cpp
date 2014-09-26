//
//  SuperTower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "SuperTower.h"

SuperTower::SuperTower(Layer* _gameLayer, Point _position, ALLIANCE _allianceType,  TOWER_TYPE _towerType):AttackTower(_gameLayer, position, _allianceType, _towerType)
{
    this->initSuperTower();
}

SuperTower::~SuperTower()
{
    
}

SuperTower* SuperTower::initSuperTower(){
    return this;
}
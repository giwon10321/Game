//
//  Tower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "Tower.h"

Tower::Tower(Layer* _gameLayer, Point _position, ALLIANCE _allianceType,  TOWER_TYPE _towerType):GameObject(_gameLayer, _position, _allianceType) , eTowerType(_towerType)
{
    this->initTower(_towerType);
}

Tower::~Tower()
{
    
}

Tower* Tower::initTower(TOWER_TYPE _towerType){
    this->eTowerType = _towerType;
    return this;
}
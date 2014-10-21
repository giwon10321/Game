//
//  SuperTower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "SuperTower.h"

SuperTower::SuperTower(GameScene* gameLayer, Point position, Json::Value info):AttackTower(gameLayer, position, info)
{
    this->initSuperTower();
}

SuperTower::~SuperTower()
{
    
}

SuperTower* SuperTower::initSuperTower(){
    return this;
}

void SuperTower::update(float delta)
{
    
}

void SuperTower::attack()
{
    
}
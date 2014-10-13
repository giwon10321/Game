//
//  AttackTower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "AttackTower.h"
#include "GameScene.h"
#include "Unit.h"

AttackTower::AttackTower(GameScene* _gameLayer, Point _position, ALLIANCE _allianceType,  TOWER_TYPE _towerType):Tower(_gameLayer, _position, _allianceType, _towerType)
{
    this->initAttackTower();
}

AttackTower::~AttackTower()
{
    
}

AttackTower* AttackTower::initAttackTower()
{
    return this;
}

void AttackTower::update(float delta)
{
    if(this->target != nullptr){
        
    }else{
        for(auto enermy : this->gameLayer->units){
            if(this->checkCollision(enermy->getPosition(), enermy->thisRadius)){
                this->setTarget(enermy);
            }
        }
    }
}
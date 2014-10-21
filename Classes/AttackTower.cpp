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

AttackTower::AttackTower(GameScene* gameLayer, Point position, Json::Value info):Tower(gameLayer, position, info)
{
    this->initAttackTower();
}

AttackTower::~AttackTower()
{
    
}

AttackTower* AttackTower::initAttackTower()
{
    this->scheduleUpdate();
    return this;
}

void AttackTower::update(float delta)
{
    if(this->target != nullptr){
    }else{
        for(auto enermy : this->gameLayer->units){
            if(this->checkCollision(enermy->getPosition(), enermy->thisRadius)){
                this->setTarget(enermy);
                break;
            }
        }
    }
}
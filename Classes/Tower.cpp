//
//  Tower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "Tower.h"
#include "Unit.h"
#include "GameScene.h"

Tower::Tower(GameScene* gameLayer, Point position, Json::Value info):GameObject(gameLayer, position, info)
{
    this->initTower();
}

Tower::~Tower()
{
    
}

Tower* Tower::initTower(){
    return this;
}

void Tower::removeObject(float damage)
{
    if(this != nullptr){
        this->currentHP -= damage;
        if(this->currentHP <= 0.0f){
            for(auto unit : this->attackBy){
                ((Unit *)unit)->unsetTarget();
            }
            this->gameLayer->towers.eraseObject(this);
            this->removeFromParentAndCleanup(true);
        }
    }
}

void Tower::saveToInventory()
{
	
}

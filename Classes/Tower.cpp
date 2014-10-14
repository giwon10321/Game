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

Tower::Tower(GameScene* _gameLayer, Point _position, ALLIANCE _allianceType,  TOWER_TYPE _towerType):GameObject(_gameLayer, _position, _allianceType) , eTowerType(_towerType)
{
    this->initTower(_towerType);
}

Tower::~Tower()
{
    
}

Tower* Tower::initTower(TOWER_TYPE towerType){
    this->eTowerType = towerType;
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

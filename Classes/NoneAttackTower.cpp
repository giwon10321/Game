//
//  NoneAttackTower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "NoneAttackTower.h"

NoneAttackTower::NoneAttackTower(GameScene* gameLayer, Point position, Json::Value info):Tower(gameLayer, position, info)
{
    this->initNoneAttackTower();
}

NoneAttackTower::~NoneAttackTower()
{
    
}

NoneAttackTower* NoneAttackTower::initNoneAttackTower(){
    return this;
}

//void NoneAttackTower::Attack(GameObject* target, TMXTiledMap* map)
//{
//    
//}
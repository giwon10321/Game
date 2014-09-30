//
//  NoneAttackTower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "NoneAttackTower.h"

NoneAttackTower::NoneAttackTower(GameScene* _gameLayer, Point _position, ALLIANCE _allianceType,  TOWER_TYPE _towerType):Tower(_gameLayer, position, _allianceType, _towerType)
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
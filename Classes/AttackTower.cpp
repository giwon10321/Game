//
//  AttackTower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "AttackTower.h"
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

void AttackTower::setTarget(Unit *enermy)
{
    this->target = nullptr;
    this->target = enermy;
    this->attack();
    enermy->getAttacked(this);
}

void AttackTower::unsetTarget()
{
    if(this->target != nullptr){
        this->target = nullptr;
    }
}

void AttackTower::damageEnermy()
{
    this->target->getDamaged(this->damage);
}

void AttackTower::stopShoot()
{
    this->unschedule(schedule_selector(Tower::shootWeapon));
}

void AttackTower::lostSightOfEnermy()
{
    this->target->gotLostSight(this);
    if(this->target != nullptr){
        this->target = nullptr;
    }
    this->unschedule(schedule_selector(Tower::shootWeapon));
}

void AttackTower::removeObjects(Node* _weapon)
{
    auto weapon = (Sprite *)_weapon;
    weapon->removeFromParentAndCleanup(true);
    this->target->removeUnit(this->damage);
}

//
//  NormalTower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "GameScene.h"
#include "NormalTower.h"

NormalTower::NormalTower(GameScene* _gameLayer, Point _position, ALLIANCE _allianceType,  TOWER_TYPE _towerType):AttackTower(_gameLayer, _position, _allianceType, _towerType)
{
    this->initNormalTower();
}

NormalTower::~NormalTower()
{
    
}

NormalTower* NormalTower::initNormalTower()
{
    this->body = Sprite::create("tower.png");
    this->body->setPosition(this->position);
    this->weaponName = "arrow.png";
    this->maxHP = 100.0f;
    this->currentHP = 100.0f;
    this->attackRange = 1000.0f;
    this->attackRate = 1.0f;
    this->attackSpeed = 1.0f;
    this->damage = 30.0f;
    this->thisRadius = 30.0f;
    
    this->addChild(this->body);

    this->gameLayer->map->addChild(this, 99);
    
    this->scheduleUpdate();
    
    return this;
}

void NormalTower::attack()
{
    this->schedule(schedule_selector(NormalTower::shootWeapon), 0.5f);
}

void NormalTower::shootWeapon(float attackRate)
{
    if(this->target != nullptr){
        Sprite* weapon = Sprite::create(this->weaponName);
        Point towerPosition = this->getPosition();
        Point destination = this->target->getPosition();
        Point diff = destination-towerPosition;
        
        float angle = CC_RADIANS_TO_DEGREES(-1*diff.getAngle());
        
        weapon->Node::setRotation(angle);
        weapon->setPosition(this->getPosition());
        this->gameLayer->map->addChild(weapon,100);
        
        auto moveAction = MoveTo::create(this->attackSpeed,destination);
        auto damageAction = CallFunc::create(CC_CALLBACK_0(AttackTower::damageEnermy, this));
        auto removeAction = CallFuncN::create(CC_CALLBACK_1(AttackTower::removeWeapon, this));
        
        auto actionSequence = Sequence::create(damageAction, moveAction,removeAction, NULL);
        
        weapon->runAction(actionSequence);
    }
}
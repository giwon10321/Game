//
//  NormalTower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "GameScene.h"
#include "NormalTower.h"

NormalTower::NormalTower(GameScene* gameLayer, Point position, Json::Value info):AttackTower(gameLayer, position, info)
{
    this->initNormalTower();
}

NormalTower::~NormalTower()
{
    
}

NormalTower* NormalTower::initNormalTower()
{
    this->body = Sprite::create(info["towerImageName"].asString());
    this->weaponName = info["weaponImageName"].asString();
    this->currentHP = info["maxHP"].asFloat();
    this->virtualHP = info["maxHP"].asFloat();
    this->attackRange = info["attackRange"].asFloat();
    this->attackRatio = info["attackRatio"].asFloat();
    this->attackSpeed = info["attackSpeed"].asFloat();
    this->damage = info["damage"].asFloat();
    this->thisRadius = info["radius"].asFloat();
    
    this->addChild(this->body);

    this->gameLayer->map->addChild(this, 99);
    
    return this;
}

void NormalTower::attack()
{
    this->schedule(schedule_selector(NormalTower::shootWeapon), this->attackRatio);
}

void NormalTower::shootWeapon(float attackRatio)
{
    if(this->target != nullptr){
        Sprite* weapon = Sprite::create(this->weaponName);
        Point towerPosition = this->getPosition();
        Point destination = this->target->getPosition();
        Point diff = destination-towerPosition;
        
        float angle = CC_RADIANS_TO_DEGREES(-1*diff.getAngle());
        
        weapon->setRotation(angle);
        weapon->setPosition(this->getPosition());
        this->gameLayer->map->addChild(weapon,100);
		
		float time = towerPosition.getDistance(destination)/this->attackSpeed;
        auto moveAction = MoveTo::create(time,destination);
        auto damageAction = CallFunc::create(CC_CALLBACK_0(AttackTower::damageEnermy, this));
        auto removeAction = CallFuncN::create(CC_CALLBACK_1(AttackTower::removeWeapon, this));
        
        auto actionSequence = Sequence::create(damageAction, moveAction,removeAction, NULL);
        
        weapon->runAction(actionSequence);
    }
}
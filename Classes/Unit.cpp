//
//  Unit.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "Unit.h"
#include "GameScene.h"
#include "Tower.h"
#include "AttackTower.h"

Unit::Unit(GameScene* gameLayer, Point position, Json::Value info):GameObject(gameLayer, position, info)
{
    this->initUnit();
}

Unit::~Unit()
{
    
}

Unit* Unit::initUnit()
{
    this->body = Sprite::create(info["unitImageName"].asString());
    this->weaponName = info["weaponImageName"].asString();
    this->currentHP = info["maxHP"].asFloat();
    this->virtualHP = info["maxHP"].asFloat();
    this->thisRadius = info["radius"].asFloat();
    this->attackRange = info["attackRange"].asFloat();
    this->attackRatio = info["attackRatio"].asFloat();
    this->attackSpeed = info["attackSpeed"].asFloat();
    this->movementSpeed = info["moveSpeed"].asFloat();
    this->damage = info["damage"].asFloat();
    
    this->addChild(this->body);
    this->gameLayer->map->addChild(this, 101);
    
    this->moveToDestination(this->gameLayer->PositionForTileCoord(Point(6,6)));
    
    this->scheduleUpdate();
    
    return this;
}

void Unit::removeObject(float damage)
{
    if(this != nullptr){
        this->currentHP -= damage;
        if(this->currentHP <= 0.0f){
            for(auto tower : this->attackBy){
                ((AttackTower *)tower)->unsetTarget();
            }
            this->gameLayer->units.eraseObject(this);
            this->removeFromParentAndCleanup(true);
        }
    }
}

void Unit::shootWeapon(float attackRatio)
{
    if(this->target != nullptr){
        Sprite* weapon = Sprite::create(this->weaponName);
        Point unitPosition = this->getPosition();
        Point destination = this->target->getPosition();
        Point diff = destination-unitPosition;
        
        float angle = CC_RADIANS_TO_DEGREES(-1*diff.getAngle());
        
        weapon->setRotation(angle);
        
        weapon->setPosition(this->getPosition());
        this->gameLayer->map->addChild(weapon,100);
		
		float time = unitPosition.getDistance(destination)/this->attackSpeed;
		
        auto moveAction = MoveTo::create(time,destination);
        auto damageAction = CallFunc::create(CC_CALLBACK_0(Unit::damageEnermy, this));
        auto removeAction = CallFuncN::create(CC_CALLBACK_1(Unit::removeWeapon, this));
        auto actionSequence = Sequence::create(damageAction, moveAction,removeAction, NULL);
        
        weapon->runAction(actionSequence);
    }
}

void Unit::attack()
{
    this->schedule(schedule_selector(Unit::shootWeapon), this->attackRatio);
}

void Unit::update(float delta)
{
    if(this->target != nullptr){
        
    }else{
        for(auto tower : this->gameLayer->towers){
            if(this->checkCollision(tower->getPosition(), tower->thisRadius)){
                this->setTarget(tower);
                this->stopActionByTag(999);
                break;
            }
        }
    }
}

void Unit::moveToDestination(Point destination)
{
	float time = this->getPosition().getDistance(destination) / this->movementSpeed;
    auto moveAction = MoveTo::create(time,destination);
    moveAction->setTag(999);
    this->runAction(moveAction);
}


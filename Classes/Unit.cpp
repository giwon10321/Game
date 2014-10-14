//
//  Unit.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "GameScene.h"
#include "Unit.h"
#include "Tower.h"
#include "AttackTower.h"

Unit::Unit(GameScene* _gameLayer, Point _position, ALLIANCE _allianceType):GameObject(_gameLayer, _position, _allianceType)
{
    this->initUnit();
}

Unit::~Unit()
{
    
}

Unit* Unit::initUnit()
{
    this->body = Sprite::create("Player.png");
    this->weaponName = "arrow.png";
    this->maxHP = 10000.0f;
    this->currentHP = this->maxHP;
    this->virtualHP = this->maxHP;
    this->thisRadius = 10.0f;
    this->attackRange = 50.0f;
    this->attackRate = 0.5f;
    this->attackSpeed = 0.1f;
    this->movementSpeed = 30.0f;
    this->damage = 30.0f;
    
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

void Unit::shootWeapon(float attackRate)
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
        
        auto moveAction = MoveTo::create(this->attackSpeed,destination);
        auto damageAction = CallFunc::create(CC_CALLBACK_0(Unit::damageEnermy, this));
        auto removeAction = CallFuncN::create(CC_CALLBACK_1(Unit::removeWeapon, this));
        auto actionSequence = Sequence::create(damageAction, moveAction,removeAction, NULL);
        
        weapon->runAction(actionSequence);
    }
}

void Unit::attack()
{
    this->schedule(schedule_selector(Unit::shootWeapon), this->attackRate);
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
    auto moveAction = MoveTo::create(10.0f,destination);
    moveAction->setTag(999);
    this->runAction(moveAction);
}


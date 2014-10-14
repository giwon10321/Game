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
    this->setPosition(this->position);
    this->maxHP = 100.0f;
    this->currentHP = this->maxHP;
    this->virtualHP = this->maxHP;
    this->thisRadius = 10.0f;
    
    this->addChild(this->body);
    this->gameLayer->map->addChild(this, 101);
    
    return this;
}

void Unit::removeObject(float damage)
{
    if(this != nullptr){
        this->currentHP -= damage;
        if(this->currentHP <= 0.0f){
            for(auto tower : this->gameLayer->towers){
                ((AttackTower *)tower)->unsetTarget();
            }
            this->gameLayer->units.eraseObject(this);
            this->removeFromParentAndCleanup(true);
        }
    }
}

void Unit::shootWeapon(float attackRate)
{
    
}

void Unit::attack()
{
    
}


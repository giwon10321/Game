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
    this->range = 100;
    
    this->addChild(this->body);
    this->gameLayer->map->addChild(this, 101);
    
    return this;
}

void Unit::getAttacked(Tower* tower)
{
    this->attackBy.push_front(tower);
}

void Unit::getDamaged(float _damage)
{
    this->virtualHP -= _damage;
    if(this->virtualHP <= 0 ){
        this->stopScheduled();
    }
}

void Unit::gotLostSight(Tower* tower)
{
    
}

void Unit::stopScheduled()
{
    list<Tower*>::iterator iterator;
    for(iterator = this->attackBy.begin(); iterator != this->attackBy.end(); ++iterator ){
        ((AttackTower* )*iterator)->stopShoot();
    }
}

void Unit::removeUnit(float _damage)
{
    this->currentHP -= _damage;
    if(this->currentHP <= 0.0f){
//        log("test");
        list<Tower*>::iterator iterator;
        for(iterator = this->attackBy.begin(); iterator != this->attackBy.end(); ++iterator ){
            ((AttackTower* )*iterator)->unsetTarget();
        }
        this->gameLayer->units.remove(this);
        this->removeFromParentAndCleanup(true);
    }
}


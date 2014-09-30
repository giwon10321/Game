//
//  Unit.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "Unit.h"
#include "Tower.h"

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
    this->currentHP = 100.0f;
    this->range = 100;
    
    return this;
}

void Unit::gotDamaged(float _damage)
{
    
}

void Unit::gotLostSight(Tower* tower)
{
    
}
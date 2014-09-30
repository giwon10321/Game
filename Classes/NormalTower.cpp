//
//  NormalTower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

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
    this->weapon = Sprite::create("arrow.png");
    this->maxHP = 100.0f;
    this->currentHP = 100.0f;
    this->range = 60;
    this->attackRate = 1.0f;
    this->damage = 30.0f;
    
    this->addChild(this->body);

    this->gameLayer->map->addChild(this, 99);
    
    this->scheduleUpdate();
    
    return this;
}

void NormalTower::attack(float _attackRate)
{
    
}

void NormalTower::shootWeapon()
{
    this->schedule(schedule_selector(NormalTower::attack), this->attackRate);
}

void NormalTower::update(float delta)
{
    log("test");
}
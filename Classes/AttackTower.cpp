//
//  AttackTower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "AttackTower.h"

AttackTower::AttackTower(Layer* _gameLayer, Point _position, ALLIANCE _allianceType,  TOWER_TYPE _towerType):Tower(_gameLayer, _position, _allianceType, _towerType)
{
    this->initAttackTower();
}

AttackTower::~AttackTower()
{
    
}

AttackTower* AttackTower::initAttackTower()
{
    this->schedule(schedule_selector(AttackTower::update),1.0f);
    return this;
}

//void AttackTower::Attack(Unit*& target, TMXTiledMap* map)
//{
//    Point towerPosition = body->getPosition();
//    Point destination = target->getPosition();
//    Point diff = towerPosition-destination;
//    float angle = CC_RADIANS_TO_DEGREES(diff.getAngle());
//    weapon->setPosition(towerPosition);
//    weapon->body->cocos2d::Node::setRotation(angle);
//    map->addChild(weapon->body);
//    MoveTo *moveTo = MoveTo::create(weapon->speed, destination);
//    weapon->body->runAction(moveTo);
//    weapon.body->setPosition(towerPosition);
//    weapon.body->setRotation(angle);
//    map->addChild(weapon.body);
//    MoveTo *moveTo  = MoveTo::create(weapon.speed, destination);
//    weapon.body->runAction(moveTo);
//}

void AttackTower::update(float delta)
{
    log("test");
}
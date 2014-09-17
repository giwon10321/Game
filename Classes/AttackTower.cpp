//
//  AttackTower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "AttackTower.h"

AttackTower::AttackTower(Sprite* _body, ALLIANCE _allianceType,  TOWER_TYPE _towerType, float _HP, int _range, Weapon* _weapon):Tower(_body, _allianceType, _towerType, _HP, _range), weapon(_weapon)
{
    
}

AttackTower::~AttackTower()
{
    
}

void AttackTower::Attack(GameObject* target, TMXTiledMap* map)
{
    Point towerPosition = body->getPosition();
    Point destination = target->getPosition();
    Point diff = towerPosition-destination;
    float angle = CC_RADIANS_TO_DEGREES(diff.getAngle());
    weapon->setPosition(towerPosition);
    weapon->body->cocos2d::Node::setRotation(angle);
    map->addChild(weapon->body);
    MoveTo *moveTo = MoveTo::create(weapon->speed, destination);
    weapon->body->runAction(moveTo);
//    weapon.body->setPosition(towerPosition);
//    weapon.body->setRotation(angle);
//    map->addChild(weapon.body);
//    MoveTo *moveTo  = MoveTo::create(weapon.speed, destination);
//    weapon.body->runAction(moveTo);
}
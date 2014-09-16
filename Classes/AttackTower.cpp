//
//  AttackTower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "AttackTower.h"

AttackTower::AttackTower(Sprite* _body, ALLIANCE _allianceType,  TOWER_TYPE _towerType, float _HP, int _range, const Weapon& _weapon):Tower(_body, _allianceType, _towerType, _HP, _range), weapon(_weapon)
{
    
}

AttackTower::~AttackTower()
{
    
}

void AttackTower::Attack(Point destination, TMXTiledMap *map)
{
    Point towerPosition = body->getPosition();
    Point vertex = Point(towerPosition.x, destination.y);
    
    
    weapon.body->setPosition(towerPosition);
    map->addChild(weapon.body);
    MoveTo *moveTo  = MoveTo::create(weapon.speed, destination);
    weapon.body->runAction(moveTo);
}
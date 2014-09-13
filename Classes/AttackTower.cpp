//
//  AttackTower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "AttackTower.h"

AttackTower::AttackTower(Sprite* _body, ALLIANCE _allianceType,  TOWER_TYPE _towerType, float _HP, Weapon _weapon):Tower(_body, _allianceType, _towerType, _HP), weapon(_weapon)
{
    
}

AttackTower::~AttackTower()
{
    
}

void AttackTower::Attack(Point destination, TMXTiledMap *map)
{
    
    Point towerPosition = body->getPosition();
    weapon.body->setPosition(towerPosition);
    map->addChild(weapon.body);
    MoveTo *moveTo  = MoveTo::create(0.5f, destination);
    weapon.body->runAction(moveTo);
//    log("tower position : %f %f",towerPosition.x, towerPosition.y);

}
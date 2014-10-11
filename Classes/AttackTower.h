//
//  AttackTower.h
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#ifndef __Game__AttackTower__
#define __Game__AttackTower__

#include "cocos2d.h"
#include "Tower.h"
#include <iostream>

USING_NS_CC;

class AttackTower : public Tower
{
public :
    AttackTower(GameScene* _gameLayer, Point _position, ALLIANCE _allianceType,  TOWER_TYPE _towerType);
    AttackTower* initAttackTower();
    virtual ~AttackTower();
    void setTarget(Unit* enermy);
    void unsetTarget();
    virtual void damageEnermy();
    virtual void stopShoot();
    virtual void lostSightOfEnermy();
    void removeObjects(Node* _weapon);
    
    float attackRate;
    float attackSpeed;
    float damage;
    std::string weaponName;
};

#endif /* defined(__Game__AttackTower__) */

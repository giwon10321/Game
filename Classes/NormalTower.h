//
//  NormalTower.h
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#ifndef __Game__NormalTower__
#define __Game__NormalTower__

#include "cocos2d.h"
#include "AttackTower.h"

USING_NS_CC;

class NormalTower : public AttackTower
{
public:
    NormalTower(Layer* _gameLayer, Point position, ALLIANCE _allianceType,  TOWER_TYPE _towerType);
    NormalTower* initNormalTower();
    virtual ~NormalTower();
    void shootWeapon();
    void attack(float _attackRate);
    void update(float delta);
};

#endif /* defined(__Game__NormalTower__) */

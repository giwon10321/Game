//
//  NormalTower.h
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#ifndef __Game__NormalTower__
#define __Game__NormalTower__

#ifndef __Game__GameScene__
#include "cocos2d.h"
#endif
#include "AttackTower.h"

USING_NS_CC;

class NormalTower : public AttackTower
{
public:
    NormalTower(GameScene* _gameLayer, Point position, ALLIANCE _allianceType,  TOWER_TYPE _towerType);
    NormalTower* initNormalTower();
    virtual ~NormalTower();
    void attack();
    void shootWeapon(float attackRate);
};

#endif /* defined(__Game__NormalTower__) */

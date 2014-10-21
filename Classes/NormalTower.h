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
    NormalTower(GameScene* gameLayer, Point position, Json::Value info);
    NormalTower* initNormalTower();
    virtual ~NormalTower();
    void attack();
    void shootWeapon(float attackRate);
};

#endif /* defined(__Game__NormalTower__) */

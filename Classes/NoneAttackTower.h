//
//  NoneAttackTower.h
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#ifndef __Game__NoneAttackTower__
#define __Game__NoneAttackTower__

#include "cocos2d.h"
#include "Tower.h"

USING_NS_CC;

class NoneAttackTower : public Tower
{
public:
    NoneAttackTower(GameScene* gameLayer, Point position, Json::Value info);
    virtual ~NoneAttackTower();
    NoneAttackTower* initNoneAttackTower();
    
};


#endif /* defined(__Game__NoneAttackTower__) */

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
    NoneAttackTower(Sprite* _body, ALLIANCE _allianceType,  TOWER_TYPE _towerType, float _HP, int _range);
    virtual ~NoneAttackTower();
    
};


#endif /* defined(__Game__NoneAttackTower__) */

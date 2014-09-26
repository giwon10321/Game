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
    NoneAttackTower(Layer* _gameLayer, Point _position, ALLIANCE _allianceType,  TOWER_TYPE _towerType);
    virtual ~NoneAttackTower();
    NoneAttackTower* initNoneAttackTower();
    
//    virtual void Attack(GameObject* target, TMXTiledMap* map);
    
};


#endif /* defined(__Game__NoneAttackTower__) */

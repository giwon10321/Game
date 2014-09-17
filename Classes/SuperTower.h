//
//  SuperTower.h
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#ifndef __Game__SuperTower__
#define __Game__SuperTower__

#include "cocos2d.h"
#include "AttackTower.h"

USING_NS_CC;

class SuperTower : public AttackTower
{
public:
    SuperTower(Sprite* _body, ALLIANCE _allianceType, TOWER_TYPE _towerType, float _HP, int _MP, int _range, Weapon* _weapon);
    virtual ~SuperTower();
    int MP;
};

#endif /* defined(__Game__SuperTower__) */

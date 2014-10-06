//
//  Tower.h
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#ifndef __Game__Tower__
#define __Game__Tower__

#include "cocos2d.h"
#include "GameObject.h"
USING_NS_CC;


enum TOWER_TYPE{
    ARROW_NOMARL = 0,
    DETECTING_NORMAL
};

class Unit;
class Tower: public GameObject
{
public:
    Tower(GameScene* _gameLayer, Point _position, ALLIANCE _allianceType,  TOWER_TYPE _towerType);
    virtual ~Tower();
    Tower* initTower(TOWER_TYPE _towerType);
    virtual void attack(float _attackRate) = 0;
    void release();
    
    TOWER_TYPE eTowerType;
    float maxHP;
    float currentHP;
    int range;
    Unit* target;
    list<Unit*> attackBy;
};


#endif /* defined(__Game__Tower__) */

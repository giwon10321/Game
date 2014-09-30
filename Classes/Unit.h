//
//  Unit.h
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#ifndef __Game__Unit__
#define __Game__Unit__

#include "cocos2d.h"
#include "GameObject.h"

USING_NS_CC;

class Tower;
class Unit : public GameObject
{
public:
    Unit();
    Unit(Layer* _gameLayer, Point _position, ALLIANCE _allianceType);
    Unit* initUnit();
    virtual ~Unit();
    void gotDamaged(float _damage);
    void gotLostSight(Tower* tower);
    
    float maxHP;
    float currentHP;
    int range;
    Sprite* weapon;
    Tower* target;
    list<Tower*> attackBy;
};

#endif /* defined(__Game__Unit__) */

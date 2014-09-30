//
//  Unit.h
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#ifndef __Game__Unit__
#define __Game__Unit__

#ifndef __Game__GameScene__
#include "cocos2d.h"
#endif
#include "GameObject.h"
USING_NS_CC;

class Tower;
class Unit : public GameObject
{
public:
    Unit();
    Unit(GameScene* _gameLayer, Point _position, ALLIANCE _allianceType);
    Unit* initUnit();
    virtual ~Unit();
    void gotDamaged(float _damage);
    void gotLostSight(Tower* tower);
    
    float maxHP;
    float currentHP;
    int range;
    Sprite* weapon;
    Tower* target;
    std::list<Tower*> attackBy;
};

#endif /* defined(__Game__Unit__) */

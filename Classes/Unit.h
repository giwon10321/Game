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
    Unit(GameScene* gameLayer, Point position, Json::Value info);
    Unit* initUnit();
    virtual ~Unit();
    void removeObject(float damage);
    void shootWeapon(float attackRate);
    void attack();
    void update(float delta);
    
    virtual void moveToDestination(Point destination);
    
    float movementSpeed;
};

#endif /* defined(__Game__Unit__) */

//
//  Weapon.h
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#ifndef __Game__Weapon__
#define __Game__Weapon__

#include "cocos2d.h"
#include "GameObject.h"

USING_NS_CC;

class Weapon : public GameObject
{
public:
    float damage;
    float speed;
    Weapon(Sprite* _body, ALLIANCE _allianceType, float _damage, float _speed);
    virtual ~Weapon();
};

#endif /* defined(__Game__Weapon__) */

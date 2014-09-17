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
#include "Weapon.h"

USING_NS_CC;

class Unit : public GameObject
{
public:
    Unit(Sprite* _body, ALLIANCE _allianceType, float _HP, Weapon* _weapon);
    virtual ~Unit();
    
    Weapon* weapon;
    float HP;
};

#endif /* defined(__Game__Unit__) */

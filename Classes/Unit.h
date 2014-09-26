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

class Unit : public GameObject
{
public:
    Unit();
    Unit(Layer* _gameLayer, Point _position, ALLIANCE _allianceType);
    virtual ~Unit();
    float HP;
};

#endif /* defined(__Game__Unit__) */

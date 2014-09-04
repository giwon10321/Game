//
//  Object.h
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#ifndef __Game__Object__
#define __Game__Object__

#include "cocos2d.h"
USING_NS_CC;

enum ALLIANCE
{
    TYPE1 = 0,
    TYPE2,
    TYPE3
};

class Object
{
public:
    Object();
    virtual ~Object();
    Sprite* body;
    ALLIANCE eAllianceType;
};

#endif /* defined(__Game__Object__) */

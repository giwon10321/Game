//
//  GameObject.h
//  Game
//
//  Created by Natae on 2014. 9. 5..
//
//

#ifndef __Game__GameObject__
#define __Game__GameObject__

#include "cocos2d.h"
USING_NS_CC;

enum ALLIANCE
{
    TYPE1 = 0,
    TYPE2,
    TYPE3
};

class GameObject
{
public:
    GameObject(Sprite* _body, ALLIANCE _allianceType);
    void setPosition(Point pos);
    virtual ~GameObject();
    Sprite* body;
    ALLIANCE eAllianceType;
};

#endif /* defined(__Game__GameObject__) */

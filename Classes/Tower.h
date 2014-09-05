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

class Tower: public GameObject
{
public:
    Tower();
    virtual ~Tower();
    void release();
    std::vector<Sprite> getSpriteInRage();
    
    std::vector<Sprite> spriteInRage;
    TOWER_TYPE eTowerType;
    float HP;
};


#endif /* defined(__Game__Tower__) */

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
    Tower(Sprite* _body, ALLIANCE _allianceType,  TOWER_TYPE _towerType, float _HP, int _range);
    virtual ~Tower();
    void release();
    
    GameObject getNearestSpriteInRange(std::vector<GameObject> objects);
    std::vector<GameObject> getSpriteInRage();
    std::vector<GameObject> spritesInRage;
    
    TOWER_TYPE eTowerType;
    float HP;
    int range;
};


#endif /* defined(__Game__Tower__) */

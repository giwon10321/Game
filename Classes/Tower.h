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

class Unit;
class Tower: public GameObject
{
public:
    Tower(GameScene* gameLayer, Point position, Json::Value info);
    virtual ~Tower();
    Tower* initTower();
    void removeObject(float damage);
	void saveToInventory();
};


#endif /* defined(__Game__Tower__) */

//
//  GameScene.h
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#ifndef __Game__GameScene__
#define __Game__GameScene__

#define TILEHEIGHT 32
#define TILEWIDTH 64
#define MAPWIDTH 15
#include "cocos2d.h"
#include "AttackTower.h"
#include "Weapon.h"
#include "Unit.h"
#include <iostream>

USING_NS_CC;
using namespace std;

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    cocos2d::EventListenerTouchOneByOne* _touchListener;
    
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    
    Point PositionForTileCoord(Point coord);
    
    Point positionToTileCoord(Point position);
    
    void checkCollision(int flag);
    
    void update(float f);
    
    void summonEnemy(float f);
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
private:
    TMXTiledMap* map;
    std::list<Unit*> units;
    std::list<Tower*> towers;
};


#endif /* defined(__Game__GameScene__) */

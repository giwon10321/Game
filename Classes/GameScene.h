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
#include "Unit.h"
#include "Tower.h"
#include "HudLayer.h"
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
    
    void addTowerToInven(Json::Value towerInfo);
    
    void awardGold(int gold);
    
    bool circle(Point circlePoint, float radius, Point circlePointTwo, float radiusTwo);
    
    TMXTiledMap* map;
    
    HudLayer* hudLayer;
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    
    Vector<Unit*> units;
    Vector<Tower*> towers;
    int player_gold;
    Label* player_gold_label;
    bool setupTower;
    
};


#endif /* defined(__Game__GameScene__) */

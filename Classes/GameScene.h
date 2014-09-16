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
USING_NS_CC;

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
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
private:
    TMXTiledMap* map;
    
};


#endif /* defined(__Game__GameScene__) */

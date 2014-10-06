//
//  HudLayer.cpp
//  Game
//
//  Created by Natae on 2014. 10. 2..
//
//

#include "HudLayer.h"


// on "init" you need to initialize your instance
bool HudLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    _touchListener = EventListenerTouchOneByOne::create();
   // _touchListener->setSwallowTouches(true);
    
    _touchListener->onTouchBegan = CC_CALLBACK_2(HudLayer::onTouchBegan, this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(HudLayer::onTouchEnded, this);
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    
    dispatcher->addEventListenerWithSceneGraphPriority( _touchListener, this);


    menuButton = Sprite::create("button.png");
    menuButton->setPosition(Vec2(origin.x + menuButton->getContentSize().width/2, origin.y+ visibleSize.height - menuButton->getContentSize().height/2));
    this->addChild(menuButton);
    
        return true;
}
bool HudLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    Point touchPoint = touch->getLocation();
    
     log("Default Touch began : (%f %f)",touchPoint.x, touchPoint.y);
    //    prevPt = touchPoint;
    //    auto para = (ParallaxNode*)getChildByTag(10);
    //
    //    log("real position = (%f, %f)", touchPoint.x - para->getPositionX(),touchPoint.y - para->getPositionY() );
    //    Point index = positionToTileCoord(Point(touchPoint.x - para->getPositionX(), touchPoint.y - para->getPositionY()-16));
    //    log("index position = (%f, %f)", index.x, index.y);
    //
    //    auto sonic = Sprite::create("Player.png");
    //
    //    Point processed = PositionForTileCoord(Point(index.x, index.y));
    //    log("processed = (%f, %f)", processed.x, processed.y);
    //    sonic->setPosition(processed.x, processed.y + 16);
    //
    //    map->addChild(sonic, 3);
    //
    //    auto tile = Sprite::create("blue_tile.png");
    //    tile->setPosition(processed.x, processed.y);
    //    
    //    map->addChild(tile, 2);
    
    return true;
}

void HudLayer::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
}


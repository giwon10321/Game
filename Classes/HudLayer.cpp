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
    
    isInventory = false;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    _touchListener = EventListenerTouchOneByOne::create();
   // _touchListener->setSwallowTouches(true);
    
    _touchListener->onTouchBegan = CC_CALLBACK_2(HudLayer::onTouchBegan, this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(HudLayer::onTouchEnded, this);
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    
    dispatcher->addEventListenerWithSceneGraphPriority( _touchListener, this);


    menuButton = MenuItemImage::create("inven1.png", "inven2.png", CC_CALLBACK_1(HudLayer::event, this));
    menuButton->setPosition(Vec2(origin.x + menuButton->getContentSize().width/2, origin.y+ visibleSize.height - menuButton->getContentSize().height/2));
    
    auto menu = Menu::create(menuButton, NULL);
    menu->setPosition(Vec2::ZERO);
    
    this->addChild(menu, 1);
    
        return true;
}

void HudLayer::event(Ref* pSender)
{
  //  log("clicked");
    if(isInventory == false)
    {
        
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();

        auto label = Label::create();
        label->setString("abcss");
        label->setColor(Color3B(255, 0, 0));
        label->setSystemFontSize(40.0);
        
        auto menuItem = MenuItemLabel::create(label);
        
        auto menuItem2 = MenuItemImage::create("shop1.png", "shop2.png", CC_CALLBACK_1(HudLayer::callBack, this));
        
        
        auto menu = Menu::create();
        menu->addChild(menuItem2);

        menu->setPosition(Vec2(400, 150));
        
        _touchListener->setSwallowTouches(true);
        auto container = LayerColor::create(Color4B(255, 255, 0, 255));
        container->setPosition(Vec2::ZERO);
        container->setContentSize(visibleSize);
        container->setVisible(true);
        container->addChild(menu);
        
        scrollView = ScrollView::create(Size(800, 300), container);
        scrollView->setTag(4);
        scrollView->retain();
        scrollView->setBounceable(false);
        scrollView->setDirection(ScrollView::Direction::HORIZONTAL);
        scrollView->setPosition(200, 200);
        scrollView->setContentSize(Size(1000, 300));
        scrollView->setDelegate(this);
        this->addChild(scrollView, 5);
        
            
        isInventory = true;
    }
    else
    {
       // auto scrollView = getChildByTag(4);
        scrollView->removeFromParent();
        _touchListener->setSwallowTouches(false);

        isInventory = false;
    }
    return;
 
}
bool HudLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    Point touchPoint = touch->getLocation();
    
    log("Default Touch began : (%f %f)",touchPoint.x, touchPoint.y);
    
    if(isInventory == true)
    {
        
     //   auto scrollView = getChildByTag(4);
        auto range = scrollView->getBoundingBox();
        if(!range.containsPoint(touchPoint))
        {
            scrollView->removeFromParent();
            _touchListener->setSwallowTouches(false);
            isInventory = false;


        }
        
        
    }
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

void HudLayer::scrollViewDidScroll(ScrollView* view)
{
 //   auto contentOffset = view->getContentOffset();
    
//  log("scrollViewDidScroll: %f, %f", contentOffset.x, contentOffset.y);
}
void HudLayer::scrollViewDidZoom(ScrollView* view)
{}
void HudLayer::callBack(Ref* pSender)
{

}


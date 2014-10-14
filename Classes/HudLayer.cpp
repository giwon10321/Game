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
        
        window = LayerColor::create(Color4B(255, 0, 255, 0));
        window->setContentSize(Size(visibleSize.width/4*3, visibleSize.height/4*3));
        window->setPosition(140, 80);
    
        //auto rect = Rect(visibleSize.width/4*3-100, visibleSize.height/4*3-50, 100, 50);
        
        tab1 = LayerColor::create(Color4B(255, 255, 0, 255));
        tab1->setContentSize(Size(100, 50));
        tab1->setPosition(1, visibleSize.height/4*3-50);
        window->addChild(tab1);
        
        tab2 = LayerColor::create(Color4B(0, 255, 255, 255));
        tab2->setContentSize(Size(100, 50));
        tab2->setPosition(101, visibleSize.height/4*3-50);
        window->addChild(tab2);
        

        auto menu = Menu::create();

        for(int i=0;i<6;i++)
        {
            auto menuItem2 = MenuItemImage::create("shop1.png", "shop2.png", CC_CALLBACK_1(HudLayer::callBack, this));
            menuItem2->setPositionX(i*150-300);
            
            menu->addChild(menuItem2);
        }
        menu->setPosition(Vec2(400, 150));
        
        _touchListener->setSwallowTouches(true);
        auto container = LayerColor::create(Color4B(255, 255, 0, 255));
        container->setPosition(Vec2::ZERO);
        container->setContentSize(Size(800, 300));
        container->addChild(menu);
        
        scrollView1 = ScrollView::create(Size(visibleSize.width/4*3, visibleSize.height/4*3-50), container);
        scrollView1->setBounceable(false);
        scrollView1->setDirection(ScrollView::Direction::HORIZONTAL);
        scrollView1->setPosition(0, 0);
        scrollView1->setContentSize(Size(visibleSize.width/4*3+200, visibleSize.height/4*3-50));
        scrollView1->setDelegate(this);
        window->addChild(scrollView1, 5);
        
        auto container2 = LayerColor::create(Color4B(0, 255, 255, 255));
        container2->setPosition(Vec2::ZERO);
        container2->setContentSize(Size(800, 300));
    //    container2->addChild(menu);
        
        scrollView2 = ScrollView::create(Size(visibleSize.width/4*3, visibleSize.height/4*3-50), container2);
        scrollView2->setBounceable(false);
        scrollView2->setDirection(ScrollView::Direction::HORIZONTAL);
        scrollView2->setPosition(0, 0);
        scrollView2->setContentSize(Size(visibleSize.width/4*3+200, visibleSize.height/4*3-50));
        scrollView2->setDelegate(this);
        window->addChild(scrollView2, 4);
        this->addChild(window);
        
        isInventory = true;
    }
    else
    {
       // auto scrollView = getChildByTag(4);
       // scrollView->removeFromParent();
        window->removeFromParent();

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
     //   auto range = scrollView->getBoundingBox();
        auto range = window->getBoundingBox();

        if(!range.containsPoint(touchPoint))
        {
//            scrollView->removeFromParent();
            log("bye");
            window->removeFromParent();
            _touchListener->setSwallowTouches(false);
            isInventory = false;
            return true;

        }
        range = tab1->getBoundingBox();
        log("tab1 position: %f, %f", tab1->getPositionX(), tab2->getPositionY());
        range.setRect(range.getMinX()+140, range.getMinY()+80, range.size.width, range.size.height);
        if(range.containsPoint(touchPoint))
        {
            log("yellow touched");
            scrollView1->setVisible(true);
            scrollView2->setVisible(false);
        }
        range = tab2->getBoundingBox();
        range.setRect(range.getMinX()+140, range.getMinY()+80, range.size.width, range.size.height);
        if(range.containsPoint(touchPoint))
        {
            log("cyan touched");
            scrollView1->setVisible(false);
            scrollView2->setVisible(true);
            
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


//
//  HudLayer.cpp
//  Game
//
//  Created by Natae on 2014. 10. 2..
//
//

#include "HudLayer.h"
#include "Database.h"


// on "init" you need to initialize your instance
bool HudLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    isShop = false;

    _touchListener = EventListenerTouchOneByOne::create();
   // _touchListener->setSwallowTouches(true);
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	winSize = Size((visibleSize.width * 3)/4,(visibleSize.height*3)/4);
	listSize = Size(winSize.width, (winSize.height * 9)/10);
    tabSize = Size(listSize.width/numberOfTabs, (listSize.height * 1)/10);
	
	winPoint = Point((((visibleSize.width*1)/4)*1)/2, (((visibleSize.height*1)/4)*1)/2);
	listPoint = Point(0,0);
	
    _touchListener->onTouchBegan = CC_CALLBACK_2(HudLayer::onTouchBegan, this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(HudLayer::onTouchEnded, this);
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    
    dispatcher->addEventListenerWithSceneGraphPriority( _touchListener, this);


    menuButton = MenuItemImage::create("shop1.png", "shop2.png", CC_CALLBACK_1(HudLayer::event, this));
    menuButton->setPosition(Vec2(origin.x + menuButton->getContentSize().width/2, origin.y+ visibleSize.height - menuButton->getContentSize().height/2));
    auto menu = Menu::create(menuButton, NULL);
    menu->setPosition(Vec2::ZERO);
	
    this->addChild(menu, 1);
    
	return true;
}

void HudLayer::event(Ref* pSender)
{
  //  log("clicked");
    if(isShop == false)
    {
        window = LayerColor::create(Color4B(255, 0, 255, 0));
        window->setContentSize(winSize);
		
        window->setPosition(winPoint);
        
        tab1 = LayerColor::create(Color4B(255, 255, 0, 255));
        tab1->setContentSize(Size(tabSize.width, tabSize.height));
        tab1->setPosition(tabSize.width * 0, listSize.height);
        window->addChild(tab1);
        
        tab2 = LayerColor::create(Color4B(0, 255, 255, 255));
        tab2->setContentSize(Size(tabSize.width, tabSize.height));
        tab2->setPosition(tabSize.width * 1, listSize.height);
        window->addChild(tab2);
        
//        auto menu = Menu::create();
//        
        _touchListener->setSwallowTouches(true);
//        auto container = LayerColor::create(Color4B(255, 255, 0, 255));
//        container->setPosition(Vec2::ZERO);
//        container->setContentSize(Size(800, 300));
//        container->addChild(menu);
		
		shopTableView = ShopTableView::create();
		shopTableView->setPosition(0,0);
		window->addChild(shopTableView,5);
		
//        scrollView1 = ScrollView::create(Size(visibleSize.width/4*3, visibleSize.height/4*3-50), container);
//        scrollView1->setBounceable(false);
//        scrollView1->setDirection(ScrollView::Direction::HORIZONTAL);
//        scrollView1->setPosition(0, 0);
//        scrollView1->setContentSize(Size(300*4, visibleSize.height/4*3-50));
//        scrollView1->setDelegate(this);
//        window->addChild(scrollView1, 5);
		
        this->addChild(window);
        isShop = true;
    }
    else
    {
        window->removeFromParent();

        _touchListener->setSwallowTouches(false);

        isShop = false;
    }
    return;
 
}
bool HudLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    Point touchPoint = touch->getLocation();
    
    log("Default Touch began : (%f %f)",touchPoint.x, touchPoint.y);
    
//    if(isShop == true)
//    {
//        auto range = window->getBoundingBox();
//		
//        if(!range.containsPoint(touchPoint))
//        {
//            log("bye");
//            window->removeFromParent();
//            _touchListener->setSwallowTouches(false);
//            isShop = false;
//            return true;
//
//        }
//        range = tab1->getBoundingBox();
//        log("tab1 position: %f, %f", tab1->getPositionX(), tab2->getPositionY());
//        range.setRect(range.getMinX()+140, range.getMinY()+80, range.size.width, range.size.height);
//        if(range.containsPoint(touchPoint))
//        {
//            log("yellow touched");
//            scrollView1->setVisible(true);
//            scrollView2->setVisible(false);
//        }
//        range = tab2->getBoundingBox();
//        range.setRect(range.getMinX()+140, range.getMinY()+80, range.size.width, range.size.height);
//        if(range.containsPoint(touchPoint))
//        {
//            log("cyan touched");
//            scrollView1->setVisible(false);
//            scrollView2->setVisible(true);
//            
//        }
//    }
    return true;
}

void HudLayer::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{

}

//void HudLayer::scrollViewDidScroll(ScrollView* view)
//{
//
//}
//void HudLayer::scrollViewDidZoom(ScrollView* view)
//{
//	
//}
void HudLayer::callBack(Ref* pSender)
{

}


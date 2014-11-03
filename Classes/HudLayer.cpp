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
    isInventory = false;
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    _touchListener = EventListenerTouchOneByOne::create();
   // _touchListener->setSwallowTouches(true);
    
    _touchListener->onTouchBegan = CC_CALLBACK_2(HudLayer::onTouchBegan, this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(HudLayer::onTouchEnded, this);
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    
    dispatcher->addEventListenerWithSceneGraphPriority( _touchListener, this);


    auto shopButton = MenuItemImage::create("shop1.png", "shop2.png", CC_CALLBACK_1(HudLayer::shopEvent, this));
    shopButton->setPosition(Vec2(origin.x + shopButton->getContentSize().width/2, origin.y+ visibleSize.height - shopButton->getContentSize().height/2));
    
    auto invenButton = MenuItemImage::create("inven1.png", "inven2.png", CC_CALLBACK_1(HudLayer::invenEvent, this));
    invenButton->setPosition(Vec2(origin.x + 4*invenButton->getContentSize().width/2, origin.y+ visibleSize.height - invenButton->getContentSize().height/2));
    
    auto menu = Menu::create(shopButton, invenButton, NULL);
    menu->setPosition(Vec2::ZERO);
    
    this->addChild(menu, 1);
    
        return true;
}

void HudLayer::shopEvent(Ref* pSender)
{
  //  log("clicked");
    if(isShop == false)
    {
        if(isInventory == true)
        {
            invenWindow->removeFromParent();
            
            _touchListener->setSwallowTouches(false);
            
            isInventory = false;
        }
        Database *db = Database::getInstance();
        
        Json::Value shopList = db->getShopList();
    
        
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        
        shopWindow = LayerColor::create(Color4B(255, 0, 255, 0));
        shopWindow->setContentSize(Size(visibleSize.width/4*3, visibleSize.height/4*3));
        shopWindow->setPosition(140, 80);
        
        shopTab1 = LayerColor::create(Color4B(255, 255, 0, 255));
        shopTab1->setContentSize(Size(100, 50));
        shopTab1->setPosition(1, visibleSize.height/4*3-50);
        shopWindow->addChild(shopTab1);
        
        shopTab2 = LayerColor::create(Color4B(0, 255, 255, 255));
        shopTab2->setContentSize(Size(100, 50));
        shopTab2->setPosition(101, visibleSize.height/4*3-50);
        shopWindow->addChild(shopTab2);
        
        auto menu = Menu::create();

        
      //  menu->setPosition(Vec2(400, 150));
        
        _touchListener->setSwallowTouches(true);
        auto container = LayerColor::create(Color4B(255, 255, 0, 255));
        container->setPosition(Vec2::ZERO);
        container->setContentSize(Size(800, 300));
        container->addChild(menu);
        
        for(int i=0;i<4;i++)
        {
            //contents : image, hp,
            auto cell = Sprite::create("box.png");
            cell->setPosition(Vec2(i*300+150, 150+130));
            
            auto buyButton = MenuItemImage::create("button.png", "button2.png", CC_CALLBACK_1(HudLayer::purchased, this));
            buyButton->setName(shopList["towers"][i]["name"].asString());
            
            auto menu = Menu::create(buyButton, NULL);
            menu->setPosition(Vec2(150, 50));
            
            auto label = Label::create();
            std::string information = "Type: "+shopList["towers"][i]["towerType"].asString()+"\nClass: "+shopList["towers"][i]["className"].asString()+"\nName: "+shopList["towers"][i]["name"].asString()+"\nPrice: "+shopList["towers"][i]["price"].asString();
            
            label->setString(information);
            label->setSystemFontSize(20);
            label->setColor(Color3B(0, 0, 0));
            label->setPosition(Vec2(150, 150));

         //   cell->setName(shopList["towers"][i]["name"].asString());
            cell->addChild(menu);
            cell->addChild(label);
            
            /*
             auto menuItem3 = MenuItemImage::create("box.png", "box.png", CC_CALLBACK_1(HudLayer::callBack, this));
             menuItem3->setPositionX(i*300-250);
             menuItem3->setPositionY(130);
             */
            container->addChild(cell);
        }
        shopView1 = ScrollView::create(Size(visibleSize.width/4*3, visibleSize.height/4*3-50), container);
        shopView1->setBounceable(false);
        shopView1->setDirection(ScrollView::Direction::HORIZONTAL);
        shopView1->setPosition(0, 0);
        shopView1->setContentSize(Size(300*4, visibleSize.height/4*3-50));
        shopView1->setDelegate(this);
        shopWindow->addChild(shopView1, 5);
        
        auto container2 = LayerColor::create(Color4B(0, 255, 255, 255));
        container2->setPosition(Vec2::ZERO);
        container2->setContentSize(Size(800, 300));
    //    container2->addChild(menu);
        

        shopView2 = ScrollView::create(Size(visibleSize.width/4*3, visibleSize.height/4*3-50), container2);
        shopView2->setBounceable(false);
        shopView2->setDirection(ScrollView::Direction::HORIZONTAL);
        shopView2->setPosition(0, 0);
        shopView2->setContentSize(Size(visibleSize.width/4*3+200, visibleSize.height/4*3-50));
        shopView2->setDelegate(this);
        shopWindow->addChild(shopView2, 4);
        this->addChild(shopWindow);
        
        isShop = true;
    }
    else
    {
       // auto scrollView = getChildByTag(4);
       // scrollView->removeFromParent();
        shopWindow->removeFromParent();

        _touchListener->setSwallowTouches(false);

        isShop = false;
    }
    return;
 
}

void HudLayer::invenEvent(Ref* pSender)
{
    if(isInventory == false)
    {
        if(isShop == true)
        {
            shopWindow->removeFromParent();
            
            _touchListener->setSwallowTouches(false);
            
            isShop = false;
        }
        Database *db = Database::getInstance();
        
        Json::Value shopList = db->getShopList();
        
        
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        
        invenWindow = LayerColor::create(Color4B(255, 0, 255, 0));
        invenWindow->setContentSize(Size(visibleSize.width/4*3, visibleSize.height/4*3));
        invenWindow->setPosition(140, 80);
        
        invenTab1 = LayerColor::create(Color4B(123, 123, 0, 255));
        invenTab1->setContentSize(Size(100, 50));
        invenTab1->setPosition(1, visibleSize.height/4*3-50);
        invenWindow->addChild(invenTab1);
        
        invenTab2 = LayerColor::create(Color4B(0, 123, 123, 255));
        invenTab2->setContentSize(Size(100, 50));
        invenTab2->setPosition(101, visibleSize.height/4*3-50);
        invenWindow->addChild(invenTab2);
        
        auto menu = Menu::create();
        
        
        //  menu->setPosition(Vec2(400, 150));
        
        _touchListener->setSwallowTouches(true);
        auto container = LayerColor::create(Color4B(123, 123, 0, 255));
        container->setPosition(Vec2::ZERO);
        container->setContentSize(Size(800, 300));
        container->addChild(menu);
        
        invenView1 = ScrollView::create(Size(visibleSize.width/4*3, visibleSize.height/4*3-50), container);
        invenView1->setBounceable(false);
        invenView1->setDirection(ScrollView::Direction::HORIZONTAL);
        invenView1->setPosition(0, 0);
        invenView1->setContentSize(Size(300*4, visibleSize.height/4*3-50));
        invenView1->setDelegate(this);
        invenWindow->addChild(invenView1, 5);
        
        auto container2 = LayerColor::create(Color4B(0, 123, 123, 255));
        container2->setPosition(Vec2::ZERO);
        container2->setContentSize(Size(800, 300));
        //    container2->addChild(menu);
        
        
        invenView2 = ScrollView::create(Size(visibleSize.width/4*3, visibleSize.height/4*3-50), container2);
        invenView2->setBounceable(false);
        invenView2->setDirection(ScrollView::Direction::HORIZONTAL);
        invenView2->setPosition(0, 0);
        invenView2->setContentSize(Size(visibleSize.width/4*3+200, visibleSize.height/4*3-50));
        invenView2->setDelegate(this);
        invenWindow->addChild(invenView2, 4);
        this->addChild(invenWindow);
        
        isInventory = true;
    }
    else
    {
        // auto scrollView = getChildByTag(4);
        // scrollView->removeFromParent();
        invenWindow->removeFromParent();
        
        _touchListener->setSwallowTouches(false);
        
        isInventory = false;
    }
    return;
}
bool HudLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    Point touchPoint = touch->getLocation();
    
    log("Default Touch began : (%f %f)",touchPoint.x, touchPoint.y);
    
    if(isShop == true)
    {
        
     //   auto scrollView = getChildByTag(4);
        auto range = shopWindow->getBoundingBox();

        if(!range.containsPoint(touchPoint))
        {
//            scrollView->removeFromParent();
            log("bye");
            shopWindow->removeFromParent();
            _touchListener->setSwallowTouches(false);
            isShop = false;
            return true;

        }
        range = shopTab1->getBoundingBox();
   //     log("tab1 position: %f, %f", tab1->getPositionX(), tab2->getPositionY());
        range.setRect(range.getMinX()+140, range.getMinY()+80, range.size.width, range.size.height);
        if(range.containsPoint(touchPoint))
        {
            log("yellow touched");
            shopView1->setVisible(true);
            shopView2->setVisible(false);
        }
        range = shopTab2->getBoundingBox();
        range.setRect(range.getMinX()+140, range.getMinY()+80, range.size.width, range.size.height);
        if(range.containsPoint(touchPoint))
        {
            log("cyan touched");
            shopView1->setVisible(false);
            shopView2->setVisible(true);
            
        }
    }
    if(isInventory == true)
    {
        auto range = invenWindow->getBoundingBox();
        if(!range.containsPoint(touchPoint))
        {
            //            scrollView->removeFromParent();
            log("bye");
            invenWindow->removeFromParent();
            _touchListener->setSwallowTouches(false);
            isInventory = false;
            return true;
            
        }
        range = invenTab1->getBoundingBox();
        //     log("tab1 position: %f, %f", tab1->getPositionX(), tab2->getPositionY());
        range.setRect(range.getMinX()+140, range.getMinY()+80, range.size.width, range.size.height);
        if(range.containsPoint(touchPoint))
        {
            log("dark yellow touched");
            invenView1->setVisible(true);
            invenView2->setVisible(false);
        }
        range = invenTab2->getBoundingBox();
        range.setRect(range.getMinX()+140, range.getMinY()+80, range.size.width, range.size.height);
        if(range.containsPoint(touchPoint))
        {
            log("dark cyan touched");
            invenView1->setVisible(false);
            invenView2->setVisible(true);
            
        }

    }
    
    
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
void HudLayer::purchased(Ref* pSender)
{
    Database *db = Database::getInstance();
    
    Json::Value shopList = db->getShopList();
 
    auto touched = (MenuItemImage*)pSender;
    
    log("%s is purchased.", touched->getName().c_str());
}


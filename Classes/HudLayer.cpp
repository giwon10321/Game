//
//  HudLayer.cpp
//  Game
//
//  Created by Natae on 2014. 10. 2..
//
//

#include "HudLayer.h"
#include "Database.h"
#include "GameScene.h"


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
            // if inven is opened, then close
            invenWindow->removeFromParent();
            _touchListener->setSwallowTouches(false);
            isInventory = false;
        }
        // DB init
        Database *db = Database::getInstance();
        
        Json::Value shopList = db->getShopList();
        
        // disable touches without current layer
        _touchListener->setSwallowTouches(true);
        
        isShop = true;
        
        // get entire window size
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        
        // shopWindow init
        shopWindow = LayerColor::create(Color4B(255, 0, 255, 0));
        shopWindow->setContentSize(Size(visibleSize.width/4*3, visibleSize.height/4*3));
        shopWindow->setPosition(visibleSize.width/8, visibleSize.height/8); //140, 80
        
        // shopTab1 init
        shopTab1 = LayerColor::create(Color4B(255, 255, 0, 255));
        shopTab1->setContentSize(Size(100, 50));
        shopTab1->setPosition(1, visibleSize.height/4*3-shopTab1->getContentSize().height);
        shopWindow->addChild(shopTab1);
        
        // shopTab2 init
        shopTab2 = LayerColor::create(Color4B(0, 255, 255, 255));
        shopTab2->setContentSize(Size(100, 50));
        shopTab2->setPosition(1+shopTab1->getContentSize().width, visibleSize.height/4*3-shopTab1->getContentSize().height);
        shopWindow->addChild(shopTab2);
        
        // temp container for scrollView
        auto container = LayerColor::create(Color4B(255, 255, 0, 255));
        container->setPosition(Vec2::ZERO);
        container->setContentSize(Size(300*4, visibleSize.height/4*3-shopTab1->getContentSize().height));
        
        for(int i=0;i<shopList["towers"].size();i++)
        {
            // fill contents
            auto cell = Sprite::create("box.png");
            cell->setPosition(Vec2(i*cell->getContentSize().width+cell->getContentSize().width/2, cell->getContentSize().height/2));
          //  cell->setPosition(Vec2(i*cell->getContentSize().width, 0));
            
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

            // cell->setName(shopList["towers"][i]["name"].asString());
            cell->addChild(menu);
            cell->addChild(label);
            
            container->addChild(cell);
        }
        
        // shopTab1 scrollView init
        shopView1 = ScrollView::create(Size(visibleSize.width/4*3, visibleSize.height/4*3-shopTab1->getContentSize().height), container);
        shopView1->setBounceable(false);
        shopView1->setDirection(ScrollView::Direction::HORIZONTAL);
        shopView1->setPosition(0, 0);
        shopView1->setContentSize(Size(300*shopList["towers"].size(), visibleSize.height/4*3-shopTab1->getContentSize().height));
        shopView1->setDelegate(this);
        shopWindow->addChild(shopView1, 5);
        
        // temp container for scrollView
        auto container2 = LayerColor::create(Color4B(0, 255, 255, 255));
        container2->setPosition(Vec2::ZERO);
        
        
        // shopTab2 scrollView init
        shopView2 = ScrollView::create(Size(visibleSize.width/4*3, visibleSize.height/4*3-shopTab1->getContentSize().height), container2);
        shopView2->setBounceable(false);
        shopView2->setDirection(ScrollView::Direction::HORIZONTAL);
        shopView2->setPosition(0, 0);
        shopView2->setContentSize(Size(1000, visibleSize.height/4*3-shopTab1->getContentSize().height));
        shopView2->setDelegate(this);
        shopWindow->addChild(shopView2, 4);
        
        this->addChild(shopWindow);
        
    }
    else
    {
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
            // if shop is opened, then close
            shopWindow->removeFromParent();
            _touchListener->setSwallowTouches(false);
            isShop = false;
        }
        // DB init
        Database *db = Database::getInstance();
        
        Json::Value shopList = db->getShopList();

        // disable touches without current layer
        _touchListener->setSwallowTouches(true);
        
        isInventory = true;

        // get entire winodw size
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();

        // invenWindow init
        invenWindow = LayerColor::create(Color4B(255, 0, 255, 0));
        invenWindow->setContentSize(Size(visibleSize.width/4*3, visibleSize.height/4*3));
        invenWindow->setPosition(visibleSize.width/8, visibleSize.height/8);
        
        // invenTab1 init
        invenTab1 = LayerColor::create(Color4B(123, 123, 0, 255));
        invenTab1->setContentSize(Size(100, 50));
        invenTab1->setPosition(1, visibleSize.height/4*3-invenTab1->getContentSize().height);
        invenWindow->addChild(invenTab1);
        
        // invenTab2 init
        invenTab2 = LayerColor::create(Color4B(0, 123, 123, 255));
        invenTab2->setContentSize(Size(100, 50));
        invenTab2->setPosition(1+invenTab1->getContentSize().width, visibleSize.height/4*3-invenTab1->getContentSize().height);
        invenWindow->addChild(invenTab2);
        
        // temp container for scrollView
        auto container = LayerColor::create(Color4B(123, 123, 0, 255));
        container->setPosition(Vec2::ZERO);

        // invenTab1 scrollView init
        invenView1 = ScrollView::create(Size(visibleSize.width/4*3, visibleSize.height/4*3-invenTab1->getContentSize().height), container);
        invenView1->setBounceable(false);
        invenView1->setDirection(ScrollView::Direction::HORIZONTAL);
        invenView1->setPosition(0, 0);
        invenView1->setContentSize(Size(300*4, visibleSize.height/4*3-invenTab1->getContentSize().height));
        invenView1->setDelegate(this);
        invenWindow->addChild(invenView1, 5);
        
        // temp container for scrollView
        auto container2 = LayerColor::create(Color4B(0, 123, 123, 255));
        container2->setPosition(Vec2::ZERO);
        
        // invenTab2 scrollView init
        invenView2 = ScrollView::create(Size(visibleSize.width/4*3, visibleSize.height/4*3-invenTab1->getContentSize().height), container2);
        invenView2->setBounceable(false);
        invenView2->setDirection(ScrollView::Direction::HORIZONTAL);
        invenView2->setPosition(0, 0);
        invenView2->setContentSize(Size(visibleSize.width/4*3+200, visibleSize.height/4*3-invenTab1->getContentSize().height));
        invenView2->setDelegate(this);
        invenWindow->addChild(invenView2, 4);
        
        this->addChild(invenWindow);
    }
    else
    {
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
    
    // get entire winodw size
    Size visibleSize = Director::getInstance()->getVisibleSize();

    if(isShop == true)
    {
        // if outside is clicked, close shopWindow
        auto range = shopWindow->getBoundingBox();

        if(!range.containsPoint(touchPoint))
        {
            log("bye");
            shopWindow->removeFromParent();
            _touchListener->setSwallowTouches(false);
            isShop = false;
            return true;
        }
        // if tab is clicked, swap ohter container
        range = shopTab1->getBoundingBox();
        range.setRect(range.getMinX()+visibleSize.width/8, range.getMinY()+visibleSize.height/8, range.size.width, range.size.height);
        if(range.containsPoint(touchPoint))
        {
            log("yellow touched");
            shopView1->setVisible(true);
            shopView2->setVisible(false);
        }
        range = shopTab2->getBoundingBox();
        range.setRect(range.getMinX()+visibleSize.width/8, range.getMinY()+visibleSize.height/8, range.size.width, range.size.height);
        if(range.containsPoint(touchPoint))
        {
            log("cyan touched");
            shopView1->setVisible(false);
            shopView2->setVisible(true);
            
        }
    }
    
    if(isInventory == true)
    {
        // if outside is clicked, close window
        auto range = invenWindow->getBoundingBox();
        if(!range.containsPoint(touchPoint))
        {
            log("bye");
            invenWindow->removeFromParent();
            _touchListener->setSwallowTouches(false);
            isInventory = false;
            return true;
        }
        
        // if tab is clicked, swap other container
        range = invenTab1->getBoundingBox();
        range.setRect(range.getMinX()+visibleSize.width/8, range.getMinY()+visibleSize.height/8, range.size.width, range.size.height);
        if(range.containsPoint(touchPoint))
        {
            log("dark yellow touched");
            invenView1->setVisible(true);
            invenView2->setVisible(false);
        }
        range = invenTab2->getBoundingBox();
        range.setRect(range.getMinX()+visibleSize.width/8, range.getMinY()+visibleSize.height/8, range.size.width, range.size.height);
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
    // DB init
    Database *db = Database::getInstance();
    
    Json::Value shopList = db->getShopList();
 
    // get selector
    auto touched = (MenuItemImage*)pSender;
    
    // get other layer
    auto gameLayer = (GameScene*)(this->getParent()->getChildByTag(101));
    
    gameLayer->player_gold -= 10;
    
    char buf[100];
    sprintf(buf,"Gold: %d", gameLayer->player_gold);
    gameLayer->player_gold_label->setString(buf);
    
    log("%s is purchased.", touched->getName().c_str());
}


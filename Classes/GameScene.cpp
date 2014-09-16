//
//  GameScene.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "GameScene.h"
#include "NormalTower.h"
#include "Weapon.h"


Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameScene::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    _touchListener = EventListenerTouchOneByOne::create();
    _touchListener->setSwallowTouches(true);
    
    _touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    
    EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
    
    dispatcher->addEventListenerWithSceneGraphPriority( _touchListener, this);
    
    map = TMXTiledMap::create("test.tmx");
    
    auto point = PositionForTileCoord(Point(0,0));
    log("coord (0, 0) is (%f, %f)", point.x, point.y);
    
    auto label = LabelTTF::create("Hello World", "Arial", 15);
    label->setPosition(point.x, point.y);
    
    char buf[100];
    sprintf(buf,"%f,%f", map->getTileSize().width, map->getTileSize().height);
    label->setString(buf);

    auto paraNode = ParallaxNode::create();
    
    paraNode->setTag(10);
    
    paraNode->addChild(map, 1, Vec2(1.0, 1.0), Vec2(0.0, 0.0));
    
    this->addChild(paraNode, 1);

//    auto towerSprite = Sprite::create("tower.png");
//    Point towerPosition = PositionForTileCoord(Point(6,5));
//    towerSprite->setPosition(towerPosition);
//    
//    auto weaponSprite = Sprite::create("arrow.png");
//    Weapon arrow = Weapon(weaponSprite, TYPE1, 100.0f, 0.1f);
//    
//    NormalTower attackNormalTower(towerSprite, TYPE1, ARROW_NOMARL, 100.0f, 100, arrow);
//    map->addChild(attackNormalTower.body);
//    attackNormalTower.Attack(PositionForTileCoord(Point(12,0)),map);
    
//    Point p1 = Point(200,-100);
//    log("radian angle : %f",p1.getAngle(Point(200,200)));
//    log("angle %f",CC_RADIANS_TO_DEGREES(p1.getAngle()));
    
    return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    return true;
}

void GameScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
    Point diff = touch->getDelta();
    auto para = (ParallaxNode*)getChildByTag(10);
    Point pt = para->getPosition();
    pt.x = pt.x + diff.x;
    pt.y = pt.y + diff.y;
    para->setPosition(pt);
}

void GameScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
    
}

Point GameScene::PositionForTileCoord(Point coord)
{
    //x좌표 = (타일맵의 가로갯수 * 타일의 가로크기의 반) + ((타일 x인덱스 – 타일 y인덱스)*타일의 가로크기의 반)
    int x =(map->getMapSize().width*map->getTileSize().width/2)+((coord.x -coord.y)*map->getTileSize().width/2);
    
    //y좌표 = (타일맵의 세로갯수 * 타일의 세로크기) – ((타일의 x인덱스 + 타일의 y인덱스)*타일의 세로크기의 반) – 타일의 세로크기
    int y =(map->getMapSize().height*map->getTileSize().height) - ((coord.x +coord.y)*map->getTileSize().height/2);
    
    return Vec2(x,y);
}

Point GameScene::positionToTileCoord(Point position)
{
    position.x = position.x;
    position.y = position.y;
    int y = (((position.y/TILEHEIGHT) + (position.x - (MAPWIDTH*TILEWIDTH/2)) / TILEWIDTH)-MAPWIDTH)* (-1);
    int x = (((position.y/TILEHEIGHT) - (position.x - (MAPWIDTH*TILEWIDTH/2)) / TILEWIDTH)-MAPWIDTH)* (-1);
    // x--;
    // y--;
    return Vec2(x,y);
}

void GameScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

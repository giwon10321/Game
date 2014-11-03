//
//  GameScene.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "GameScene.h"
#include "NormalTower.h"
#include "Database.h"

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
        // add layer as a child to scene
    scene->addChild(layer);
    
    auto hudLayer = HudLayer::create();
    hudLayer->setTag(100);
    scene->addChild(hudLayer);
    
    
    
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
    
    Database *db = Database::getInstance();
//	db->addNormalTowerToInventory();
	
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
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    
    dispatcher->addEventListenerWithSceneGraphPriority( _touchListener, this);
    
    map = TMXTiledMap::create("test.tmx");
    map->setScale(1.5f);
    
    
    player_gold_label = Label::create();
    
    char buf[100];
    sprintf(buf,"Gold: %d", player_gold);
    player_gold_label->setSystemFontSize(20);
    player_gold_label->setString(buf);
    player_gold_label->setPosition(Vec2(origin.x + visibleSize.width - player_gold_label->getContentSize().width/2 ,                                        origin.y + visibleSize.height - player_gold_label->getContentSize().height/2));
    this->addChild(player_gold_label, 10);

    auto unit = new Unit(this,PositionForTileCoord(Point(10,12)),db->getUnitList()[0]);
    auto unit1 = new Unit(this,PositionForTileCoord(Point(1,12)),db->getUnitList()[0]);
    auto unit2 = new Unit(this,PositionForTileCoord(Point(10,1)),db->getUnitList()[0]);

    units.pushBack(unit);
    units.pushBack(unit1);
    units.pushBack(unit2);

//	std::cout<<db->getShopList()["towers"][0]<<std::endl;
	auto towerData = db->addIdToObject(db->getShopList()["towers"][0]);
//	std::cout<<towerData<<std::endl;
    auto normalTower = new NormalTower(this,PositionForTileCoord(Point(6, 6)),towerData);
    towers.pushBack(normalTower);

//	db->saveToObject(std::vector<std::string>{"inventory","towers"}, normalTower->info);
//	std::cout<<db->getUserInventory()<<std::endl;
//	normalTower->info["attackRange"] = 400;
//	std::cout<<normalTower->info<<std::endl;
//	db->update(std::vector<std::string>{"inventory","towers"}, "id", normalTower->info["id"].asString(), normalTower->info);
//	db->remove(std::vector<std::string>{"inventory","towers"}, "id", normalTower->info["id"].asString());
//	std::cout<<db->getUserInventory()<<std::endl;
	
	
	auto paraNode = ParallaxNode::create();
    
    paraNode->setTag(10);
    
    paraNode->addChild(map, 1, Vec2(1.0, 1.0), Vec2(0.0, 0.0));
    
    this->addChild(paraNode, 1);
    
//    this->schedule(schedule_selector(GameScene::summonEnemy), 1.0f);
//    this->schedule(schedule_selector(GameScene::update), 1.0f);
    
    
    //  auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    //  label->setPosition(Vec2(origin.x + visibleSize.width/2,
    //                       origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    //  this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    //   auto sprite = Sprite::create("HelloWorld.png");
    
    // position the sprite on the center of the screen
    //    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    //    this->addChild(sprite, 0);
    
    return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    Point touchPoint = touch->getLocation();
    
    // log("Default Touch began : (%f %f)",touchPoint.x, touchPoint.y);
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

void GameScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
    Point diff = touch->getDelta();
    auto para = (ParallaxNode*)getChildByTag(10);
    Point pt = para->getPosition();
    pt.x = pt.x + diff.x;
    pt.y = pt.y + diff.y;
    para->setPosition(pt);
    
    // blue tile following cursor
    /*
    auto para = (ParallaxNode*)getChildByTag(10);
    auto processed = PositionForTileCoord(positionToTileCoord(Point(touchPoint.x - para->getPositionX(),touchPoint.y - para->getPositionY())));
    
    auto blue_tile = Sprite::create("blue_tile.png");
    blue_tile->setPosition(processed.x, processed.y+16);
    blue_tile->setTag(1);
    
    map->addChild(blue_tile, 3);
    */
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

void GameScene::update(float f)
{
    // check collisions
//    list<Unit*>::iterator _iterator;
//    for(_iterator = units.begin(); _iterator != units.end(); ++_iterator){
//        cout<<"address in update : "<<*_iterator<<endl;
//    }
//    std::list<Tower*>::iterator iterator;
//    Unit* target = NULL;
//    
//    for(iterator = towers.begin(); iterator != towers.end(); ++iterator){
//        (*iterator)->getNearestObject(units,target);
//        (*iterator)->target = target;
//        (*iterator)->Attack(target, map);
//    }
}

void checkCollision(int flag)
{
    if(flag == 0) // tower vs. unit weapon
    {
        
    }
    else          // unit vs. tower weapon
    {
        
    }
}
void GameScene::summonEnemy(float f)
{
//    if(units.size() >= 9)
//        this->unschedule(schedule_selector(GameScene::summonEnemy));
//    srand((unsigned int)time(NULL));
//    Point object_postion = PositionForTileCoord(Point(rand()%15, rand()%15));
    
//    auto* unit = new Unit(Sprite::create("Player.png"), TYPE1 , 50, weapon);
    
//    unit->setPosition(Point(object_postion.x, object_postion.y+16));
//    
//    map->addChild(unit->body, 5);
//    units.push_front(unit);
}
void GameScene::awardGold(int gold)
{
    log("awardGold");
    player_gold = player_gold + gold;
    
}
bool GameScene::circle(Point circlePoint, float radius, Point circlePointTwo, float radiusTwo){
    float xdif = circlePoint.x - circlePointTwo.x;
    float ydif = circlePoint.y - circlePointTwo.y;
    
    float distance = sqrt(xdif*xdif+ydif*ydif);
    
    if(distance <= radius+radiusTwo)
        return true;
    
    return false;
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

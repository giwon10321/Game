//
//  HudLayer.h
//  Game
//
//  Created by Natae on 2014. 10. 2..
//
//

#ifndef __Game__HudLayer__
#define __Game__HudLayer__

#include "cocos2d.h"
#include "ShopTableView.h"
#include <iostream>
#include "cocos-ext.h"
#include "sqlite3.h"
USING_NS_CC;
USING_NS_CC_EXT;

class HudLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    cocos2d::EventListenerTouchOneByOne* _touchListener;
    
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

    void event(Ref* pSender);
    
    void callBack(Ref* pSender);
    
    int score;
    // implement the "static create()" method manually
    CREATE_FUNC(HudLayer);
private:
    cocos2d::Label* label;
    MenuItemImage* menuButton;
    bool isInventory;
    bool isShop;
    ScrollView* scrollView1;
    ScrollView* scrollView2;
    LayerColor* window;
    LayerColor* tab1;
    LayerColor* tab2;
	
	const int numberOfTabs = 3;
	
	Size winSize;
	Size listSize;
	Size tabSize;
	
	Point winPoint;
	Point listPoint;
	Point tabPoint;
	
	ShopTableView* shopTableView;
};

#endif /* defined(__Game__HudLayer__) */

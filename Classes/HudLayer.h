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
#include <iostream>
USING_NS_CC;

class HudLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    cocos2d::EventListenerTouchOneByOne* _touchListener;
    
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

    
    // implement the "static create()" method manually
    CREATE_FUNC(HudLayer);
private:
    cocos2d::Label* label;
    Sprite* menuButton;
    
    
    
    
};

#endif /* defined(__Game__HudLayer__) */

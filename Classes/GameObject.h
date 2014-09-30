//
//  GameObject.h
//  Game
//
//  Created by Natae on 2014. 9. 5..
//
//

#ifndef __Game__GameObject__
#define __Game__GameObject__

#include "cocos2d.h"
#include <iostream>

USING_NS_CC;
using namespace std;

enum ALLIANCE
{
    TYPE1 = 0,
    TYPE2,
    TYPE3
};

class GameObject : public Node
{
public:
    GameObject(Layer* _gameLayer, Point position, ALLIANCE _allianceType);
    GameObject* initGameObject(Layer* _gameLayer, Point position, ALLIANCE _allianceType);
    void setPosition(Point pos);
    Point getPosition();
    virtual ~GameObject();
    
    template <typename T> void getNearestObject(list<T*> &objects, T*& target){
        Point thisPosition = this->getPosition();
        
        float nearestDistance = -1.0f;
        typename list<T*>::iterator iterator;
        for(iterator = objects.begin(); iterator != objects.end(); ++iterator){
            float distance = thisPosition.getDistance(((GameObject*)(*iterator))->getPosition());
            if(nearestDistance == -1.0f || distance < nearestDistance){
                nearestDistance = distance;
                target = *iterator;
                cout<<target<<endl;
            }
        }
    }

    Sprite* body;
    ALLIANCE eAllianceType;
    Layer* gameLayer;
    Point position;
    
};
#endif /* defined(__Game__GameObject__) */

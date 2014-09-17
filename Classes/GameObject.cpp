//
//  GameObject.cpp
//  Game
//
//  Created by Natae on 2014. 9. 5..
//
//

#include "GameObject.h"

GameObject::GameObject(Sprite* _body, ALLIANCE _allianceType) : body(_body), eAllianceType(_allianceType)
{
    
}

GameObject::~GameObject()
{
    
}

void GameObject::setPosition(Point pos)
{
    body->setPosition(pos);
}

Point GameObject::getPosition()
{
    return body->getPosition();
}

//GameObject& GameObject::getNearestSprite(std::list<GameObject>& objects)
//{
//    GameObject nearestObject = GameObject(NULL,TYPE1);
//    Point position = this->getPosition();
//    
//    float nearestDistance = -1.0f;
//    std::list<GameObject>::iterator iterator;
//    for(iterator = objects.begin(); iterator != objects.end(); ++iterator){
//        float distance = position.getDistance(iterator->getPosition());
//        if(nearestDistance == -1.0f || distance < nearestDistance){
//            nearestDistance = distance;
//            nearestObject = *iterator;
//        }
//    }
//    return nearestObject;
//}
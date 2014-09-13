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
//
//  GameObject.cpp
//  Game
//
//  Created by Natae on 2014. 9. 5..
//
//

#include "GameObject.h"

GameObject::GameObject(Layer* _gameLayer, Point _position, ALLIANCE _allianceType) : eAllianceType(_allianceType)
{
    this->initGameObject(_gameLayer, _position, _allianceType);
}

GameObject::~GameObject()
{
    
}

GameObject* GameObject::initGameObject(Layer* _gameLayer, Point _position, ALLIANCE _allianceType)
{
    Node::onEnter();
    this->gameLayer = _gameLayer;
    this->position = _position;
    this->eAllianceType = _allianceType;
    
    return this;
}

void GameObject::setPosition(Point pos)
{
    body->setPosition(pos);
}

Point GameObject::getPosition()
{
    return body->getPosition();
}
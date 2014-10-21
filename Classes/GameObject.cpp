//
//  GameObject.cpp
//  Game
//
//  Created by Natae on 2014. 9. 5..
//
//

#include "GameObject.h"

GameObject::GameObject(GameScene* gameLayer, Point position, Json::Value info) : gameLayer(gameLayer), info(info)
{
    this->initGameObject(position);
}

GameObject::~GameObject()
{
    
}

GameObject* GameObject::initGameObject(Point position)
{
    this->onEnter();
    this->setPosition(position);
    this->unsetTarget();
	
    return this;
}

bool GameObject::checkCollision(Point destination, float targetRadius)
{
    float distance = this->getPosition().getDistance(destination);
    if(distance <= this->attackRange + targetRadius){
        return true;
    }
    return false;
}

void GameObject::setTarget(GameObject *obj)
{
    this->target = nullptr;
    this->target = obj;
    this->attack();
    obj->getAttacked(this);
}

void GameObject::unsetTarget()
{
    if(this->target != nullptr){
        this->target = nullptr;
    }
}

void GameObject::getAttacked(GameObject *obj)
{
    this->attackBy.pushBack(obj);
}

void GameObject::getDamaged(float damage)
{
    this->virtualHP -= damage;
    if(this->virtualHP <= 0 ){
        this->stopScheduled();
    }
}

void GameObject::gotLostSight(GameObject* obj)
{
    this->attackBy.eraseObject(obj);
}

void GameObject::removeWeapon(cocos2d::Node *weapon)
{
    weapon->removeFromParentAndCleanup(true);
    if(this->target != nullptr){
        this->target->removeObject(this->damage);
    }
}

void GameObject::damageEnermy()
{
    this->target->getDamaged(this->damage);
}

void GameObject::stopShoot()
{
    this->unschedule(schedule_selector(GameObject::shootWeapon));
}

void GameObject::stopScheduled()
{
    for(auto enermy : this->attackBy){
        enermy->stopShoot();
    }
}


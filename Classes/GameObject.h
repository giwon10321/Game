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
#include "Database.h"

USING_NS_CC;
using namespace std;


class GameScene;
class GameObject : public Node
{
public:
    GameObject(GameScene* gameLayer, Point position, Json::Value info);
    GameObject* initGameObject(Point position);
    virtual ~GameObject();
    bool checkCollision(Point destination, float targetRadius);
	void saveInfo();
	
    virtual void setTarget(GameObject* obj);
    virtual void unsetTarget();
    virtual void getAttacked(GameObject* obj);
    virtual void getDamaged(float damage);
    virtual void gotLostSight(GameObject* obj);
    virtual void removeWeapon(Node* weapon);
    virtual void damageEnermy();
    virtual void stopShoot();
    virtual void stopScheduled();
    
    virtual void removeObject(float damage) = 0;
    virtual void shootWeapon(float attackRate) = 0;
    virtual void attack() = 0;
    
    Sprite* body;
    GameScene* gameLayer;
    GameObject* target;
    Vector<GameObject *> attackBy;

    float attackRange;
    float damage;
    float thisRadius;
    float currentHP;
    float virtualHP;
    float attackRatio;
    float attackSpeed;
    std::string weaponName;
	Json::Value info;
};
#endif /* defined(__Game__GameObject__) */

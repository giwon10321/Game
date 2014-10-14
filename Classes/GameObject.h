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
//#include "GameScene.h"
#include <iostream>

USING_NS_CC;
using namespace std;


class GameScene;
enum ALLIANCE
{
    TYPE1 = 0,
    TYPE2,
    TYPE3
};

class GameObject : public Node
{
public:
    GameObject(GameScene* _gameLayer, Point position, ALLIANCE _allianceType);
    GameObject* initGameObject(GameScene* _gameLayer, Point position, ALLIANCE _allianceType);
    virtual ~GameObject();
    
    void setPosition(Point pos);
    Point getPosition();
    bool checkCollision(Point destination, float targetRadius);
    
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
    ALLIANCE eAllianceType;
    GameScene* gameLayer;
    GameObject* target;
    Vector<GameObject *> attackBy;
    
    Point position;
    int attackRange;
    float damage;
    float thisRadius;
    float maxHP;
    float currentHP;
    float virtualHP;
};
#endif /* defined(__Game__GameObject__) */

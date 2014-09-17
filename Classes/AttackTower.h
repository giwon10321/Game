//
//  AttackTower.h
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#ifndef __Game__AttackTower__
#define __Game__AttackTower__

#include "cocos2d.h"
#include "GameObject.h"
#include "Tower.h"
#include "Weapon.h"

USING_NS_CC;

class AttackTower : public Tower
{
public :
    Weapon* weapon;
    
    AttackTower(Sprite* _body, ALLIANCE _allianceType,  TOWER_TYPE _towerType, float _HP, int _range, Weapon* _weapon);
    virtual ~AttackTower();
    void Attack(GameObject* target, TMXTiledMap* map);
};

#endif /* defined(__Game__AttackTower__) */

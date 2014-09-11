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
#include "Tower.h"
#include "Weapon.h"

USING_NS_CC;

class AttackTower : public Tower
{
public :
    AttackTower();
    virtual ~AttackTower();
    void Attack(Point destination);
};

#endif /* defined(__Game__AttackTower__) */

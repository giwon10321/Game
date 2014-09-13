//
//  SuperTower.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "SuperTower.h"

SuperTower::SuperTower(Sprite* _body, ALLIANCE _allianceType, TOWER_TYPE _towerType, float _HP, int _MP, int _range, const Weapon& _weapon):AttackTower(_body, _allianceType, _towerType, _HP, _range, _weapon)
{
    
}

SuperTower::~SuperTower()
{
    
}
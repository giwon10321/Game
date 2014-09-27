//
//  Unit.cpp
//  Game
//
//  Created by kwon giwon on 2014. 9. 5..
//
//

#include "Unit.h"

Unit::Unit(Layer* _gameLayer, Point _position, ALLIANCE _allianceType):GameObject(_gameLayer, _position, _allianceType)
{
    this->initUnit();
}

Unit::~Unit()
{
    
}

Unit* Unit::initUnit()
{
    this->body = Sprite::create("Player.png");
    return this;
}
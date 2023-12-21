//
//  key.cpp
//  hwk7
//
//  Created by Brandon Niese on 4/17/16.
//  Copyright © 2016 Brandon Niese. All rights reserved.
//

#include "monster.h"

monster::monster()
{
    existance =0;
    hp=0;
    attack=0;
    name="";
}

monster::monster(int exist, int health, int at, string nm)
{
    existance = exist;
    hp = health;
    attack = at;
    name = nm;
}

void monster::set_existance(int exist)
{
    existance = exist;
}

void monster::set_hp(int health)
{
    hp = health;
}

void monster::set_attack(int at)
{
    attack = at;
}

void monster::set_name(string nm)
{
    name = nm;
}

int monster::get_existance()
{
    return existance;
}

int monster::get_hp()
{
    return hp;
}

int monster::get_attack()
{
    return attack;
}

string monster::get_name()
{
    return name;
}

void monster::hit(int at)
{
    hp -= at;
}
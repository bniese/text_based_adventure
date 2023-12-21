//
//  player.cpp
//  hwk7
//
//  Created by Brandon Niese on 4/18/16.
//  Copyright © 2016 Brandon Niese. All rights reserved.
//

#include "player.h"

player::player()
{
    name = "";
    wallet = 0;
    keys = 0;
    health = 40;
    attack = 8;
    full_heal = 1;
    half_heal = 2;
}

void player::set_name(string nm)
{
    name = nm;
}

string player::get_name()
{
    return name;
}

double player::get_wallet()
{
    return wallet;
}

int player::get_keys()
{
    return keys;
}

int player::get_health()
{
    return health;
}

int player::get_attack()
{
    return attack;
}

int player::get_full_heal()
{
    return full_heal;
}

int player::get_half_heal()
{
    return half_heal;
}

void player::add_keys(int k)
{
    keys += k;
}

void player::add_money(double m)
{
    wallet += m;
}

void player::decrement_key()
{
    keys--;
}

void player::hit(int at)
{
    health -= at;
}

void player::heal(int heal)
{
    health += heal;
    if (health > 40) {
        health = 40;
    }
}

void player::decrement_f_heal()
{
    full_heal--;
}

void player::decrement_h_heal()
{
    half_heal--;
}
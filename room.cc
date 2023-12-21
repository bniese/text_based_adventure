//
//  room.cpp
//  hwk7
//
//  Created by Brandon Niese on 4/17/16.
//  Copyright © 2016 Brandon Niese. All rights reserved.
//

#include "room.h"

room::room(int rn, string desc, double mon, int k, vector<ex> dir, bool ex_game, monster monst)
{
    room_number = rn;
    description = desc;
    money = mon;
    keys = k;
    direction = dir;
    exit_game = ex_game;
    m = monst;
}

void room::set_exit(ex e)
{
    direction.push_back(e);
}

void room::set_key(int num)
{
    keys = num;
}

void room::set_mon(double mon)
{
    money = mon;
}

void room::set_exit_game(bool e_game)
{
    exit_game = e_game;
}

void room::set_descrip(string d)
{
    description = d;
}

string room::get_descrip()
{
    return description;
}

vector<ex> room::get_exit()
{
    return direction;
}

int room::get_keys()
{
    return keys;
}

double room::get_money()
{
    return money;
}

bool room::get_exit_game()
{
    return exit_game;
}

monster room::get_monster()
{
    return m;
}

void room::hit_monster(int at)
{
    m.hit(at);
}

void room::monster_exist(int x)
{
    m.set_existance(x);
}
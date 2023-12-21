//
//  exit.cpp
//  hwk7
//
//  Created by Brandon Niese on 4/17/16.
//  Copyright © 2016 Brandon Niese. All rights reserved.
//

#include "exit.h"

ex::ex(bool lock, int num, string dir)
{
    locked = lock;
    room_number = num;
    direction = dir;
}

void ex::set_lock(bool b)
{
    locked = b;
}

string ex::get_direction()
{
    return direction;
}

int ex::get_room_number()
{
    return room_number;
}

bool ex::get_lock()
{
    return locked;
}
//
//  room.hpp
//  hwk7
//
//  Created by Brandon Niese on 4/17/16.
//  Copyright © 2016 Brandon Niese. All rights reserved.
//
#ifndef ROOM
#define ROOM


#include "monster.h"
#include "exit.h"
#include <string>
#include <vector>

using namespace std;

class room
{
public:
    // constructors
    room(int rn, string desc, double mon, int k, vector<ex> dir, bool ex_game, monster monst);
    
    // setters
    void set_rn();
    void set_descrip(string d);
    void set_mon(double mon);
    void set_key(int num);
    void set_exit(ex e);
    void set_exit_game(bool e_game);
    
    // getters
    monster get_monster();
    bool get_exit_game();
    int get_keys();
    double get_money();
    string get_descrip();
    vector<ex> get_exit();
    
    // changers
    void hit_monster(int at);
    void monster_exist(int x);
private:
    int room_number;
    string description;
    double money;
    int keys;
    vector<ex> direction;
    bool exit_game;
    monster m;
};

#endif
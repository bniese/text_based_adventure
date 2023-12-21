//
//  player.hpp
//  hwk7
//
//  Created by Brandon Niese on 4/18/16.
//  Copyright © 2016 Brandon Niese. All rights reserved.
//
#ifndef PLAYER
#define PLAYER

#include <string>

using namespace std;

class player
{
public:
    // constructors
    player();
    
    // setters
    void set_name(string nm);
    
    // mutators
    void add_money(double m);
    void add_keys(int k);
    void decrement_key();
    void hit(int at);
    void heal(int heal);
    void decrement_f_heal();
    void decrement_h_heal();
    
    // accessors
    string get_name();
    double get_wallet();
    int get_keys();
    int get_health();
    int get_attack();
    int get_full_heal();
    int get_half_heal();
    
private:
    string name;
    double wallet;
    int keys;
    int health;
    int attack;
    int full_heal;
    int half_heal;
};

#endif
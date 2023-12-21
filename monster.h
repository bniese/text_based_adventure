//
//  key.hpp
//  hwk7
//
//  Created by Brandon Niese on 4/17/16.
//  Copyright © 2016 Brandon Niese. All rights reserved.
//
#ifndef MONSTER
#define MONSTER

#include <string>

using namespace std;

class monster
{
public:
    // constructors
    monster();
    monster(int exist, int health, int at, string nm);
    
    // setters
    void set_existance(int exist);
    void set_hp(int health);
    void set_attack(int at);
    void set_name(string nm);
    
    // getters
    int get_existance();
    int get_hp();
    int get_attack();
    string get_name();
    
    // changers
    void hit(int at);
    
    
private:
    int existance;
    int hp;
    int attack;
    string name;
};

#endif
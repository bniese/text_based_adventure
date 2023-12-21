//
//  exit.hpp
//  hwk7
//
//  Created by Brandon Niese on 4/17/16.
//  Copyright © 2016 Brandon Niese. All rights reserved.
//
#ifndef EX
#define EX


#include <string>

using namespace std;

class ex
{
public:
    // constructors
    ex();
    ex(bool lock, int num, string dir);
    
    // setters
    void set_lock(bool b);
    void set_room();
    
    // getters
    bool get_lock();
    int get_room_number();
    string get_direction();
    

    
private:
    bool locked;
    int room_number;
    
    string direction;
    
};

#endif



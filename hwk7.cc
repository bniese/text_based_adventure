//*******************************************************************
//
// Program:		hwk7.cc
//
// Author:		Brandon Niese
// Email: 		bn738214@ohio.edu
//
// Lab Section: 	Max's Thursday Lab
//
// Description: 	This runs a file and reads it as a game to satisfy homework 7
//
// Date:		22 April 2016
//
//*******************************************************************

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "room.h"
#include "exit.h"
#include "monster.h"
#include "player.h"

using namespace std;



//******************************************************************
//
// Function:    get_world
//
// Purpose:     gets the file and opens it
//
// Parameters:  fin
//******************************************************************
void get_world(ifstream &fin);


//******************************************************************
//
// Function:    set_world
//
// Purpose:     generates the world and calls other functions to do it
//
// Parameters:  world, rooms
//
//******************************************************************
void set_world(ifstream &world, vector<room> &rooms);


//******************************************************************
//
// Function:    read_exit
//
// Purpose:     reads the exit portion of the infile
//
// Parameters:  world, rooms, room_index, e1
//
//******************************************************************
void read_exit(ifstream &world, vector<room> &rooms, int &room_index, vector<ex> &e1);


//******************************************************************
//
// Function:    read_one_exit
//
// Purpose:     reads one exit at a time
//
// Parameters:  world, rooms, room_index, e1
//
//******************************************************************
void read_one_exit(ifstream &world, vector<room> &rooms, int &room_index, vector<ex> &e1);


//******************************************************************
//
// Function:    is_locked
//
// Purpose:     checks if room is locked
//
// Parameters:  temp
//
//******************************************************************
bool is_locked(string temp);

//******************************************************************
//
// Function:    read_keys
//
// Purpose:     reads number of keys in a room from the file
//
// Parameters:  world, rooms, room_index, kys
//
//******************************************************************
void read_keys(ifstream &world, vector<room> &rooms, int &room_index, int &kys);


//******************************************************************
//
// Function:    read_money
//
// Purpose:     reads money in a room from file
//
// Parameters:  world, rooms, room_index, mon
//
//******************************************************************
void read_money(ifstream &world, vector<room> &rooms, int &room_index, double &mon);


//******************************************************************
//
// Function:    read_monster
//
// Purpose:     reads information for a monster from file
//
// Parameters:  world, rooms, room_index, monst
//
//******************************************************************
void read_monster(ifstream &world, vector<room> &rooms, int &room_index, monster &monst);


//******************************************************************
//
// Function:    read_exit_game
//
// Purpose:     reads if you can exit the whole game from the room
//
// Parameters:  world, rooms, room_index, ex_game
//
//******************************************************************
void read_exit_game(ifstream &world, vector<room> &rooms, int &room_index, bool &ex_game);


//******************************************************************
//
// Function:    read_description
//
// Purpose:     reads the rooms description from the file
//
// Parameters:  world, rooms, room_index, desc
//
//******************************************************************
void read_description(ifstream &world, vector<room> &rooms, int &room_index, string &desc);


//******************************************************************
//
// Function:    create_player
//
// Purpose:     creates the player and asks for there name
//
// Parameters:  p
//
//******************************************************************
void create_player(player &p);


//******************************************************************
//
// Function:    game_opening
//
// Purpose:     gives the openning speal
//
// Parameters:  p
//
//******************************************************************
void game_opening(player &p);


//******************************************************************
//
// Function:    play_game
//
// Purpose:     moves the player through the world
//
// Parameters:  rooms, p
//
//******************************************************************
void play_game(vector<room> &rooms, player &p);


//******************************************************************
//
// Function:    print_menu
//
// Purpose:     prints the main menu of the game where the player interacts
//
// Parameters:  rooms, p, room_index
//
//******************************************************************
void print_menu(vector<room> &rooms, player &p, int &room_index);


//******************************************************************
//
// Function:    menu_switch
//
// Purpose:     switchs through menu options based on choice
//
// Parameters:  choice, rooms, p, room_index
//
//******************************************************************
void menu_switch(string choice, vector<room> &rooms, player &p, int &room_index);


//******************************************************************
//
// Function:    do_go
//
// Purpose:     move room to room
//
// Parameters: rooms, p, room_index
//
//******************************************************************
void do_go(vector<room> &rooms, player &p, int &room_index);


//******************************************************************
//
// Function:    do_pick_up
//
// Purpose:     picks up stuff in the room
//
// Parameters:  rooms, p, room_index
//
//******************************************************************
void do_pick_up(vector<room> &rooms, player &p, int &room_index);


//******************************************************************
//
// Function:    do_inventory
//
// Purpose:     shows the inventory
//
// Parameters:  rooms, p, room_index
//
//******************************************************************
void do_inventory(vector<room> &rooms, player &p, int &room_index);


//******************************************************************
//
// Function:    do_leave
//
// Purpose:     sees if you can leave the game
//
// Parameters:  rooms, p, room_index
//
//******************************************************************
void do_leave(vector<room> &rooms, player &p, int &room_index);


//******************************************************************
//
// Function:    move_to_new_room
//
// Purpose:     moves to a new room
//
// Parameters:  rooms, p, room_index, dir
//
//******************************************************************
void move_to_new_room(vector<room> &rooms, player &p, int &room_index, string dir);


//******************************************************************
//
// Function:    unlock_door
//
// Purpose:     unlocks the door
//
// Parameters:  rooms, p, room_index, exit_index
//
//******************************************************************
void unlock_door(vector<room> &rooms, player &p, int &room_index, int exit_index);

//******************************************************************
//
// Function:    fight_monster
//
// Purpose:     fight phase of the world
//
// Parameters:  rooms, p, room_index
//
//******************************************************************
void fight_monster(vector<room> &rooms, player &p, int &room_index);


int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    ifstream world;
    vector<room> rooms;
    get_world(world);
    set_world(world, rooms);
    //cout << rooms[1].get_exit()[0].get_direction();
    player p;
    create_player(p);
    game_opening(p);
    play_game(rooms, p);
    return 0;
}

void get_world(ifstream &fin)
{
    string temp;
    cout << "Enter the file for your world" << endl;
    cin  >> temp;
    
    fin.open(temp.c_str());
    if (fin.fail()) {
        cout << "Error in opening your file" << endl;
        exit(EXIT_FAILURE);
    }
}

void set_world(ifstream &world, vector<room> &rooms)
{
    int room_index = 0;
    while (!world.eof())
    {
        vector<ex> e1;
        int kys;
        double mon;
        bool ex_game;
        string desc;
        monster monst;
        
        //cout << room_index << endl;
        
        read_exit(world, rooms, room_index, e1);
        if (world.eof()) {
            break;
        }
        read_keys(world, rooms, room_index, kys);
        read_money(world, rooms, room_index, mon);
        read_monster(world, rooms, room_index, monst);
        read_exit_game(world, rooms, room_index, ex_game);
        read_description(world, rooms, room_index, desc);
        rooms.push_back(room(room_index, desc, mon, kys, e1, ex_game, monst));
        room_index++;
    }
}

void read_exit(ifstream &world, vector<room> &rooms, int &room_index, vector<ex> &e1)
{
    string temp;
    while (temp != "keys") {
        world >> temp;
        //cout << temp << endl;
        if (temp== "exit") {
            read_one_exit(world, rooms, room_index, e1);
        } else if (world.eof()) {
            break;
        } else if (temp != "keys") {
            cout << "Error File Syntax 1" << endl;
            exit(EXIT_FAILURE);
        }
    }
}

void read_one_exit(ifstream &world, vector<room> &rooms, int &room_index, vector<ex> &e1)
{
    string dir;
    int room_number;
    string lock;
    world >> dir;
    world >> room_number;
    world >> lock;
    
    //cout << dir << " " << room_number << " " << lock << endl;
    
    
    e1.push_back(ex(is_locked(lock), room_number, dir));
}


bool is_locked(string temp)
{
    if (temp == "locked") {
        return true;
    } else if (temp == "unlocked") {
        return false;
    } else {
        cout << "Error File Syntax 2" << endl;
        exit(EXIT_FAILURE);
    }
}

void read_keys(ifstream &world, vector<room> &rooms, int &room_index, int &kys)
{
    int temp;
    world >> temp;
    kys = temp;
}

void read_money(ifstream &world, vector<room> &rooms, int &room_index, double &mon)
{
    string temp;
    world >> temp;
    if (temp!="money") {
        cout << "Error File Syntax 3" << endl;
        exit(EXIT_FAILURE);
    }
    world >> mon;
    
}

void read_monster(ifstream &world, vector<room> &rooms, int &room_index, monster &monst)
{
    string temp;
    int exist;
    int hp;
    int attack;
    string name;
    world >> temp;
    if (temp != "monster") {
        cout << "Error File Syntax 4" << endl;
        exit(EXIT_FAILURE);
    }
    world >> exist;
    world >> hp;
    world >> attack;
    world >> name;
    monst.set_existance(exist);
    monst.set_hp(hp);
    monst.set_attack(attack);
    monst.set_name(name);
}

void read_exit_game(ifstream &world, vector<room> &rooms, int &room_index, bool &ex_game)
{
    string temp;
    world >> temp;
    if (temp=="no_exit_game") {
        ex_game = false;
    } else if (temp=="exit_game") {
        ex_game = true;
    } else {
        cout << "Error File Syntax 5" << endl;
        exit(EXIT_FAILURE);
    }
}

void read_description(ifstream &world, vector<room> &rooms, int &room_index, string &desc)
{
    string temp;
    desc = "";
    world >> temp;
    while (temp!="#") {
        desc += temp;
        desc += " ";
        world >> temp;
    }
}

void create_player(player &p)
{
    string name;
    cout << "Whats Your Name, Adventurer?" << endl;
    
    cin.ignore(100, '\n');
    getline(cin, name);
    p.set_name(name);
}

void game_opening(player &p)
{
    cout << p.get_name() << ", welcome to Brandon's Adventure Game." << endl;
    cout << "This is a menu driven game, but asks you to enter the direction\n"
    << "you want to go. When entering the direction please enter \"North\"\n"
    << "\"South\" \"East\" \"West\" \"Up\" \"Down\" etc.\n"
    << "You will have only one(1) full heal(40 hp) and two(2) half heals(20 hp).\n"
    << "Beware of Monsters!!\n"
    << "Happy Adventuring\n\n";
}

void play_game(vector<room> &rooms, player &p)
{
    int room_index = 0;
    print_menu(rooms, p, room_index);
}

void print_menu(vector<room> &rooms, player &p, int &room_index)
{
    if (rooms[room_index].get_monster().get_existance() == 1){
        cout << "You encountered a monster!\n";
        fight_monster(rooms, p, room_index);
    }
    
    cout << rooms[room_index].get_descrip() << endl;
    cout << "What do you want to do?\n"
    << "1. Go\n"
    << "2. Pick Up\n"
    << "3. Inventory\n"
    << "4. Try to leave\n";
    
    string choice;
    cin >> choice;
    menu_switch(choice, rooms, p, room_index);
}

void menu_switch(string choice, vector<room> &rooms, player &p, int &room_index)
{
    if (choice == "1") {
        do_go(rooms, p, room_index);
    } else if (choice =="2") {
        do_pick_up(rooms, p, room_index);
    } else if (choice == "3") {
        do_inventory(rooms, p, room_index);
    } else if (choice == "4") {
        do_leave(rooms, p, room_index);
    } else {
        cout << "Enter a valid choice\n";
        print_menu(rooms, p, room_index);
    }
}

void do_go(vector<room> &rooms, player &p, int &room_index)
{
    string temp;
    cout << "Which direction do you want to go?\n";
    cin >> temp;
    move_to_new_room(rooms, p, room_index, temp);
}

void do_pick_up(vector<room> &rooms, player &p, int &room_index)
{
    cout << "You picked up " << rooms[room_index].get_keys() << " key(s)\n";
    cout << "You picked up $" << rooms[room_index].get_money() << endl;
    
    p.add_keys(rooms[room_index].get_keys());
    p.add_money(rooms[room_index].get_money());
    
    rooms[room_index].set_key(0);
    rooms[room_index].set_mon(0);
    
    print_menu(rooms, p, room_index);
}

void do_inventory(vector<room> &rooms, player &p, int &room_index)
{
    cout << "You Have:\n";
    cout << "$" << p.get_wallet() << endl;
    cout << p.get_keys() << " keys" << endl;
    cout << p.get_full_heal() << " full heal(s)\n";
    cout << p.get_half_heal() << " half heal(s)\n";
    
    print_menu(rooms, p, room_index);
}

void do_leave(vector<room> &rooms, player &p, int &room_index)
{
    if (rooms[room_index].get_exit_game()) {
        cout << "Congratulations you made it out alive!\n";
        exit (EXIT_SUCCESS);
    } else {
        cout << "You can't leave. There is no way out right here.\n";
        print_menu(rooms, p, room_index);
    }
}

void move_to_new_room(vector<room> &rooms, player &p, int &room_index, string dir)
{
    int next_room = -1;
    int exit_index;
    for (int i=0; i<(rooms[room_index].get_exit()).size(); i++)
    {
        if (rooms[room_index].get_exit()[i].get_direction() == dir) {
            next_room = rooms[room_index].get_exit()[i].get_room_number();
            exit_index = i;
        }
    }
    if (next_room == -1)
    {
        cout << p.get_name() << ", pick a real direction\n" << endl;
        do_go(rooms, p, room_index);
    }
    if (rooms[room_index].get_exit()[exit_index].get_lock()) {
        cout << "The door is locked\n";
        unlock_door(rooms, p, room_index, exit_index);
    }
    print_menu(rooms, p, next_room);
}

void unlock_door(vector<room> &rooms, player &p, int &room_index, int exit_index)
{
    string choice;
    cout << "Do you want to unlock the door?\n";
    cin  >> choice;
    
    if ((choice == "yes") || (choice == "Yes")){
        if (p.get_keys() > 0)
        {
            rooms[room_index].get_exit()[exit_index].set_lock(false);
            p.decrement_key();
        } else {
            cout << "You don't have a key\n";
            print_menu(rooms, p, room_index);
        }
    } else if ((choice == "no")||(choice == "No")){
        print_menu(rooms, p, room_index);
    } else {
        cout << "Use better words!\n";
        unlock_door(rooms, p, room_index, exit_index);
    }
}

void fight_monster(vector<room> &rooms, player &p, int &room_index)
{
    while ((rooms[room_index].get_monster().get_hp() > 0) &&
           (p.get_health() > 0))
    {
        cout << endl << rooms[room_index].get_monster().get_name() << ": "
        << rooms[room_index].get_monster().get_hp() << " hp\n"
        << p.get_name() << ": " << p.get_health() << " hp\n";
        string choice;
        cout << "What would you like to do?\n"
        << "Fight or Heal\n";
        cin  >> choice;
        if (choice == "Fight") {
            cout << "BOOM BOOM POW\n";
            rooms[room_index].hit_monster(p.get_attack());
            if (rooms[room_index].get_monster().get_hp() > 0) {
                p.hit(rooms[room_index].get_monster().get_attack());
            }
        } else if (choice == "Heal") {
            string choice1;
            cout << "\"Full\" Heal or \"Half\" Heal\n";
            cin  >> choice1;
            if ((choice1 == "Full")&&(p.get_full_heal() >0)) {
                p.heal(40);
                p.decrement_f_heal();
            } else if ((choice1 == "Half")&&(p.get_half_heal() >0)) {
                p.heal(20);
                p.decrement_h_heal();
            } else if ((choice1 != "Full")||(choice1 != "Half")) {
                cout << "That wasn't a choice!\n";
                fight_monster(rooms, p, room_index);
            } else if (!(p.get_full_heal() >0)||!(p.get_half_heal() >0)) {
                cout << "You don't have that!\n";
                fight_monster(rooms, p, room_index);
            }
        } else {
            cout << "That wasn't a choice!\n";
            fight_monster(rooms, p, room_index);
        }
    }
    if (rooms[room_index].get_monster().get_hp() > 0) {
        cout << "Sorry you died. Better luck next time.\n";
        exit(EXIT_SUCCESS);
    } else {
        cout << "You defeated the " << rooms[room_index].get_monster().get_name() << "!\n";
        rooms[room_index].monster_exist(0);
    }
}




































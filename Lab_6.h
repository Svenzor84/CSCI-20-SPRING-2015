/*
 * Lab_6.h
 *
 *  Created on: Apr 15, 2015
 *      Author: Steve Ross-Byers
 *      Description: Header File for Lab 6
 *      Sources: CinReader (by Boyd Trolinger)
 */

#ifndef LAB_6_H_STEVE_ROSS_BYERS
#define LAB_6_H_STEVE_ROSS_BYERS

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "CinReader.h"
using std::cout;
using std::string;
using std::cin;
using std::srand;
using std::time;
using std::rand;
using std::ifstream;
using std::ofstream;

//Setting up global enumeration of enemy types
enum EnemyType {kGoblin, kOrc, kBugBear, kSkeleton, kGoblinChief, kOrcKing};
//And of items
enum ItemType {kKey, kDagger, kShortSword, kLongSword, kBastardSword,
               kLeatherArmor, kPlateMail,
               kAlchemistFire, kHealthPotion, kVitaPotion,
               kAmulet};
//And of cardinal directions
enum Direction {kNorth, kSouth, kEast, kWest};

//Global Function that outputs a bunch of new lines to "clear" the screen
void ClearScreen();

class Game {
 public:
  //Game Constructor
  Game();
  //Function to Start the game
  void Start();
 private:
  //function that lets the user decide to continue if they die
  int ContinueGame(int cont);
  //Function that forces the user to press enter to continue and its required variable
  void EnterToContinue();
  //Setting up CinReader
  CinReader reader;
  //Function to introduce the game
  void GameIntro();
  //Function to rename the game
  void NameGame(string game_name);
  //function that changes the character's location
  void SetLoc(int direction);
  char play_game_, new_game_, view_sheet_, re_roll_;
  int current_loc_x_, current_loc_y_;
  string game_name_;
};

class PlayerCharacter {
 public:
 //PC Constructor
 PlayerCharacter();
 //Function to Output the Character Sheet to the User
 void ViewSheet();
 //Function that names or renames the character
 void SetName();
 //Function to Set the Character's Class
 void SetClass(char char_class);
 //Function that allows the character to gain experience
 void SetXp(int xp_gained);
 //function for the character to gain gold
 void SetGold(int gold_gained);
 //function to change the character's inventory
 void SetInventory(int item_enum, int item_num);
 //function to equip the character's gear
 void SetGear();
 //function that allows the character to buy gear and stats
 void Shop(int shop_request);
 //function to update usable item totals after battle
 void SetUsables(int alch, int potion, int vita);
 //Function to set all variables for a character, used to load a previously saved character
 void SetCharacter(string fname, string lname, char char_class, int str, int dex, int intel,
                   int hp, int sp, int find, int xp, int ac, int gold, int weap_equip,
                   int armor_equip, int key, int alch, int potion, int vita, int dagger,
                   int bsword, int ssword, int lsword, int larmor, int pmail, int amulet);
 //Functions to return the character's data
 string GetLname();
 string GetFname();
 char GetClass();
 int GetStr();
 int GetDex();
 int GetInt();
 int GetHp();
 int GetSp();
 int GetFind();
 int GetXp();
 int GetAc();
 int GetGold();
 int GetWeap();
 int GetArmor();
 int GetKey();
 int GetAlch();
 int GetPotion();
 int GetVita();
 int GetDagger();
 int GetBSword();
 int GetSSword();
 int GetLSword();
 int GetLArmor();
 int GetPMail();
 int GetAmulet();
private:
 void EnterToContinue();
 //Setting up CinReader
 CinReader reader;
 string f_name_, l_name_;
 char char_class_, accept_name_;
 int str_, dex_, int_, hp_, sp_, find_, xp_, ac_, gold_, weap_equip_, armor_equip_;
 //This inventory array keeps track of the character's inventory
 //each index refers to an enumerated item type
 //e.g. inventory_[0] (or inventory_[kDagger])holds the number of daggers the pc currently holds
 int inventory_[11];
};

class Room {
 public:
  //Default room constructor (creates starting room)
  Room();
  //Constructor for custom rooms
  Room(int room_num, int room_diff, int door_num, int enemy_num, int enemy_type_,int north_door, int south_door,
       int east_door, int west_door, bool enemy_aware, bool enemy_hidden, bool npc_present,
       bool npc_aware, bool secret_found, string room_material);
  //Function to describe a room
  void DescribeRoom();
  //function that displays UI for the room, returns a user decision
  char UserInterface();
  //function that changes properties of the room based on user decision,
  //returns a number that corresponds to a user decision to change the character (buy gear/stats)
  int ChangeRoom(char user_decision);
  //Function that checks for enemies in the current room
  int CheckEnemies();
  //Function that handles battle
  int Battle();
  //Pulls in fresh Pc data for the battle function
  void GetPcData(string fname, string lname, int hp, int sp, int ac, int str, int dex, int intel, int find, int xp, int gold, int weap, int key, int alch, int potion, int vita, int amulet);
  //Function to return the gold gained from battle
  int GoldGained();
  //Function that chooses random loot depending on the room (returns loot type for SetLoot function)
  int GetRandomLoot();
  //function that returns the current room number
  int GetRoomNum();
  //function that returns the room's difficulty level
  int GetRoomDiff();
  //functions to return modified totals for usable items from battle
  int GetNewAlch();
  int GetNewPotion();
  int GetNewVita();
 private:
  //Function that forces the user to press enter to continue and its required variable
  void EnterToContinue();
  CinReader reader;
  int room_num_, room_diff_, enemy_num_, enemy_type_, door_num_;
  //This array holds information on doors for a room, each index refers to an enumerated direction type
  //e.g. door_[0] (or door_[kNorth]) refers to a door on the north side of the room
  //values represent the state of the door: 0 = no door, 1 = open door, 2 = locked door
  int door_[4];
  //these next variables are all imported pc data for the battle function
  string pc_fname_, pc_lname_;
  int pc_hp_, pc_sp_, pc_ac_, pc_str_, pc_dex_, pc_int_, pc_find_, pc_xp_, pc_gold_,
      pc_weap_, pc_key_, pc_alch_, pc_potion_, pc_vita_, pc_amulet_, gold_gained_;
  bool secret_found_,  enemy_aware_, enemy_hidden_, npc_present_, npc_aware_;
  string room_material_;
};

class Enemy {
 public:
 //Enemy Constructor
  Enemy(int enemy_type);
  //functions to return enemy stats for battle function
  string GetName();
  int GetHp();
  int GetAc();
  int GetAtk();
  int GetXp();
  int GetGold();

 private:
  string enemy_name_;
  int enemy_hp_, enemy_atk_, enemy_ac_,enemy_xp_, enemy_gold_;
};
#endif /* LAB_6_H_STEVE_ROSS_BYERS */

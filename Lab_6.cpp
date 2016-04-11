/*
 * Lab_6.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: Steve Ross-Byers
 *      Description: Dungeon Crawler Text Adventure
 */

#include "Lab_6.h"

//Function that outputs a bunch of new lines to "clear" the screen
void ClearScreen() {
  cout
      << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"
      << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
}

//Game Constructor
Game::Game() {
  play_game_ = 'Y';
  new_game_ = 'Y';
  view_sheet_ = 'Y';
  re_roll_ = 'Y';
  current_loc_x_ = 0;
  current_loc_y_ = 1;
  game_name_ = "Ancestral Quest";
}

//Function to start the game
void Game::Start() {
  ifstream in_stream;
  ofstream out_stream;
  int enemies_present;
  char user_selection;
  bool user_loop = true;
  GameIntro();
  PlayerCharacter pc;
  //these variables are for saving and loading the game
  string fname, lname;
  char char_class;
  int str, dex, intel, hp, sp, find, xp, ac, gold, weap_equip, armor_equip, key,
      alch, potion, vita, dagger, bsword, ssword, lsword, larmor, pmail, amulet,
      room_num;
  do {
    switch (toupper(new_game_)) {
      case 'L':
        char user_choice;

        cout << "          ****Load game from which slot?****\n\n";
        in_stream.open("slotA.txt");
        if (in_stream.fail()) {
        } else {
          cout << "        [A]";
          in_stream >> fname >> lname;
          cout << fname << " " << lname << endl;
        }
        in_stream.close();
        in_stream.open("slotB.txt");
        if (in_stream.fail()) {
        } else {
          cout << "        [B]";
          in_stream >> fname >> lname;
          cout << fname << " " << lname << endl;
        }
        in_stream.close();
        in_stream.open("slotC.txt");
        if (in_stream.fail()) {
        } else {
          cout << "        [C]";
          in_stream >> fname >> lname;
          cout << fname << " " << lname << endl;
        }
        in_stream.close();
        cout << "[E]xit to New Character Creation\n\n";
        user_choice = reader.readChar("AaBbCcEe");
        ClearScreen();
        cout
            << "Note: Loading your game will restore your character,\n"
            << "inventory, and current Catacomb Level ONLY. Your character\n"
            << "will be placed you in the first Room of the most recent Catacomb\n"
            << "Level you visited, with all Rooms and enemies restored.\n";
        EnterToContinue();
        ClearScreen();
        switch (toupper(user_choice)) {
          case 'E':
            cout << "You will now be taken to New Character Creation\n";
            new_game_ = 'N';
            break;
          case 'A':
            in_stream.open("slotA.txt");
            in_stream >> fname >> lname >> char_class >> str >> dex >> intel
                >> hp >> sp >> find >> xp >> ac >> gold >> weap_equip
                >> armor_equip >> key >> alch >> potion >> vita >> dagger
                >> bsword >> ssword >> lsword >> larmor >> pmail >> amulet
                >> room_num;

            in_stream.close();
            pc.SetCharacter(fname, lname, char_class, str, dex, intel, hp, sp,
                            find, xp, ac, gold, weap_equip, armor_equip, key,
                            alch, potion, vita, dagger, bsword, ssword, lsword,
                            larmor, pmail, amulet);
            if (room_num > 31) {
              current_loc_x_ = 3;
              current_loc_y_ = 11;
            } else if (room_num > 14) {
              current_loc_x_ = 2;
              current_loc_y_ = 6;
            } else {
              current_loc_x_ = 0;
              current_loc_y_ = 1;
            }
            user_loop = false;
            break;
          case 'B':
            in_stream.open("slotB.txt");
            in_stream >> fname >> lname >> char_class >> str >> dex >> intel
                >> hp >> sp >> find >> xp >> ac >> gold >> weap_equip
                >> armor_equip >> key >> alch >> potion >> vita >> dagger
                >> bsword >> ssword >> lsword >> larmor >> pmail >> amulet
                >> room_num;

            in_stream.close();
            pc.SetCharacter(fname, lname, char_class, str, dex, intel, hp, sp,
                            find, xp, ac, gold, weap_equip, armor_equip, key,
                            alch, potion, vita, dagger, bsword, ssword, lsword,
                            larmor, pmail, amulet);
            if (room_num > 31) {
              current_loc_x_ = 3;
              current_loc_y_ = 10;
            } else if (room_num > 14) {
              current_loc_x_ = 2;
              current_loc_y_ = 6;
            } else {
              current_loc_x_ = 0;
              current_loc_y_ = 1;
            }
            user_loop = false;
            break;
          case 'C':
            in_stream.open("slotC.txt");
            in_stream >> fname >> lname >> char_class >> str >> dex >> intel
                >> hp >> sp >> find >> xp >> ac >> gold >> weap_equip
                >> armor_equip >> key >> alch >> potion >> vita >> dagger
                >> bsword >> ssword >> lsword >> larmor >> pmail >> amulet
                >> room_num;

            in_stream.close();
            pc.SetCharacter(fname, lname, char_class, str, dex, intel, hp, sp,
                            find, xp, ac, gold, weap_equip, armor_equip, key,
                            alch, potion, vita, dagger, bsword, ssword, lsword,
                            larmor, pmail, amulet);
            if (room_num > 31) {
              current_loc_x_ = 3;
              current_loc_y_ = 10;
            } else if (room_num > 14) {
              current_loc_x_ = 2;
              current_loc_y_ = 6;
            } else {
              current_loc_x_ = 0;
              current_loc_y_ = 1;
            }
            user_loop = false;
            break;
        }
        EnterToContinue();
        ClearScreen();
        break;
      case 'N':
//Character Creation
        do {
          cout << "Would you like to be a [M]age, a [R}ogue, or a [W]arrior?\n";
          pc.SetClass(toupper(reader.readChar("MmRrWw")));
          pc.SetName();
          cout << "Character creation is complete.\n" << "\n";
          pc.ViewSheet();
          cout
              << "\n"
              << "Are you happy with your character, or would you like to re-roll?\n"
              << "<PRESS [R] TO RE-ROLL YOUR CHARACTER OR [C] TO CONTINUE>\n"
              << endl;
          re_roll_ = reader.readChar("RrCc");
          if (toupper(re_roll_) == 'C') {
            user_loop = false;
          }
        } while (toupper(re_roll_) == 'R');
        break;
    }
  } while (user_loop == true);
//Setting up the Game World, creating custom rooms requires these parameters to be passed into the constuctor
  //int room_num, int room_diff, int door_num, int enemy_num,
  //int enemy_type, int north_door, int south_door, int east_door,
  //int west_door, bool enemy_aware, bool enemy_hidden, bool npc_present,
  //bool npc_aware, bool secret_found, string room_material
  Room room_0;
  Room room_1(1, 1, 2, 1, kGoblin, 2, 0, 0, 1, true, false, false, false, false,
              "Stone");
  Room room_2(2, 1, 3, 0, kGoblin, 0, 1, 1, 1, true, false, false, false, false,
              "Stone");
  Room room_3(3, 1, 3, 3, kGoblin, 2, 0, 1, 1, true, false, false, false, false,
              "Stone");
  Room room_4(4, 1, 0, 2, kGoblin, 0, 0, 0, 0, false, false, false, false,
              false, "Smooth Stone");
  Room room_5(5, 1, 2, 0, kGoblin, 1, 1, 0, 0, true, false, false, false, true,
              "Stone");
  Room room_6(6, 1, 3, 4, kGoblin, 2, 1, 0, 1, true, true, false, false, false,
              "Stone");
  Room room_7(7, 1, 2, 2, kGoblin, 2, 1, 0, 0, true, false, false, false, true,
              "Wood Plank");
  Room room_8(8, 1, 2, 3, kGoblin, 1, 0, 1, 0, true, false, false, false, false,
              "Stone");
  Room room_9(9, 2, 2, 0, kGoblin, 1, 1, 0, 0, true, false, false, false, false,
              "Rough Stone");
  Room room_10(10, 2, 3, 2, kOrc, 0, 1, 1, 2, true, false, false, false, false,
               "Rough Stone");
  Room room_11(11, 1, 2, 2, kGoblin, 0, 0, 1, 1, true, false, false, false,
               true, "Stone");
  Room room_12(12, 2, 2, 4, kOrc, 0, 1, 1, 0, true, false, false, false, false,
               "Rough Stone");
  Room room_13(13, 2, 2, 0, kOrc, 1, 2, 0, 0, true, false, false, false, false,
               "Rough Stone");
  Room room_14(14, 1, 1, 1, kGoblinChief, 1, 0, 0, 0, true, false, false, false,
               false, "Worked Stone");
  Room room_15(15, 2, 2, 0, kOrc, 1, 1, 0, 0, true, false, true, false, false,
               "Wood Plank");
  Room room_16(16, 2, 3, 3, kOrc, 0, 1, 1, 1, true, false, false, false, false,
               "Wood Plank");
  Room room_17(17, 2, 2, 4, kOrc, 2, 0, 1, 0, false, false, false, false, false,
               "Wood Plank");
  Room room_18(18, 2, 3, 0, kOrc, 1, 1, 0, 2, true, false, false, false, false,
               "Wood Plank");
  Room room_19(19, 3, 1, 5, kOrc, 0, 0, 1, 0, true, true, false, false, false,
               "Wood Plank");
  Room room_20(20, 3, 3, 2, kOrc, 1, 1, 2, 0, true, false, false, false, true,
               "Wood Plank");
  Room room_21(21, 5, 1, 0, kOrc, 0, 0, 0, 1, true, false, false, false, false,
               "Wood Plank");
  Room room_22(22, 4, 2, 0, kOrc, 0, 1, 1, 0, true, false, false, false, false,
               "Wood Plank");
  Room room_23(23, 4, 2, 4, kOrc, 0, 0, 2, 1, true, false, false, false, false,
               "Wood Plank");
  Room room_24(24, 4, 4, 0, kOrc, 2, 1, 1, 1, true, false, false, false, false,
               "Wood Plank");
  Room room_25(25, 1, 1, 1, kOrcKing, 1, 0, 0, 0, true, false, false, false,
               false, "Finely Furnished");
  Room room_26(26, 3, 2, 2, kOrc, 0, 0, 1, 1, true, true, false, false, false,
               "Engraved Stone");
  Room room_27(27, 3, 2, 2, kOrc, 2, 0, 0, 1, true, false, false, false, false,
               "Engraved Stone");
  Room room_28(28, 3, 3, 0, kOrc, 1, 1, 0, 2, true, false, false, false, true,
               "Engraved Stone");
  Room room_29(29, 6, 1, 5, kOrc, 0, 0, 1, 0, true, false, false, false, false,
               "Engraved Stone");
  Room room_30(30, 4, 2, 2, kBugBear, 1, 1, 0, 0, true, false, false, false,
               false, "Engraved Stone");
  Room room_31(31, 4, 2, 4, kBugBear, 0, 1, 0, 2, true, false, false, false,
               false, "Engraved Stone");
  Room room_32(32, 3, 1, 0, kBugBear, 0, 1, 0, 0, true, false, true, false,
               false, "Moss Covered");
//Introducing your character to the game world
  ClearScreen();
  cout
      << "    Your gaze lingers on the dark stone staircase that leads down into your\n "
      << "ancestors' tomb.  If the report you gathered from the nearby town was correct,\n"
      << "deep within this dank dungeon lies the proof required to restore your family's\n"
      << "name and earn back your birthright, the famed Castle "
      << pc.GetLname() << ".\n";
  EnterToContinue();
  cout
      << "    Your footsteps ring hollow as you descend, the darkness \n"
      << "pressing in on all sides.  After an eternity of stairs you reach\n"
      << "a stone landing and notice the faint flicker of a light at the end\n"
      << "of a long hall accompanied by a soft noise.\n"
      << "\n"
      << "You press on, vividly aware of the danger and promise all around you...\n";
  EnterToContinue();

//This is the beginning of the Game Loop
  do {
    ClearScreen();
    //These if statements check for the current location of the character (x,y)
    if (current_loc_x_ == 0 && current_loc_y_ == 0) {
      cout << "  This is the door where you first entered the catacomb...\n"
           << "If you leave, your adventure will end, and your family's name\n"
           << "will live on in infamy.  Would you like to continue playing?\n"
           << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
      play_game_ = reader.readChar("YyNn");
      ClearScreen();
      if (toupper(play_game_) == 'Y')
        current_loc_y_ = 1;
    }
    if (current_loc_x_ == 0 && current_loc_y_ == 1) {
      room_0.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                       pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                       pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                       pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                       pc.GetAmulet());
      enemies_present = room_0.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_0.DescribeRoom();
          user_selection = room_0.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_0.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_0.GetRandomLoot(), room_0.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_0.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_0.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_0.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_0.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_0.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_0.Battle()));
            pc.SetGold(room_0.GoldGained());
            pc.SetUsables(room_0.GetNewAlch(), room_0.GetNewPotion(),
                          room_0.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_0.Battle()));
          pc.SetGold(room_0.GoldGained());
          pc.SetUsables(room_0.GetNewAlch(), room_0.GetNewPotion(),
                        room_0.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 1 && current_loc_y_ == 1) {
      room_1.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                       pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                       pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                       pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                       pc.GetAmulet());
      enemies_present = room_1.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_1.DescribeRoom();
          user_selection = room_1.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_1.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_1.GetRandomLoot(), room_1.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_1.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_1.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_1.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_1.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_1.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_1.Battle()));
            pc.SetGold(room_1.GoldGained());
            pc.SetUsables(room_1.GetNewAlch(), room_1.GetNewPotion(),
                          room_1.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_1.Battle()));
          pc.SetGold(room_1.GoldGained());
          pc.SetUsables(room_1.GetNewAlch(), room_1.GetNewPotion(),
                        room_1.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 1 && current_loc_y_ == 2) {
      room_2.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                       pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                       pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                       pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                       pc.GetAmulet());
      enemies_present = room_2.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_2.DescribeRoom();
          user_selection = room_2.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_2.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_2.GetRandomLoot(), room_2.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_2.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_2.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_2.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_2.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_2.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_2.Battle()));
            pc.SetGold(room_2.GoldGained());
            pc.SetUsables(room_2.GetNewAlch(), room_2.GetNewPotion(),
                          room_2.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_2.Battle()));
          pc.SetGold(room_2.GoldGained());
          pc.SetUsables(room_2.GetNewAlch(), room_2.GetNewPotion(),
                        room_2.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 2 && current_loc_y_ == 2) {
      room_3.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                       pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                       pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                       pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                       pc.GetAmulet());
      enemies_present = room_3.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_3.DescribeRoom();
          user_selection = room_3.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_3.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_3.GetRandomLoot(), room_3.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_3.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_3.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_3.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_3.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_3.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_3.Battle()));
            pc.SetGold(room_3.GoldGained());
            pc.SetUsables(room_3.GetNewAlch(), room_3.GetNewPotion(),
                          room_3.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_3.Battle()));
          pc.SetGold(room_3.GoldGained());
          pc.SetUsables(room_3.GetNewAlch(), room_3.GetNewPotion(),
                        room_3.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 3 && current_loc_y_ == 2) {
      room_4.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                       pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                       pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                       pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                       pc.GetAmulet());
      enemies_present = room_4.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_4.DescribeRoom();
          user_selection = room_4.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_4.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_4.GetRandomLoot(), room_4.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_4.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_4.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_4.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_4.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_4.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_4.Battle()));
            pc.SetGold(room_4.GoldGained());
            pc.SetUsables(room_4.GetNewAlch(), room_4.GetNewPotion(),
                          room_4.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_4.Battle()));
          pc.SetGold(room_4.GoldGained());
          pc.SetUsables(room_4.GetNewAlch(), room_4.GetNewPotion(),
                        room_4.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 2 && current_loc_y_ == 3) {
      room_5.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                       pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                       pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                       pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                       pc.GetAmulet());
      enemies_present = room_5.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_5.DescribeRoom();
          user_selection = room_5.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_5.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_5.GetRandomLoot(), room_5.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_5.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_5.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_5.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_5.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_5.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_5.Battle()));
            pc.SetGold(room_5.GoldGained());
            pc.SetUsables(room_5.GetNewAlch(), room_5.GetNewPotion(),
                          room_5.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_5.Battle()));
          pc.SetGold(room_5.GoldGained());
          pc.SetUsables(room_5.GetNewAlch(), room_5.GetNewPotion(),
                        room_5.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 2 && current_loc_y_ == 4) {
      room_6.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                       pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                       pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                       pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                       pc.GetAmulet());
      enemies_present = room_6.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_6.DescribeRoom();
          user_selection = room_6.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_6.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_6.GetRandomLoot(), room_6.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_6.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_6.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_6.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_6.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_6.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_6.Battle()));
            pc.SetGold(room_6.GoldGained());
            pc.SetUsables(room_6.GetNewAlch(), room_6.GetNewPotion(),
                          room_6.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_6.Battle()));
          pc.SetGold(room_6.GoldGained());
          pc.SetUsables(room_6.GetNewAlch(), room_6.GetNewPotion(),
                        room_6.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 2 && current_loc_y_ == 5) {
      room_7.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                       pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                       pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                       pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                       pc.GetAmulet());
      enemies_present = room_7.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_7.DescribeRoom();
          user_selection = room_7.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_7.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_7.GetRandomLoot(), room_7.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_7.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_7.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_7.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_7.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_7.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_7.Battle()));
            pc.SetGold(room_7.GoldGained());
            pc.SetUsables(room_7.GetNewAlch(), room_7.GetNewPotion(),
                          room_7.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_7.Battle()));
          pc.SetGold(room_7.GoldGained());
          pc.SetUsables(room_7.GetNewAlch(), room_7.GetNewPotion(),
                        room_7.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 1 && current_loc_y_ == 4) {
      room_11.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_11.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_11.DescribeRoom();
          user_selection = room_11.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_11.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_11.GetRandomLoot(), room_11.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_11.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_11.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_11.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_11.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_11.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_11.Battle()));
            pc.SetGold(room_11.GoldGained());
            pc.SetUsables(room_11.GetNewAlch(), room_11.GetNewPotion(),
                          room_11.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_11.Battle()));
          pc.SetGold(room_11.GoldGained());
          pc.SetUsables(room_11.GetNewAlch(), room_11.GetNewPotion(),
                        room_11.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 0 && current_loc_y_ == 4) {
      room_10.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_10.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_10.DescribeRoom();
          user_selection = room_10.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_10.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_10.GetRandomLoot(), room_10.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_10.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_10.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_10.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_10.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_10.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_10.Battle()));
            pc.SetGold(room_10.GoldGained());
            pc.SetUsables(room_10.GetNewAlch(), room_10.GetNewPotion(),
                          room_10.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_10.Battle()));
          pc.SetGold(room_10.GoldGained());
          pc.SetUsables(room_10.GetNewAlch(), room_10.GetNewPotion(),
                        room_10.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == -1 && current_loc_y_ == 4) {
      room_12.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_12.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_12.DescribeRoom();
          user_selection = room_12.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_12.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_12.GetRandomLoot(), room_12.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_12.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_12.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_12.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_12.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_12.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_12.Battle()));
            pc.SetGold(room_12.GoldGained());
            pc.SetUsables(room_12.GetNewAlch(), room_12.GetNewPotion(),
                          room_12.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_12.Battle()));
          pc.SetGold(room_12.GoldGained());
          pc.SetUsables(room_12.GetNewAlch(), room_12.GetNewPotion(),
                        room_12.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == -1 && current_loc_y_ == 3) {
      room_13.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_13.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_13.DescribeRoom();
          user_selection = room_13.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_13.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_13.GetRandomLoot(), room_13.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_13.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_13.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_13.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_13.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_13.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_13.Battle()));
            pc.SetGold(room_13.GoldGained());
            pc.SetUsables(room_13.GetNewAlch(), room_13.GetNewPotion(),
                          room_13.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_13.Battle()));
          pc.SetGold(room_13.GoldGained());
          pc.SetUsables(room_13.GetNewAlch(), room_13.GetNewPotion(),
                        room_13.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == -1 && current_loc_y_ == 2) {
      room_14.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_14.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_14.DescribeRoom();
          user_selection = room_14.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_14.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_14.GetRandomLoot(), room_14.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_14.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_14.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_14.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_14.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_14.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_14.Battle()));
            pc.SetGold(room_14.GoldGained());
            pc.SetUsables(room_14.GetNewAlch(), room_14.GetNewPotion(),
                          room_14.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_14.Battle()));
          pc.SetGold(room_14.GoldGained());
          pc.SetUsables(room_14.GetNewAlch(), room_14.GetNewPotion(),
                        room_14.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 0 && current_loc_y_ == 2) {
      room_8.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                       pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                       pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                       pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                       pc.GetAmulet());
      enemies_present = room_8.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_8.DescribeRoom();
          user_selection = room_8.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_8.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_8.GetRandomLoot(), room_8.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_8.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_8.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_8.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_8.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_8.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_8.Battle()));
            pc.SetGold(room_8.GoldGained());
            pc.SetUsables(room_8.GetNewAlch(), room_8.GetNewPotion(),
                          room_8.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_8.Battle()));
          pc.SetGold(room_8.GoldGained());
          pc.SetUsables(room_8.GetNewAlch(), room_8.GetNewPotion(),
                        room_8.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 0 && current_loc_y_ == 3) {
      room_9.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                       pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                       pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                       pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                       pc.GetAmulet());
      enemies_present = room_9.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_9.DescribeRoom();
          user_selection = room_9.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_9.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_9.GetRandomLoot(), room_9.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_9.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_9.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_9.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_9.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl << room_9.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_9.Battle()));
            pc.SetGold(room_9.GoldGained());
            pc.SetUsables(room_9.GetNewAlch(), room_9.GetNewPotion(),
                          room_9.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_9.Battle()));
          pc.SetGold(room_9.GoldGained());
          pc.SetUsables(room_9.GetNewAlch(), room_9.GetNewPotion(),
                        room_9.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 2 && current_loc_y_ == 6) {
      room_15.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_15.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_15.DescribeRoom();
          user_selection = room_15.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_15.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_15.GetRandomLoot(), room_15.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_15.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_15.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_15.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_15.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_15.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_15.Battle()));
            pc.SetGold(room_15.GoldGained());
            pc.SetUsables(room_15.GetNewAlch(), room_15.GetNewPotion(),
                          room_15.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_15.Battle()));
          pc.SetGold(room_15.GoldGained());
          pc.SetUsables(room_15.GetNewAlch(), room_15.GetNewPotion(),
                        room_15.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 2 && current_loc_y_ == 7) {
      room_16.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_16.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_16.DescribeRoom();
          user_selection = room_16.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_16.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_16.GetRandomLoot(), room_16.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_16.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_16.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_16.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_16.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_16.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_16.Battle()));
            pc.SetGold(room_16.GoldGained());
            pc.SetUsables(room_16.GetNewAlch(), room_16.GetNewPotion(),
                          room_16.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_16.Battle()));
          pc.SetGold(room_16.GoldGained());
          pc.SetUsables(room_16.GetNewAlch(), room_16.GetNewPotion(),
                        room_16.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 1 && current_loc_y_ == 7) {
      room_17.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_17.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_17.DescribeRoom();
          user_selection = room_17.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_17.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_17.GetRandomLoot(), room_17.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_17.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_17.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_17.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_17.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_17.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_17.Battle()));
            pc.SetGold(room_17.GoldGained());
            pc.SetUsables(room_17.GetNewAlch(), room_17.GetNewPotion(),
                          room_17.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_17.Battle()));
          pc.SetGold(room_17.GoldGained());
          pc.SetUsables(room_17.GetNewAlch(), room_17.GetNewPotion(),
                        room_17.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 1 && current_loc_y_ == 8) {
      room_18.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_18.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_18.DescribeRoom();
          user_selection = room_18.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_18.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_18.GetRandomLoot(), room_18.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_18.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_18.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_18.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_18.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_18.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_18.Battle()));
            pc.SetGold(room_18.GoldGained());
            pc.SetUsables(room_18.GetNewAlch(), room_18.GetNewPotion(),
                          room_18.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_18.Battle()));
          pc.SetGold(room_18.GoldGained());
          pc.SetUsables(room_18.GetNewAlch(), room_18.GetNewPotion(),
                        room_18.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 0 && current_loc_y_ == 8) {
      room_19.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_19.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_19.DescribeRoom();
          user_selection = room_19.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_19.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_19.GetRandomLoot(), room_19.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_19.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_19.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_19.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_19.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_19.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_19.Battle()));
            pc.SetGold(room_19.GoldGained());
            pc.SetUsables(room_19.GetNewAlch(), room_19.GetNewPotion(),
                          room_19.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_19.Battle()));
          pc.SetGold(room_19.GoldGained());
          pc.SetUsables(room_19.GetNewAlch(), room_19.GetNewPotion(),
                        room_19.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 1 && current_loc_y_ == 9) {
      room_20.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_20.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_20.DescribeRoom();
          user_selection = room_20.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_20.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_20.GetRandomLoot(), room_20.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_20.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_20.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_20.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_20.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_20.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_20.Battle()));
            pc.SetGold(room_20.GoldGained());
            pc.SetUsables(room_20.GetNewAlch(), room_20.GetNewPotion(),
                          room_20.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_20.Battle()));
          pc.SetGold(room_20.GoldGained());
          pc.SetUsables(room_20.GetNewAlch(), room_20.GetNewPotion(),
                        room_20.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 2 && current_loc_y_ == 9) {
      room_21.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_21.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_21.DescribeRoom();
          user_selection = room_21.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_21.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_21.GetRandomLoot(), room_21.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_21.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_21.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_21.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_21.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_21.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_21.Battle()));
            pc.SetGold(room_21.GoldGained());
            pc.SetUsables(room_21.GetNewAlch(), room_21.GetNewPotion(),
                          room_21.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_21.Battle()));
          pc.SetGold(room_21.GoldGained());
          pc.SetUsables(room_21.GetNewAlch(), room_21.GetNewPotion(),
                        room_21.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 1 && current_loc_y_ == 10) {
      room_22.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_22.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_22.DescribeRoom();
          user_selection = room_22.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_22.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_22.GetRandomLoot(), room_22.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_22.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_22.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_22.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_22.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_22.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_22.Battle()));
            pc.SetGold(room_22.GoldGained());
            pc.SetUsables(room_22.GetNewAlch(), room_22.GetNewPotion(),
                          room_22.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_22.Battle()));
          pc.SetGold(room_22.GoldGained());
          pc.SetUsables(room_22.GetNewAlch(), room_22.GetNewPotion(),
                        room_22.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 2 && current_loc_y_ == 10) {
      room_23.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_23.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_23.DescribeRoom();
          user_selection = room_23.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_23.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_23.GetRandomLoot(), room_23.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_23.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_23.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_23.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_23.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_23.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_23.Battle()));
            pc.SetGold(room_23.GoldGained());
            pc.SetUsables(room_23.GetNewAlch(), room_23.GetNewPotion(),
                          room_23.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_23.Battle()));
          pc.SetGold(room_23.GoldGained());
          pc.SetUsables(room_23.GetNewAlch(), room_23.GetNewPotion(),
                        room_23.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 3 && current_loc_y_ == 10) {
      room_24.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_24.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_24.DescribeRoom();
          user_selection = room_24.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_24.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_24.GetRandomLoot(), room_24.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_24.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_24.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_24.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_24.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_24.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_24.Battle()));
            pc.SetGold(room_24.GoldGained());
            pc.SetUsables(room_24.GetNewAlch(), room_24.GetNewPotion(),
                          room_24.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_24.Battle()));
          pc.SetGold(room_24.GoldGained());
          pc.SetUsables(room_24.GetNewAlch(), room_24.GetNewPotion(),
                        room_24.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 3 && current_loc_y_ == 9) {
      room_25.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_25.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_25.DescribeRoom();
          user_selection = room_25.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_25.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_25.GetRandomLoot(), room_25.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_25.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_25.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_25.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_25.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_25.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_25.Battle()));
            pc.SetGold(room_25.GoldGained());
            pc.SetUsables(room_25.GetNewAlch(), room_25.GetNewPotion(),
                          room_25.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_25.Battle()));
          pc.SetGold(room_25.GoldGained());
          pc.SetUsables(room_25.GetNewAlch(), room_25.GetNewPotion(),
                        room_25.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 3 && current_loc_y_ == 7) {
      room_26.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_26.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_26.DescribeRoom();
          user_selection = room_26.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_26.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_26.GetRandomLoot(), room_26.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_26.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_26.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_26.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_26.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_26.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_26.Battle()));
            pc.SetGold(room_26.GoldGained());
            pc.SetUsables(room_26.GetNewAlch(), room_26.GetNewPotion(),
                          room_26.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_26.Battle()));
          pc.SetGold(room_26.GoldGained());
          pc.SetUsables(room_26.GetNewAlch(), room_26.GetNewPotion(),
                        room_26.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 4 && current_loc_y_ == 7) {
      room_27.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_27.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_27.DescribeRoom();
          user_selection = room_27.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_27.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_27.GetRandomLoot(), room_27.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_27.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_27.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_27.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_27.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_27.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_27.Battle()));
            pc.SetGold(room_27.GoldGained());
            pc.SetUsables(room_27.GetNewAlch(), room_27.GetNewPotion(),
                          room_27.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_27.Battle()));
          pc.SetGold(room_27.GoldGained());
          pc.SetUsables(room_27.GetNewAlch(), room_27.GetNewPotion(),
                        room_27.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 4 && current_loc_y_ == 8) {
      room_28.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_28.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_28.DescribeRoom();
          user_selection = room_28.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_28.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_28.GetRandomLoot(), room_28.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_28.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_28.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_28.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_28.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_28.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_28.Battle()));
            pc.SetGold(room_28.GoldGained());
            pc.SetUsables(room_28.GetNewAlch(), room_28.GetNewPotion(),
                          room_28.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_28.Battle()));
          pc.SetGold(room_28.GoldGained());
          pc.SetUsables(room_28.GetNewAlch(), room_28.GetNewPotion(),
                        room_28.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 3 && current_loc_y_ == 8) {
      room_29.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_29.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_29.DescribeRoom();
          user_selection = room_29.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_29.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_29.GetRandomLoot(), room_29.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_29.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_29.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_29.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_29.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_29.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_29.Battle()));
            pc.SetGold(room_29.GoldGained());
            pc.SetUsables(room_29.GetNewAlch(), room_29.GetNewPotion(),
                          room_29.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_29.Battle()));
          pc.SetGold(room_29.GoldGained());
          pc.SetUsables(room_29.GetNewAlch(), room_29.GetNewPotion(),
                        room_29.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 4 && current_loc_y_ == 9) {
      room_30.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_30.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_30.DescribeRoom();
          user_selection = room_30.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_30.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_30.GetRandomLoot(), room_30.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_30.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_30.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_30.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_30.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_30.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_30.Battle()));
            pc.SetGold(room_30.GoldGained());
            pc.SetUsables(room_30.GetNewAlch(), room_30.GetNewPotion(),
                          room_30.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_30.Battle()));
          pc.SetGold(room_30.GoldGained());
          pc.SetUsables(room_30.GetNewAlch(), room_30.GetNewPotion(),
                        room_30.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 4 && current_loc_y_ == 10) {
      room_31.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_31.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_31.DescribeRoom();
          user_selection = room_31.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_31.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_31.GetRandomLoot(), room_31.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_31.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_31.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_31.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_31.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_31.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_31.Battle()));
            pc.SetGold(room_31.GoldGained());
            pc.SetUsables(room_31.GetNewAlch(), room_31.GetNewPotion(),
                          room_31.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_31.Battle()));
          pc.SetGold(room_31.GoldGained());
          pc.SetUsables(room_31.GetNewAlch(), room_31.GetNewPotion(),
                        room_31.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    if (current_loc_x_ == 3 && current_loc_y_ == 11) {
      room_32.GetPcData(pc.GetFname(), pc.GetLname(), pc.GetHp(), pc.GetSp(),
                        pc.GetAc(), pc.GetStr(), pc.GetDex(), pc.GetInt(),
                        pc.GetFind(), pc.GetXp(), pc.GetGold(), pc.GetWeap(),
                        pc.GetKey(), pc.GetAlch(), pc.GetPotion(), pc.GetVita(),
                        pc.GetAmulet());
      enemies_present = room_32.CheckEnemies();
      switch (enemies_present) {
        case 0:
          room_32.DescribeRoom();
          user_selection = room_32.UserInterface();
          switch (user_selection) {
            int change_room_result;
          case 'V':
            pc.ViewSheet();
            EnterToContinue();
            break;
          case 'R':
            change_room_result = room_32.ChangeRoom('R');
            switch (change_room_result) {
              case 0:
                break;
              case 4:
                pc.SetInventory(room_32.GetRandomLoot(), room_32.GetRoomDiff());
                break;
            }
            EnterToContinue();
            break;
          case 'O':
            pc.Shop(room_32.ChangeRoom('O'));
            EnterToContinue();
            break;
          case 'U':
            pc.SetInventory(kKey, -(room_32.ChangeRoom('U')));
            break;
          case 'N':
            SetLoc(kNorth);
            break;
          case 'S':
            SetLoc(kSouth);
            break;
          case 'E':
            SetLoc(kEast);
            break;
          case 'W':
            SetLoc(kWest);
            break;
          case 'X':
            cout
                << "You have decided to quit the game.  Please, don't go so soon!\n"
                << "     Would you like to continue playing?\n"
                << "        <PRESS [Y] TO CONTINUE OR [N] TO QUIT>\n" << endl;
            play_game_ = reader.readChar("YyNn");
            ClearScreen();
            break;
          case 'C':
            pc.SetGear();
            EnterToContinue();
            break;
          case 'G':
            char user_choice;
            cout << "          ****Save game to which slot?****\n\n"
                 << "        [A]";
            in_stream.open("slotA.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [B]";
            in_stream.open("slotB.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "        [C]";
            in_stream.open("slotC.txt");
            if (in_stream.fail()) {
              cout << "Empty\n";
            } else {
              in_stream >> fname;
              in_stream >> lname;
              cout << fname << " " << lname << endl;
            }
            in_stream.close();
            cout << "[E]xit\n\n";
            user_choice = reader.readChar("AaBbCcEe");
            ClearScreen();
            cout
                << "Note: Saving your game will preserve your character,\n"
                << "inventory, and Catacomb Level ONLY.  Loading your game\n"
                << "will place you in the first Room of the most recent Catacomb\n"
                << "Level you have visited, with all Rooms and enemies restored.\n";
            EnterToContinue();
            ClearScreen();
            switch (toupper(user_choice)) {
              case 'E':
                break;
              case 'A':
                cout
                    << "    Are you sure you want to save to Slot[A]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotA.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_32.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'B':
                cout
                    << "    Are you sure you want to save to Slot[B]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotB.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_32.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
              case 'C':
                cout
                    << "    Are you sure you want to save to Slot[C]?\n\n"
                    << "Note: Any data previously stored in this slot will be\n"
                    << "      overwritten.\n"
                    << "<ENTER [Y] TO CONTINUE OR [N] TO CANCEL>\n";
                user_choice = reader.readChar("YyNn");
                ClearScreen();
                switch (toupper(user_choice)) {
                  case 'N':
                    break;
                  case 'Y':
                    out_stream.open("slotC.txt");
                    out_stream << pc.GetFname() << endl << pc.GetLname() << endl
                               << pc.GetClass() << endl << pc.GetStr() << endl
                               << pc.GetDex() << endl << pc.GetInt() << endl
                               << pc.GetHp() << endl << pc.GetSp() << endl
                               << pc.GetFind() << endl << pc.GetXp() << endl
                               << pc.GetAc() << endl << pc.GetGold() << endl
                               << pc.GetWeap() << endl << pc.GetArmor() << endl
                               << pc.GetKey() << endl << pc.GetAlch() << endl
                               << pc.GetPotion() << endl << pc.GetVita() << endl
                               << pc.GetDagger() << endl << pc.GetBSword()
                               << endl << pc.GetSSword() << endl
                               << pc.GetLSword() << endl << pc.GetLArmor()
                               << endl << pc.GetPMail() << endl
                               << pc.GetAmulet() << endl
                               << room_32.GetRoomNum();
                    out_stream.close();
                    cout << "Character Saved Successfully!\n";
                    break;
                }
                break;
            }
            EnterToContinue();
            ClearScreen();
            break;
          case 'H':
            pc.SetXp(ContinueGame(room_32.Battle()));
            pc.SetGold(room_32.GoldGained());
            pc.SetUsables(room_32.GetNewAlch(), room_32.GetNewPotion(),
                          room_32.GetNewVita());
            EnterToContinue();
            break;
          case 'L':
            cout
                << "That door is locked.  If you have a key, you can try to open it.\n";
            EnterToContinue();
            ClearScreen();
            break;
          }
          break;
        case 1:
          pc.SetXp(ContinueGame(room_32.Battle()));
          pc.SetGold(room_32.GoldGained());
          pc.SetUsables(room_32.GetNewAlch(), room_32.GetNewPotion(),
                        room_32.GetNewVita());
          EnterToContinue();
          break;
      }
    }
    //start adding locations for rooms here when you are ready to set up the game world!

  } while (toupper(play_game_) == 'Y');
  cout << "Perhaps another time..." << endl;
}

//Function to Introduce the game
void Game::GameIntro() {
  cout
      << "     -Welcome to "
      << game_name_
      << "-\n"

//This next section should change if you decide to change the name of the game from default
      << "You are about to embark on a quest to find\n"
      << "the truth about your family's past.\n" << "\n"
      << "But to do so you must brave the depths of\n"
      << "an ancient catacomb, uncover the relics\n"
      << "hidden below, and live to tell the tale!\n" << "\n"
      << "Do you wish to proceed?\n" << "<PRESS [Y] TO PLAY OR [N] TO EXIT>\n"
      << "\n";
  play_game_ = reader.readChar("YyNn");

  if (toupper(play_game_) == 'Y') {
    cout << "       Would you like to:\n" << "\n"
         << "     Start a [N]ew Character\n" << "              or\n"
         << "             [L]oad a Saved Game\n" << "\n";
    new_game_ = reader.readChar("NnLl");
  }
}

//Function to Rename the Game
void Game::NameGame(string game_name) {
  game_name_ = game_name;
}

//function to let the user continue their game if they die
int Game::ContinueGame(int cont) {
  if (cont == 0) {
    cout << "     Would you like to continue playing?\n"
         << "    <PRESS [Y] TO CONTINUE OR [N] TO EXIT>\n" << endl;
    play_game_ = reader.readChar("YyNn");
    if (toupper(play_game_) == 'Y') {
      current_loc_x_ = 0;
      current_loc_y_ = 1;
    }
    return 0;
  } else {
    return cont;
  }
}

//function that changes the character's location
void Game::SetLoc(int direction) {
  switch (direction) {
    case kNorth:
      current_loc_y_++;
      break;
    case kSouth:
      current_loc_y_--;
      break;
    case kEast:
      current_loc_x_++;
      break;
    case kWest:
      current_loc_x_--;
      break;
  }
}
//Function to force the user to press enter to continue
void Game::EnterToContinue() {
  string press_enter;
  cout << "                     <PRESS [ENTER] TO CONTINUE>\n" << endl;
  press_enter = reader.readString(true, 0);
}
//PC Constructor for new characters
PlayerCharacter::PlayerCharacter() {
  xp_ = 0;
  ac_ = 0;
  char_class_ = 0;
  str_ = 0;
  dex_ = 0;
  int_ = 0;
  find_ = 0;
  hp_ = 0;
  sp_ = 0;
  accept_name_ = 0;
  weap_equip_ = kDagger;
  armor_equip_ = 0;
  gold_ = 100;
  inventory_[kDagger] = 1;
  inventory_[kShortSword] = 0;
  inventory_[kLongSword] = 0;
  inventory_[kBastardSword] = 0;
  inventory_[kLeatherArmor] = 0;
  inventory_[kPlateMail] = 0;
  inventory_[kHealthPotion] = 2;
  inventory_[kAlchemistFire] = 0;
  inventory_[kKey] = 0;
  inventory_[kVitaPotion] = 1;
  inventory_[kAmulet] = 0;
}

//PC naming function
void PlayerCharacter::SetName() {
  do {
    cout << "Please enter your character's first name:\n" << "\n";
    f_name_ = reader.readString();

    cout << "Please enter your character's family name:\n" << "\n";
    l_name_ = reader.readString();

    cout << "You entered : " << f_name_ << " of Clan " << l_name_ << "\n"
         << "Is this correct?\n" << "<PRESS [Y] TO ACCEPT OR [N] TO RENAME>\n"
         << endl;

    accept_name_ = reader.readChar("YyNn");
  } while (toupper(accept_name_) == 'N');
}

//Function to set the character's class
void PlayerCharacter::SetClass(char char_class) {
  char_class_ = char_class;
  switch (toupper(char_class_)) {
    case 'M':
      str_ = 1;
      dex_ = 2;
      int_ = 4;
      hp_ = 10;
      sp_ = 30;
      find_ = 5;
      break;
    case 'R':
      str_ = 2;
      dex_ = 4;
      int_ = 2;
      hp_ = 15;
      sp_ = 10;
      find_ = 20;
      break;
    case 'W':
      str_ = 4;
      dex_ = 3;
      int_ = 1;
      hp_ = 20;
      sp_ = 5;
      find_ = 5;
      break;
  }
  ac_ = (dex_ + 5);
}
//Character Sheet Output function
void PlayerCharacter::ViewSheet() {
  cout
      << "+--------------------------------------------------------------------+\n"
      << "|                                                                    |\n"
      << "|  Name: "
      << f_name_
      << " of Clan "
      << l_name_
      << "\n"
      << "|                                                                    |\n"
      << "|  Class: ";
  switch (toupper(char_class_)) {
    case 'M':
      cout << "Mage         Experience: " << xp_ << "\n";
      break;
    case 'R':
      cout << "Rogue        Experience: " << xp_ << "\n";
      break;
    case 'W':
      cout << "Warrior      Experience: " << xp_ << "\n";
      break;
  }
  cout
      << "|                                                                    |\n"
      << "|   Strength:     "
      << str_
      << "        Health: "
      << hp_
      << "      Skill Points: "
      << sp_
      << "\n"
      << "|   Dexterity:    "
      << dex_
      << "          Armor Class: "
      << ac_
      << "\n"
      << "|   Intelligence: "
      << int_
      << "          ATK Damage: "
      << (str_ + weap_equip_)
      << "\n"
      << "|                            Find Secrets: "
      << find_
      << "\n"
      << "|        Gold: "
      << gold_
      << "\n"
      << "|                                                                    |\n"
      << "|                          -Inventory-                               |\n"
      << "|       Item             ATK   AC   QTY   Equipped                   |\n"
      << "|  -------------------------------------------------------           |\n"
      << "|                                                                    |\n"
      << "|                         ***Usables***                              |\n";
  if (inventory_[kAlchemistFire] > 0) {
    cout << "|    Alchemist Fire       7     -    "
         << inventory_[kAlchemistFire] << " \n";
  }
  if (inventory_[kHealthPotion] > 0) {
    cout << "|    Health Potion        -     -    " << inventory_[kHealthPotion]
         << " \n";
  }
  if (inventory_[kKey] > 0) {
    cout << "|    Key                  -     -    " << inventory_[kKey]
         << " \n";
  }
  if (inventory_[kVitaPotion] > 0) {
    cout << "|    Vita Potion          -     -    " << inventory_[kVitaPotion]
         << " \n";
  }
  cout
      << "|                         ***Weapons***                              |\n";
  if (inventory_[kBastardSword] > 0) {
    cout << "|    Bastard Sword        4     -    " << inventory_[kBastardSword]
         << "       ";
    if (weap_equip_ == kBastardSword) {
      cout << "+";
    }
    cout << "\n";
  }
  if (inventory_[kDagger] > 0) {
    cout << "|    Dagger               1     -    " << inventory_[kDagger]
         << "       ";
    if (weap_equip_ == kDagger) {
      cout << "+";
    }
    cout << " \n";
  }
  if (inventory_[kLongSword] > 0) {
    cout << "|    Long Sword           3     -    " << inventory_[kLongSword]
         << "       ";
    if (weap_equip_ == kLongSword) {
      cout << "+";
    }
    cout << "\n";
  }
  if (inventory_[kShortSword] > 0) {
    cout << "|    Short Sword          2     -    " << inventory_[kShortSword]
         << "       ";
    if (weap_equip_ == kShortSword) {
      cout << "+";
    }
    cout << "\n";
  }
  cout
      << "|                          ***Armor***                               |\n";
  if (inventory_[kLeatherArmor] > 0) {
    cout << "|    Leather Armor        -     5    " << inventory_[kLeatherArmor]
         << "       ";
    if (armor_equip_ == kLeatherArmor) {
      cout << "+";
    }
    cout << "\n";
  }
  if (inventory_[kPlateMail] > 0) {
    cout << "|    Plate Mail           -     6    " << inventory_[kPlateMail]
         << "       ";
    if (armor_equip_ == kPlateMail) {
      cout << "+";
    }
    cout << "\n";
  }
  if (inventory_[kAmulet] > 0) {
    cout
        << "|                         ***Special***                              |\n"
        << "|    Amulet Heirloom      -     -    " << inventory_[kAmulet]
        << "       \n";
  }
  cout
      << "|                                                                    |\n"
      << "+--------------------------------------------------------------------+\n";
}

//Functions that return the character's data
string PlayerCharacter::GetLname() {
  return l_name_;
}

string PlayerCharacter::GetFname() {
  return f_name_;
}
char PlayerCharacter::GetClass() {
  return char_class_;
}
int PlayerCharacter::GetStr() {
  return str_;
}
int PlayerCharacter::GetDex() {
  return dex_;
}
int PlayerCharacter::GetInt() {
  return int_;
}
int PlayerCharacter::GetHp() {
  return hp_;
}
int PlayerCharacter::GetSp() {
  return sp_;
}
int PlayerCharacter::GetFind() {
  return find_;
}
int PlayerCharacter::GetXp() {
  return xp_;
}
int PlayerCharacter::GetAc() {
  return ac_;
}
int PlayerCharacter::GetGold() {
  return gold_;
}
int PlayerCharacter::GetWeap() {
  return weap_equip_;
}
int PlayerCharacter::GetArmor() {
  return armor_equip_;
}
int PlayerCharacter::GetKey() {
  return inventory_[kKey];
}
int PlayerCharacter::GetAlch() {
  return inventory_[kAlchemistFire];
}
int PlayerCharacter::GetPotion() {
  return inventory_[kHealthPotion];
}
int PlayerCharacter::GetVita() {
  return inventory_[kVitaPotion];
}
int PlayerCharacter::GetDagger() {
  return inventory_[kDagger];
}
int PlayerCharacter::GetBSword() {
  return inventory_[kBastardSword];
}
int PlayerCharacter::GetSSword() {
  return inventory_[kShortSword];
}
int PlayerCharacter::GetLSword() {
  return inventory_[kLongSword];
}
int PlayerCharacter::GetLArmor() {
  return inventory_[kLeatherArmor];
}
int PlayerCharacter::GetPMail() {
  return inventory_[kPlateMail];
}
int PlayerCharacter::GetAmulet() {
  return inventory_[kAmulet];
}
//function for the character to gain exp
void PlayerCharacter::SetXp(int xp_gained) {
  if (xp_gained == 0) {
  } else {
    cout << "   -The battle is over-\n" << "Your XP:   " << xp_ << "\n"
         << "XP Gained: " << xp_gained << "\n";
    xp_ += xp_gained;
    cout << "XP Total: " << xp_ << "\n\n";
  }
}
//function for the character to gain gold
void PlayerCharacter::SetGold(int gold_gained) {
  if (gold_gained == 0) {
  } else {
    cout << "Your Gold: " << gold_ << "\n" << "Gold Gained: " << gold_gained
         << "\n";
    gold_ += gold_gained;
    cout << "Gold Total: " << gold_ << "\n";
  }
}

//Function to give the character loot
void PlayerCharacter::SetInventory(int item_enum, int item_num) {
  inventory_[item_enum] += item_num;
}

//function to equip the character's gear
void PlayerCharacter::SetGear() {
  bool user_loop = true;
  char user_selection;
  string options = "Ee", add_options;
  do {
    cout << "    ***Would you like to equip [A]rmor or [W]eapons?***\n" << "\n"
         << "                        [E]xit\n";
    user_selection = reader.readChar("AaWwEe");
    ClearScreen();
    switch (toupper(user_selection)) {
      case 'A':
        add_options = "LlPp";
        cout << "Which suit of Armor would you like to equip?\n" << "\n";
        if (inventory_[kLeatherArmor] > 0) {
          cout << "   +[L]eather Armor     Ac Bonus: " << kLeatherArmor << endl;
          options.append(add_options, 0, 2);
        }
        if (inventory_[kPlateMail] > 0) {
          cout << "   +[P]late Mail        Ac Bonus: " << kPlateMail << endl;
          options.append(add_options, 2, 2);
        }
        cout << "             [E]xit\n";
        user_selection = reader.readChar(options);
        ClearScreen();
        switch (toupper(user_selection)) {
          case 'L':
            ac_ -= armor_equip_;
            armor_equip_ = kLeatherArmor;
            ac_ += armor_equip_;
            cout << "Leather Armor Equipped!\n";
            break;
          case 'P':
            ac_ -= armor_equip_;
            armor_equip_ = kPlateMail;
            ac_ += armor_equip_;
            cout << "Plate Mail Equipped!\n";
            break;
          case 'E':
            break;
        }
        break;
      case 'W':
        add_options = "BbDdLlSs";
        cout << "Which Weapon would you like to equip?\n" << "\n";
        if (inventory_[kBastardSword] > 0) {
          cout << "   +[B]astard Sword  ATK Bonus: 4\n";
          options.append(add_options, 0, 2);
        }
        if (inventory_[kDagger] > 0) {
          cout << "   +[D]agger         ATK Bonus: 1\n";
          options.append(add_options, 2, 2);
        }
        if (inventory_[kLongSword] > 0) {
          cout << "   +[L]ong Sword     ATK Bonus: 3\n";
          options.append(add_options, 4, 2);
        }
        if (inventory_[kShortSword] > 0) {
          cout << "   +[S]hort Sword    ATK Bonus: 2\n";
          options.append(add_options, 6, 2);
        }
        cout << "             [E]xit\n";
        user_selection = reader.readChar(options);
        ClearScreen();
        switch (toupper(user_selection)) {
          case 'B':
            weap_equip_ = kBastardSword;
            cout << "Bastard Sword Equipped!\n";
            break;
          case 'D':
            weap_equip_ = kDagger;
            cout << "Dagger Equipped!\n";
            break;
          case 'L':
            weap_equip_ = kLongSword;
            cout << "Long Sword Equipped!\n";
            break;
          case 'S':
            weap_equip_ = kShortSword;
            cout << "Short Sword Equipped!\n";
            break;
          case 'E':
            break;
        }
        break;
      case 'E':
        user_loop = false;
        break;
    }
  } while (user_loop == true);
}

//function to update usable item totals after battle
void PlayerCharacter::SetUsables(int alch, int potion, int vita) {
  inventory_[kAlchemistFire] = alch;
  inventory_[kHealthPotion] = potion;
  inventory_[kVitaPotion] = vita;
}

//Function to set all variables for a character, used to load a previously saved character
void PlayerCharacter::SetCharacter(string fname, string lname, char char_class,
                                   int str, int dex, int intel, int hp, int sp,
                                   int find, int xp, int ac, int gold,
                                   int weap_equip, int armor_equip, int key,
                                   int alch, int potion, int vita, int dagger,
                                   int bsword, int ssword, int lsword,
                                   int larmor, int pmail, int amulet) {
  f_name_ = fname;
  l_name_ = lname;
  char_class_ = char_class;
  str_ = str;
  dex_ = dex;
  int_ = intel;
  hp_ = hp;
  sp_ = sp;
  find_ = find;
  xp_ = xp;
  ac_ = ac;
  gold_ = gold;
  weap_equip_ = weap_equip;
  armor_equip_ = armor_equip;
  inventory_[kKey] = key;
  inventory_[kAlchemistFire] = alch;
  inventory_[kHealthPotion] = potion;
  inventory_[kVitaPotion] = vita;
  inventory_[kDagger] = dagger;
  inventory_[kBastardSword] = bsword;
  inventory_[kShortSword] = ssword;
  inventory_[kLongSword] = lsword;
  inventory_[kLeatherArmor] = larmor;
  inventory_[kPlateMail] = pmail;
  inventory_[kAmulet] = amulet;
}
//function that lets the character buy gear/stats
void PlayerCharacter::Shop(int shop_request) {
  char user_choice, confirm_choice, user_loop = 'Y';
  string options, add_options;
  switch (shop_request) {
    case 0:
      break;
    case 1:
      do {
        cout
            << "     \"You wish to become a more fierce opponent for the denizens\n"
            << "     of this tomb, eh?  Can't say as I blame you.  Let us see...\n"
            << "\n" << "              ***What would you like to Improve?***\n"
            << "\n" << "     [S]trength - " << (str_ * 100) << " Experience\n"
            << "     [D]exterity - " << (dex_ * 100) << " Experience\n"
            << "     [I]ntelligence - " << (int_ * 100) << " Experience\n"
            << "\n" << "      Your Current Experience: " << xp_ << "\n"
            << "[E]xit\n";
        user_choice = reader.readChar("SsDdIiEe");
        switch (toupper(user_choice)) {
          case 'S':
            if (xp_ < (str_ * 100)) {
              cout
                  << "     \"I am so sorry, but you do not have enough Experience to\n"
                  << "     advance in this area.  Try raising a different stat, or\n"
                  << "     gaining more Experience first.\n";
              EnterToContinue();
            } else {
              cout
                  << "You want to spend "
                  << (str_ * 100)
                  << " Experience to raise your Strength?\n"
                  << "        <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
              confirm_choice = reader.readChar("YyNn");
              switch (toupper(confirm_choice)) {
                case 'Y':
                  xp_ -= (str_ * 100);
                  str_++;
                  hp_ += 10;
                  break;
                case 'N':
                  break;
              }
            }
            break;
          case 'D':
            if (xp_ < (dex_ * 100)) {
              cout
                  << "     \"I am so sorry, but you do not have enough Experience to\n"
                  << "     advance in this area.  Try raising a different stat, or\n"
                  << "     gaining more Experience first.\n";
              EnterToContinue();
            } else {
              cout
                  << "You want to spend "
                  << (dex_ * 100)
                  << " Experience to raise your Dexterity?\n"
                  << "        <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
              confirm_choice = reader.readChar("YyNn");
              switch (toupper(confirm_choice)) {
                case 'Y':
                  xp_ -= (dex_ * 100);
                  dex_++;
                  hp_ += 7;
                  find_ += 5;
                  ac_++;
                  break;
                case 'N':
                  break;
              }
            }
            break;
          case 'I':
            if (xp_ < (int_ * 100)) {
              cout
                  << "     \"I am so sorry, but you do not have enough Experience to\n"
                  << "     advance in this area.  Try raising a different stat, or\n"
                  << "     gaining more Experience first.\n";
              EnterToContinue();
            } else {
              cout
                  << "You want to spend "
                  << (int_ * 100)
                  << " Experience to raise your Intelligence?\n"
                  << "        <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
              confirm_choice = reader.readChar("YyNn");
              switch (toupper(confirm_choice)) {
                case 'Y':
                  xp_ -= (int_ * 100);
                  int_++;
                  hp_ += 5;
                  sp_ += 10;
                  break;
                case 'N':
                  break;
              }
            }
            break;
          case 'E':
            user_loop = 'N';
            break;
        }
        ClearScreen();
      } while (user_loop == 'Y');
      break;
    case 2:
      do {
        cout
            << "     \"Buying new equipment can give you a leg up in battle, and\n"
            << "     possibly save your life!  Let us see what I have in stock...\n"
            << "\n"
            << "                  ***What would you like to see?***\n\n"
            << "         [A]rmor        [I]tems        [W]eapons        [S]ell\n"
            << "                               [E]xit\n";
        user_choice = reader.readChar("AaIiWwEeSs");
        ClearScreen();
        switch (toupper(user_choice)) {
          case 'S':
            int sellable_total;
            user_loop = true;
            do {
              options = "Ee";
              add_options = "AaBbDdHhKkRrLlPpSsVv";
              cout
                  << "\"Sell off your old equipment in order to buy new items of\n"
                  << "greater worth to your cause.  What would you like to sell?\"\n"
                  << "\n"
                  << "          Item           Avail to Sell        Price\n"
                  << "  -------------------------------------------------------\n";
              if (inventory_[kAlchemistFire] > 0) {
                sellable_total = inventory_[kAlchemistFire];
                cout << "   -[A]lchemist Fire           " << sellable_total
                     << "             100 Gold\n";
                options.append(add_options, 0, 2);
              }
              if (inventory_[kBastardSword] > 0) {
                if (weap_equip_ == kBastardSword) {
                  sellable_total = inventory_[kBastardSword] - 1;
                } else {
                  sellable_total = inventory_[kBastardSword];
                }
                if (sellable_total > 0) {
                  cout << "   -[B]astard Sword            " << sellable_total
                       << "             800 Gold\n";
                  options.append(add_options, 2, 2);
                }
              }
              if (inventory_[kDagger] > 0) {
                if (weap_equip_ == kDagger) {
                  sellable_total = inventory_[kDagger] - 1;
                } else {
                  sellable_total = inventory_[kDagger];
                }
                if (sellable_total > 0) {
                  cout << "   -[D]agger                   " << sellable_total
                       << "             100 Gold\n";
                  options.append(add_options, 4, 2);
                }
              }
              if (inventory_[kHealthPotion] > 0) {
                sellable_total = inventory_[kHealthPotion];
                cout << "   -[H]ealth Potion            " << sellable_total
                     << "              50 Gold\n";
                options.append(add_options, 6, 2);
              }
              if (inventory_[kKey] > 0) {
                sellable_total = inventory_[kKey];
                cout << "   -[K]ey                      " << sellable_total
                     << "              75 Gold\n";
                options.append(add_options, 8, 2);
              }
              if (inventory_[kLeatherArmor] > 0) {
                if (weap_equip_ == kLeatherArmor) {
                  sellable_total = inventory_[kLeatherArmor] - 1;
                } else {
                  sellable_total = inventory_[kLeatherArmor];
                }
                if (sellable_total > 0) {
                  cout << "   -Leather A[R]mor            " << sellable_total
                       << "             500 Gold\n";
                  options.append(add_options, 10, 2);
                }
              }
              if (inventory_[kLongSword] > 0) {
                if (weap_equip_ == kLongSword) {
                  sellable_total = inventory_[kLongSword] - 1;
                } else {
                  sellable_total = inventory_[kLongSword];
                }
                if (sellable_total > 0) {
                  cout << "   -[L]ong Sword               " << sellable_total
                       << "             550 Gold\n";
                  options.append(add_options, 12, 2);
                }
              }
              if (inventory_[kPlateMail] > 0) {
                if (weap_equip_ == kPlateMail) {
                  sellable_total = inventory_[kPlateMail] - 1;
                } else {
                  sellable_total = inventory_[kPlateMail];
                }
                if (sellable_total > 0) {
                  cout << "   -[P]late Mail               " << sellable_total
                       << "             750 Gold\n";
                  options.append(add_options, 14, 2);
                }
              }
              if (inventory_[kShortSword] > 0) {
                if (weap_equip_ == kShortSword) {
                  sellable_total = inventory_[kShortSword] - 1;
                } else {
                  sellable_total = inventory_[kShortSword];
                }
                if (sellable_total > 0) {
                  cout << "   -[S]hort Sword              " << sellable_total
                       << "             250 Gold\n";
                  options.append(add_options, 16, 2);
                }
              }
              if (inventory_[kVitaPotion] > 0) {
                sellable_total = inventory_[kVitaPotion];
                cout << "   -[V]ita Potion              " << sellable_total
                     << "              40 Gold\n";
                options.append(add_options, 18, 2);
              }
              cout
                  << "  -------------------------------------------------------\n"
                  << "         [E]xit \n" << "  Your Gold: " << gold_ << endl;
              user_choice = reader.readChar(options);
              switch (toupper(user_choice)) {
                case 'E':
                  user_loop = false;
                  break;
                case 'A':
                  cout
                      << "You want to sell an Alchemist Fire for 100 Gold?\n"
                      << " <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      inventory_[kAlchemistFire]--;
                      gold_ += 100;
                  }
                  break;
                case 'B':
                  cout
                      << "You want to sell a Bastard Sword for 800 Gold?\n"
                      << " <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      inventory_[kBastardSword]--;
                      gold_ += 800;
                  }
                  break;
                case 'D':
                  cout
                      << "You want to sell a Dagger for 100 Gold?\n"
                      << " <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      inventory_[kDagger]--;
                      gold_ += 100;
                  }
                  break;
                case 'H':
                  cout
                      << "You want to sell a Health Potion for 50 Gold?\n"
                      << " <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      inventory_[kHealthPotion]--;
                      gold_ += 50;
                  }
                  break;
                case 'K':
                  cout
                      << "You want to sell a Key for 75 Gold?\n"
                      << " <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      inventory_[kKey]--;
                      gold_ += 75;
                  }
                  break;
                case 'R':
                  cout
                      << "You want to sell a suit of Leather Armor for 500 Gold?\n"
                      << " <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      inventory_[kLeatherArmor]--;
                      gold_ += 500;
                  }
                  break;
                case 'L':
                  cout
                      << "You want to sell a Long Sword for 550 Gold?\n"
                      << " <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      inventory_[kLongSword]--;
                      gold_ += 550;
                  }
                  break;
                case 'P':
                  cout
                      << "You want to sell a suit of Plate Mail for 750 Gold?\n"
                      << " <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      inventory_[kPlateMail]--;
                      gold_ += 750;
                  }
                  break;
                case 'S':
                  cout
                      << "You want to sell a Short Sword for 250 Gold?\n"
                      << " <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      inventory_[kShortSword]--;
                      gold_ += 250;
                  }
                  break;
                case 'V':
                  cout
                      << "You want to sell a Vita Potion for 40 Gold?\n"
                      << " <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      inventory_[kVitaPotion]--;
                      gold_ += 40;
                  }
                  break;
              }
              ClearScreen();
            } while (user_loop == true);
            break;
          case 'A':
            user_loop = true;
            do {
              cout
                  << "     \"This is what I have for someone of your particular talent...\"\n"
                  << "\n";
              if (str_ > 3) {
                cout << "  -[L]eather Armor-    Ac Bonus: 4  Cost: 500 Gold\n";
              }
              if (str_ > 6) {
                cout << "  -[P]late Mail Armor- Ac Bonus: 5  Cost: 750 Gold\n";
              }
              cout << "    [E]xit\n" << "  Your Gold: " << gold_ << endl;
              if (str_ > 6 && char_class_ == 'W') {
                user_choice = reader.readChar("PpLlEe");
              } else if (str_ > 3) {
                user_choice = reader.readChar("LlEe");
              } else {
                user_choice = reader.readChar("Ee");
              }
              switch (toupper(user_choice)) {
                case 'P':
                  cout
                      << "You want to spend 750 Gold on a suit of Plate Mail?\n"
                      << "        <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      if (gold_ < 750) {
                        cout
                            << "Sorry, you cannot afford this item.  Go find more gold!\n";
                        EnterToContinue();
                      } else {
                        inventory_[kPlateMail]++;
                        gold_ -= 750;
                      }
                      break;
                  }
                  break;
                case 'L':
                  cout
                      << "You want to spend 500 Gold on a suit of Leather Armor?\n"
                      << "        <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      if (gold_ < 500) {
                        cout
                            << "Sorry, you cannot afford this item.  Go find more gold!\n";
                        EnterToContinue();
                      } else {
                        inventory_[kLeatherArmor]++;
                        gold_ -= 500;
                      }
                      break;
                  }
                  break;
                case 'E':
                  user_loop = false;
                  break;
              }
              ClearScreen();
            } while (user_loop == true);
            break;
          case 'W':
            do {
              options = "DdEe";
              add_options = "BbLlSs";
              cout
                  << "     \"This is what I have for someone of your particular talent...\"\n"
                  << "\n";
              if (str_ > 7) {
                cout << "  -[B]astard Sword- ATK Bonus: 4  Cost: 800 Gold\n";
                options.append(add_options, 0, 2);
              }
              cout << "  -[D]agger-        ATK Bonus: 1  Cost: 100 Gold\n";
              if (str_ > 5) {
                cout << "  -[L]ong Sword-    ATK Bonus: 3  Cost: 550 Gold\n";
                options.append(add_options, 2, 2);
              }
              if (str_ > 1) {
                cout << "  -[S]hort Sword-   ATK Bonus: 2  Cost: 250 Gold\n";
                options.append(add_options, 4, 2);
              }
              cout << "               [E]xit\n" << "  Your Gold: " << gold_
                   << endl;
              user_choice = reader.readChar(options);
              switch (toupper(user_choice)) {
                case 'D':
                  cout
                      << "You want to spend 100 Gold on a Dagger?\n"
                      << "        <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      if (gold_ < 100) {
                        cout
                            << "Sorry, you cannot afford this item.  Go find more gold!\n";
                        EnterToContinue();
                      } else {
                        inventory_[kDagger]++;
                        gold_ -= 100;
                      }
                      break;
                  }
                  break;
                case 'E':
                  user_loop = false;
                  break;
                case 'B':
                  cout
                      << "You want to spend 800 Gold on a Bastard Sword?\n"
                      << "        <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      if (gold_ < 800) {
                        cout
                            << "Sorry, you cannot afford this item.  Go find more gold!\n";
                        EnterToContinue();
                      } else {
                        inventory_[kBastardSword]++;
                        gold_ -= 800;
                      }
                      break;
                  }
                  break;
                case 'L':
                  cout
                      << "You want to spend 550 Gold on a Long Sword?\n"
                      << "        <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      if (gold_ < 550) {
                        cout
                            << "Sorry, you cannot afford this item.  Go find more gold!\n";
                        EnterToContinue();
                      } else {
                        inventory_[kLongSword]++;
                        gold_ -= 550;
                      }
                      break;
                  }
                  break;
                case 'S':
                  cout
                      << "You want to spend 250 Gold on a Short Sword?\n"
                      << "        <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      if (gold_ < 250) {
                        cout
                            << "Sorry, you cannot afford this item.  Go find more gold!\n";
                        EnterToContinue();
                      } else {
                        inventory_[kShortSword]++;
                        gold_ -= 250;
                      }
                      break;
                  }
                  break;
              }
              ClearScreen();
            } while (user_loop == true);
            break;
          case 'I':
            user_loop = true;
            do {
              options = "HhKkVvEe";
              add_options = "Aa";
              cout
                  << "     \"These items can be the difference between life and death.\n"
                  << "     Don't forget to stock up!!!\"\n" << "\n";
              if (int_ > 7 || dex_ > 7) {
                cout
                    << "  -[A]lchemist Fire-  Cost: 100 Gold  -Deals 7 Damage in Battle\n";
                options.append(add_options, 0, 2);
              }
              cout
                  << "  -[H]ealth Potion-   Cost: 50 Gold   -Heals 10 HP in Battle\n"
                  << "  -[K]ey-             Cost: 75 Gold   -Unlocks Standard Doors\n"
                  << "  -[V]ita Potion-     Cost: 40 Gold   -Restores 10 SP in Battle\n"
                  << "               [E]xit\n" << "  Your Gold: " << gold_
                  << endl;
              user_choice = reader.readChar(options);
              switch (toupper(user_choice)) {
                case 'E':
                  user_loop = false;
                  break;
                case 'A':
                  cout
                      << "You want to spend 100 Gold on an Alchemist Fire?\n"
                      << "        <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      if (gold_ < 100) {
                        cout
                            << "Sorry, you cannot afford this item.  Go find more gold!\n";
                        EnterToContinue();
                      } else {
                        inventory_[kAlchemistFire]++;
                        gold_ -= 100;
                      }
                      break;
                  }
                  break;
                case 'H':
                  cout
                      << "You want to spend 50 Gold on a Health Potion?\n"
                      << "        <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      if (gold_ < 50) {
                        cout
                            << "Sorry, you cannot afford this item.  Go find more gold!\n";
                        EnterToContinue();
                      } else {
                        inventory_[kHealthPotion]++;
                        gold_ -= 50;
                      }
                      break;
                  }
                  break;
                case 'K':
                  cout
                      << "You want to spend 75 Gold on a Key?\n"
                      << "        <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      if (gold_ < 75) {
                        cout
                            << "Sorry, you cannot afford this item.  Go find more gold!\n";
                        EnterToContinue();
                      } else {
                        inventory_[kKey]++;
                        gold_ -= 75;
                      }
                      break;
                  }
                  break;
                case 'V':
                  cout
                      << "You want to spend 40 Gold on a Vita Potion?\n"
                      << "        <ENTER [Y] TO CONFIRM OR [N] TO CANCEL THIS TRANSACTION>\n";
                  confirm_choice = reader.readChar("YyNn");
                  switch (toupper(confirm_choice)) {
                    case 'N':
                      break;
                    case 'Y':
                      if (gold_ < 40) {
                        cout
                            << "Sorry, you cannot afford this item.  Go find more gold!\n";
                        EnterToContinue();
                      } else {
                        inventory_[kVitaPotion]++;
                        gold_ -= 40;
                      }
                      break;
                  }
                  break;
              }
              ClearScreen();
            } while (user_loop == true);
            break;
          case 'E':
            user_loop = 'N';
            break;
        }
        ClearScreen();
      } while (user_loop == 'Y');
      break;
  }
}
//function that forces the user to press enter to continue
void PlayerCharacter::EnterToContinue() {
  string press_enter;
  cout << "                     <PRESS [ENTER] TO CONTINUE>\n" << endl;
  press_enter = reader.readString(true, 0);
}

//Room Zero Constructor
Room::Room() {
  room_num_ = 0;
  room_diff_ = 1;
  door_num_ = 3;
  enemy_num_ = 0;
  door_[kNorth] = 0;
  door_[kSouth] = 1;
  door_[kEast] = 1;
  door_[kWest] = 2;
  enemy_aware_ = false;
  enemy_hidden_ = false;
  npc_present_ = true;
  npc_aware_ = false;
  secret_found_ = true;
  room_material_ = "Stone";
  enemy_type_ = kGoblin;
  gold_gained_ = 0;
  pc_hp_ = 0;
  pc_sp_ = 0;
  pc_ac_ = 0;
  pc_str_ = 0;
  pc_dex_ = 0;
  pc_int_ = 0;
  pc_find_ = 0;
  pc_xp_ = 0;
  pc_gold_ = 0;
  pc_weap_ = 0;
  pc_key_ = 0;
  pc_alch_ = 0;
  pc_potion_ = 0;
  pc_vita_ = 0;
  pc_amulet_ = 0;
  gold_gained_ = 0;
}

//Other Rooms Constructor
Room::Room(int room_num, int room_diff, int door_num, int enemy_num,
           int enemy_type, int north_door, int south_door, int east_door,
           int west_door, bool enemy_aware, bool enemy_hidden, bool npc_present,
           bool npc_aware, bool secret_found, string room_material) {
  room_num_ = room_num;
  room_diff_ = room_diff;
  door_num_ = door_num;
  enemy_num_ = enemy_num;
  door_[kNorth] = north_door;
  door_[kSouth] = south_door;
  door_[kEast] = east_door;
  door_[kWest] = west_door;
  enemy_aware_ = enemy_aware;
  enemy_hidden_ = enemy_hidden;
  npc_present_ = npc_present;
  npc_aware_ = npc_aware;
  secret_found_ = secret_found;
  room_material_ = room_material;
  enemy_type_ = enemy_type;
  gold_gained_ = 0;
  pc_hp_ = 0;
  pc_sp_ = 0;
  pc_ac_ = 0;
  pc_str_ = 0;
  pc_dex_ = 0;
  pc_int_ = 0;
  pc_find_ = 0;
  pc_xp_ = 0;
  pc_gold_ = 0;
  pc_weap_ = 0;
  pc_key_ = 0;
  pc_alch_ = 0;
  pc_potion_ = 0;
  pc_vita_ = 0;
  pc_amulet_ = 0;
  gold_gained_ = 0;
}

//Function to describe a room
void Room::DescribeRoom() {
  cout << "    You enter a " << room_material_ << " room with ";
  if (door_num_ > 1) {
    cout << door_num_ << " doors, " << "on the ";
    for (int i = door_num_; i > 0;) {
      if (door_[kEast] != 0 && i > 2) {
        cout << "East, ";
        i--;
      } else if (door_[kEast] != 0 && i == 2) {
        cout << "East and ";
        i--;
      }
      if (door_[kWest] != 0 && i > 2) {
        cout << "West, ";
        i--;
      } else if (door_[kWest] != 0 && i == 2) {
        cout << "West, and ";
        i--;
      } else if (door_[kWest] != 0 && i == 1) {
        cout << "West.\n";
        i--;
      }
      if (door_[kNorth] != 0 && i > 2) {
        cout << "North, ";
        i--;
      } else if (door_[kNorth] != 0 && i == 2) {
        cout << "North, and ";
        i--;
      } else if (door_[kNorth] != 0 && i == 1) {
        cout << "North.\n";
        i--;
      }
      if (door_[kSouth] != 0) {
        cout << "South.\n";
        i--;
      }
    }
  }
  if (door_num_ == 1) {
    cout << door_num_ << " door, " << "on the ";
    if (door_[kEast] != 0) {
      cout << "East.\n";
    }
    if (door_[kWest] != 0) {
      cout << "West.\n";
    }
    if (door_[kNorth] != 0) {
      cout << "North.\n";
    }
    if (door_[kSouth] != 0) {
      cout << "South.\n";
    }
  }
  if (door_num_ == 0) {
    cout << "no doors.\n" << "\n"
         << "    Wait...no doors? But then how did you get in here?";
  }
  cout << "\n";
  if (npc_present_ == true) {
    cout << "You see an elderly man with a friendly face, ";
    if (npc_aware_ == false) {
      cout << "but it looks like he is sleeping...\n";
    } else {
      cout << "and he seems pleased to see you!\n";
    }
  }
  if (enemy_hidden_ == true) {
    cout
        << "\n"
        << "The room's corners are cluttered with boxes, barrels, and empty bottles.\n";
  }
  cout << "\n";
}

//function that displays the UI for interacting with the room, returns user choice
char Room::UserInterface() {
  char user_decision;
  string options = "VvRrCcGgXx", add_options = "OoNnSsEeWwUu";

  cout << "Catacomb Level ";
  if (room_num_ > 14) {
    cout << 2;
  } else if (room_num_ > 31) {
    cout << 3;
  } else {
    cout << 1;
  }
  cout << " - Room " << room_num_ << "\n\n"
       << "                       What would you like to do?\n";
  if ((room_num_ == 7 && pc_amulet_ > 0 && door_[kNorth] == 2)
      || (room_num_ == 24 && pc_amulet_ > 1 && door_[kNorth] == 2)
      || (pc_key_ > 0
          && (door_[kNorth] == 2 || door_[kSouth] == 2 || door_[kEast] == 2
              || door_[kWest] == 2))) {
    options.append(add_options, 10, 2);
    cout << "                         +-------------------+\n"
         << "                         | [U]nlock the Door |\n";
  }
  cout
      << "+------------------------+-------------------+-----------------------+\n"

      << "| [V]iew Character Sheet | Search the [R]oom | ";
  if (npc_present_ == true) {
    if (npc_aware_ == false) {
      cout << "Wake up the [O]ld Man |\n";
    } else {
      cout << "Talk to the [O]ld Man |\n";
    }
  } else {
    cout << "                      |\n";
  }
  cout
      << "+-------------+----------+-------------------+-----------------------+\n"
      << "| Try a Door: |";
  if (door_[kNorth] != 0) {
    cout << "     [N]orth";
  }
  if (door_[kSouth] != 0) {
    cout << "     [S]outh";
  }
  if (door_[kEast] != 0) {
    cout << "     [E]ast";
  }
  if (door_[kWest] != 0) {
    cout << "     [W]est";
  }
  cout
      << "\n"
      << "+------------------------+------------------+------------------------+\n"
      << "| [C]hange Equipped Gear | Save Your [G]ame |     E[X]it the Game    |\n"
      << "+------------------------+------------------+------------------------+\n";
  if (npc_present_ == true) {
    options.append(add_options, 0, 2);
  }
  if (door_[kNorth] != 0) {
    options.append(add_options, 2, 2);
  }
  if (door_[kSouth] != 0) {
    options.append(add_options, 4, 2);
  }
  if (door_[kEast] != 0) {
    options.append(add_options, 6, 2);
  }
  if (door_[kWest] != 0) {
    options.append(add_options, 8, 2);
  }
  user_decision = reader.readChar(options);
  if (enemy_hidden_ == true) {
    ClearScreen();
    cout << "  Suddenly, hidden enemies burst from the shadows\n"
         << "and attack you without notice!\n";
    EnterToContinue();
    return 'H';
  }
  if (toupper(user_decision) == 'N' && door_[kNorth] == 2) {
    return 'L';
  }
  if (toupper(user_decision) == 'S' && door_[kSouth] == 2) {
    return 'L';
  }
  if (toupper(user_decision) == 'E' && door_[kEast] == 2) {
    return 'L';
  }
  if (toupper(user_decision) == 'W' && door_[kWest] == 2) {
    return 'L';
  }
  if (toupper(user_decision) == 'N' || toupper(user_decision) == 'S'
      || toupper(user_decision) == 'E' || toupper(user_decision) == 'W') {
    cout << "  You move toward the door, place your hand on the \n"
         << "rough wood, and press onward...\n";
    EnterToContinue();
  }
  ClearScreen();
  return toupper(user_decision);
}
//Function that checks for enemies in a room
int Room::CheckEnemies() {
  cout << "      As you scan the room, ";
  if (enemy_num_ == 0 || enemy_hidden_ == true) {
    cout << "you see no enemies.\n";
    return 0;
  } else {
    if (enemy_num_ > 1 && enemy_hidden_ == false) {
      cout << "you see enemies!!!  \n";
    }
    if (enemy_num_ == 1 && enemy_hidden_ == false) {
      cout << "you see an enemy!  \n";
    }
    if (enemy_num_ > 0 && enemy_aware_ == true) {
      cout << "You must deal with this threat before you can continue!\n";
      EnterToContinue();
    }
    if (enemy_num_ > 0 && enemy_aware_ == false) {
      cout << "But the enemy has not seen you...yet.\n";
      EnterToContinue();
    }
  }
  return 1;
}

//Function to handle battle
int Room::Battle() {
  //Setting up local variables for battle
  string enemy_name;
  int current_enemy_hp, enemy_hp, enemy_atk, enemy_ac, current_enemy_ac,
      enemy_xp, rand_int1, pc_current_ac, pc_current_hp, pc_current_sp;
  char user_selection, yorn, skill_cat_selection, skill_selection,
      item_selection;
  bool used_defense = false, used_stealth = false;
  string options, add_options;
  //This variable breaks you out of the user loop
  //don't forget to switch to false when a final choice is made
  bool user_loop = true;
  //set  up the random number generator
  srand(time(0));
  //set the current stats for the player character
  pc_current_ac = pc_ac_;
  pc_current_hp = pc_hp_;
  pc_current_sp = pc_sp_;
  //creating the room's enemy type and importing enemy stats
  Enemy enemy(enemy_type_);
  gold_gained_ = (enemy.GetGold() * enemy_num_);
  enemy_name = enemy.GetName();
  enemy_hp = enemy.GetHp();
  enemy_atk = enemy.GetAtk();
  enemy_ac = enemy.GetAc();
  current_enemy_ac = enemy_ac;
  enemy_xp = (enemy.GetXp() * enemy_num_);

  //Battle loop starts here
  ClearScreen();
  while (enemy_num_ > 0 && pc_current_hp > 0) {
    for (current_enemy_hp = enemy_hp; current_enemy_hp > 0;) {
      used_stealth = false;
      used_defense = false;
      cout << "    You see " << enemy_num_ << " " << enemy_name;
      if (enemy_num_ == 1) {
        cout << ".\n";
      } else {
        cout << "s.\n";
      }
      if (enemy_hidden_ == false) {
        do {
          user_loop = true;
          if (enemy_aware_ == false) {
            cout << "The enemy is not aware of your presence.  Stay quiet!\n\n";
          } else {
            cout << "The enemy sees you immediately!\n\n";
          }
          cout
              << "*------------------------------------------------------------------*\n"
              << "|                                                                  |\n"
              << "|                                                                  |\n"
              << "|    " << enemy_name << " 1 [";
          if (current_enemy_hp > 30) {
            cout << current_enemy_hp;
          } else {
            for (int i = current_enemy_hp; i > 0; i--) {
              cout << "-";
            }
          }
          cout
              << "]\n"
              << "|                                                                  |\n";
          for (int i = enemy_num_; i > 1; i--) {
            cout << "|    " << enemy_name << " " << i << " [";
            if (enemy_hp > 30) {
              cout << enemy_hp;
            } else {
              for (int i = enemy_hp; i > 0; i--) {
                cout << "-";
              }
            }
            cout
                << "]\n"
                << "|                                                                  |\n";
          }
          cout
              << "|                                                                  |\n"
              << "|                   What would you like to do?                     |\n"
              << "|******************************************************************|\n"
              << "|              [A]ttack   [D]efend   [S]kills   [I]tems            |\n"
              << "|******************************************************************|\n"
              << "     ******  "
              << pc_fname_
              << " "
              << pc_lname_
              << " - HP: "
              << pc_current_hp
              << " - SP: "
              << pc_current_sp
              << " - AC: "
              << pc_current_ac
              << "  ******\n"
              << "********************************************************************\n";

          user_selection = reader.readChar("AaDdSsIi");
          switch (toupper(user_selection)) {

            case 'A':
              cout << "***************************************\n"
                   << "*  Attack the " << enemy_name << "?  [Y] or [N]  *\n"
                   << "***************************************\n";
              yorn = reader.readChar("YyNn");
              ClearScreen();
              if (toupper(yorn) == 'Y') {
                cout << "  You launch a fierce physical attack with your ";
                switch (pc_weap_) {
                  case kDagger:
                    cout << "dagger";
                    break;
                  case kShortSword:
                    cout << "short sword";
                    break;
                  case kLongSword:
                    cout << "long sword";
                    break;
                  case kBastardSword:
                    cout << "bastard sword";
                    break;
                }
                cout << "!\n";
                //using the random number generator as a d10 system
                rand_int1 = (rand() % 10) + 1;
                if (enemy_aware_ == false) {
                  current_enemy_ac = (enemy_ac - 5);
                } else {
                  current_enemy_ac = enemy_ac;
                }
                cout << "            " << (rand_int1 + pc_dex_) << " vs. "
                     << (current_enemy_ac) << " \n";
                if ((rand_int1 + pc_dex_) > (current_enemy_ac)) {
                  cout << "Your attack connects and the " << enemy_name
                       << " recoils from the blow.\n" << "You dealt "
                       << (pc_str_ + pc_weap_) << " damage!\n";
                  current_enemy_hp -= (pc_str_ + pc_weap_);
                  //Check for a critical hit
                  if ((rand_int1 + pc_dex_) == (10 + pc_dex_)) {
                    cout << "   *** Critical Wound ***\n"
                         << "You dealt an extra " << (pc_str_ / 2)
                         << " damage!\n";
                    current_enemy_hp -= (pc_str_ / 2);
                  }
                  if (current_enemy_hp <= 0) {
                    if (enemy_type_ == kOrc || enemy_type_ == kOrcKing) {
                      cout << "\n" << "You have dispatched an " << enemy_name
                           << ".\n";
                    } else {
                      cout << "\n" << "You have dispatched a " << enemy_name
                           << ".\n";
                    }
                    enemy_num_ -= 1;
                    if (enemy_num_ > 0) {
                      current_enemy_hp = enemy_hp;
                    } else {
                    }
                  }
                  EnterToContinue();
                  ClearScreen();
                } else {
                  cout << "Your attack misses...\n";
                  EnterToContinue();
                  ClearScreen();
                }
                user_loop = false;
              }
              if (toupper(yorn) == 'N') {
                ClearScreen();
              }
              break;
            case 'D':
              cout << "***************************************\n"
                   << "*  Defend for this round?  [Y] or [N] *\n"
                   << "***************************************\n";
              yorn = reader.readChar("YyNn");
              ClearScreen();
              if (toupper(yorn) == 'Y') {
                used_defense = true;
                cout << "You enter a defensive stance...";
                if (enemy_aware_ == false) {
                  cout << "but the enemy hasn't noticed you.";
                }
                cout << "\n";
                EnterToContinue();
                ClearScreen();
              }
              if (toupper(yorn) == 'N') {
                ClearScreen();
              }
              user_loop = false;
              break;
            case 'S':
              cout << "*******************\n" << "*     Skills      *\n"
                   << "*******************\n" << "*                 *\n"
                   << "*  [B]attle       *\n" << "*                 *\n"
                   << "*  [M]agic        *\n" << "*                 *\n"
                   << "*  [S]tealth      *\n" << "*                 *\n"
                   << "*******************\n" << "*     [E]xit      *\n"
                   << "*******************\n";

              skill_cat_selection = reader.readChar("BbMmSsEe");

              switch (toupper(skill_cat_selection)) {
                case 'B':
                  options = "Ee";
                  add_options = "Rr";
                  cout << "*******************\n" << "*  Battle Skills  *\n"
                       << "*******************\n" << "*                 *\n";
                  if (pc_str_ > 4) {
                    cout << "*     [R]end      *\n" << "*     -10 SP-     *\n";
                    options.append(add_options, 0, 2);
                  }
                  cout << "*                 *\n" << "*******************\n"
                       << "*     [E]xit      *\n" << "*******************\n";
                  skill_selection = reader.readChar(options);
                  switch (toupper(skill_selection)) {
                    case 'R':
                      if (pc_current_sp < 10) {
                        cout
                            << "Sorry, you do not have enough Skill Points for this Skill.\n";
                        EnterToContinue();
                        ClearScreen();
                      } else {
                        cout
                            << "Do you want to spend 10 Skill Points to use Rend?\n"
                            << "      <ENTER [Y] TO CONFIRM OR [N] TO CANCEL>\n";
                        user_selection = reader.readChar("YyNn");
                        switch (toupper(user_selection)) {
                          case 'N':
                            break;
                          case 'Y':
                            ClearScreen();
                            user_loop = false;
                            pc_current_sp -= 10;
                            cout
                                << "    You grip your weapon with both hands and dig deep within your-\n"
                                << "self for a warrior's rage!  With extra might, you drive your blade\n"
                                << "home!\n" << "You dealt "
                                << (pc_str_ + pc_weap_ + pc_str_)
                                << " damage!\n";
                            current_enemy_hp -= (pc_str_ + pc_weap_ + pc_str_);
                            if (current_enemy_hp <= 0) {
                              if (enemy_type_ == kOrc
                                  || enemy_type_ == kOrcKing) {
                                cout << "\n" << "You have dispatched an "
                                     << enemy_name << ".\n";
                              } else {
                                cout << "\n" << "You have dispatched a "
                                     << enemy_name << ".\n";
                              }
                              enemy_num_ -= 1;
                              if (enemy_num_ > 0) {
                                current_enemy_hp = enemy_hp;
                              } else {
                              }
                            }
                            EnterToContinue();
                            ClearScreen();
                            break;
                        }
                      }
                      break;
                    case 'E':
                      ClearScreen();
                      break;
                  }
                  break;
                case 'M':
                  options = "Ee";
                  add_options = "MmSsDd";
                  cout << "*******************\n" << "*   Magic Skills  *\n"
                       << "*******************\n" << "*                 *\n";
                  if (pc_int_ > 3) {
                    cout << "* [M]agic Missile *\n" << "*      -5 SP-     *\n"
                         << "*                 *\n";
                    options.append(add_options, 0, 2);
                  }
                  if (pc_int_ > 6) {
                    cout << "*     [S]leep     *\n" << "*     -20 SP-     *\n"
                         << "*                 *\n";
                    options.append(add_options, 2, 2);
                  }
                  if (pc_int_ > 8) {
                    cout << "*   [D]eath Ray   *\n" << "*     -50 SP-     *\n"
                         << "*                 *\n";
                    options.append(add_options, 4, 2);
                  }
                  cout << "*                 *\n" << "*******************\n"
                       << "*     [E]xit      *\n" << "*******************\n";
                  skill_selection = reader.readChar(options);
                  switch (toupper(skill_selection)) {
                    case 'M':
                      if (pc_current_sp < 5) {
                        cout
                            << "Sorry, you do not have enough Skill Points for this Skill.\n";
                        EnterToContinue();
                        ClearScreen();
                      } else {
                        cout
                            << "Do you want to spend 5 Skill Points to cast Magic Missile?\n"
                            << "      <ENTER [Y] TO CONFIRM OR [N] TO CANCEL>\n";
                        user_selection = reader.readChar("YyNn");
                        switch (toupper(user_selection)) {
                          case 'N':
                            break;
                          case 'Y':
                            ClearScreen();
                            user_loop = false;
                            pc_current_sp -= 5;
                            cout
                                << "    Brilliant sparks of deep purple form at your fingertips\n"
                                << "before arcing forward and exploding into your foe with a flash!\n"
                                << "You dealt " << (pc_int_ + 1)
                                << " damage!\n";
                            current_enemy_hp -= (pc_int_ + 1);
                            if (current_enemy_hp <= 0) {
                              if (enemy_type_ == kOrc
                                  || enemy_type_ == kOrcKing) {
                                cout << "\n" << "You have dispatched an "
                                     << enemy_name << ".\n";
                              } else {
                                cout << "\n" << "You have dispatched a "
                                     << enemy_name << ".\n";
                              }
                              enemy_num_ -= 1;
                              if (enemy_num_ > 0) {
                                current_enemy_hp = enemy_hp;
                              } else {
                              }
                            }
                            EnterToContinue();
                            ClearScreen();
                            break;
                        }
                      }
                      break;
                    case 'D':
                      if (pc_current_sp < 50) {
                        cout
                            << "Sorry, you do not have enough Skill Points for this Skill.\n";
                        EnterToContinue();
                        ClearScreen();
                      } else {
                        cout
                            << "Do you want to spend 50 Skill Points to cast Death Ray?\n"
                            << "      <ENTER [Y] TO CONFIRM OR [N] TO CANCEL>\n";
                        user_selection = reader.readChar("YyNn");
                        switch (toupper(user_selection)) {
                          case 'N':
                            break;
                          case 'Y':
                            ClearScreen();
                            user_loop = false;
                            pc_current_sp -= 50;
                            cout
                                << "    A pure white ball of energy materializes before your outstretched\n"
                                << "hand.  The center of the energy mass turns black as night and a beam\n"
                                << "of energy races forward to smash your enemy with deadly speed!\n"
                                << "You dealt " << (pc_int_ * 5)
                                << " damage!\n";
                            current_enemy_hp -= (pc_int_ * 5);
                            if (current_enemy_hp <= 0) {
                              if (enemy_type_ == kOrc
                                  || enemy_type_ == kOrcKing) {
                                cout << "\n" << "You have dispatched an "
                                     << enemy_name << ".\n";
                              } else {
                                cout << "\n" << "You have dispatched a "
                                     << enemy_name << ".\n";
                              }
                              enemy_num_ -= 1;
                              if (enemy_num_ > 0) {
                                current_enemy_hp = enemy_hp;
                              } else {
                              }
                            }
                            EnterToContinue();
                            ClearScreen();
                            break;
                        }
                      }
                      break;
                    case 'S':
                      if (pc_current_sp < 20) {
                        cout
                            << "Sorry, you do not have enough Skill Points for this Skill.\n";
                        EnterToContinue();
                        ClearScreen();
                      } else {
                        cout
                            << "Do you want to spend 20 Skill Points to cast Sleep?\n"
                            << "      <ENTER [Y] TO CONFIRM OR [N] TO CANCEL>\n";
                        user_selection = reader.readChar("YyNn");
                        switch (toupper(user_selection)) {
                          case 'N':
                            break;
                          case 'Y':
                            ClearScreen();
                            user_loop = false;
                            pc_current_sp -= 20;
                            cout
                                << "    You move your hands in intricate circles, weaving the air before\n"
                                << "you as you chant a lullaby.  Soon, your foe becomes groggy and falls\n"
                                << "asleep...\n";
                            enemy_aware_ = false;
                            used_stealth = true;
                        }
                      }
                      break;
                    case 'E':
                      ClearScreen();
                      break;
                  }
                  break;
                case 'S':
                  options = "Ee";
                  add_options = "Ss";
                  cout << "*******************\n" << "*  Stealth Skills *\n"
                       << "*******************\n" << "*                 *\n";
                  if (pc_dex_ > 4) {
                    cout << "*    [S]neak      *\n" << "*    -10 SP-      *\n";
                    options.append(add_options, 0, 2);
                  }
                  cout << "*                 *\n" << "*******************\n"
                       << "*     [E]xit      *\n" << "*******************\n";
                  skill_selection = reader.readChar(options);
                  switch (toupper(skill_selection)) {
                    case 'S':
                      if (pc_current_sp < 10) {
                        cout
                            << "Sorry, you do not have enough Skill Points for this Skill.\n";
                        EnterToContinue();
                        ClearScreen();
                      } else {
                        cout
                            << "Do you want to spend 10 Skill Points to use Sneak?\n"
                            << "      <ENTER [Y] TO CONFIRM OR [N] TO CANCEL>\n";
                        user_selection = reader.readChar("YyNn");
                        switch (toupper(user_selection)) {
                          case 'N':
                            break;
                          case 'Y':
                            ClearScreen();
                            user_loop = false;
                            pc_current_sp -= 10;
                            cout
                                << "    Deftly moving about your foe, you slip into the shadows\n"
                                << " and out of sight.  Your enemy looses you and turns about in\n"
                                << " confusion...\n";
                            enemy_aware_ = false;
                            used_stealth = true;
                        }
                      }
                      break;
                    case 'E':
                      ClearScreen();
                      break;
                  }
                  break;
                case 'E':
                  ClearScreen();
                  break;
              }
              break;
            case 'I':
              options = "Ee";
              add_options = "AaHhVv";
              cout << "*******************\n" << "*      Items      *\n"
                   << "*******************\n" << "*                 *\n";
              if (pc_alch_ > 0) {
                cout << "*[A]lchemist Fire *\n" << "*     " << pc_alch_
                     << " left      *\n" << "*                 *\n";
                options.append(add_options, 0, 2);
              }
              if (pc_potion_ > 0) {
                cout << "* [H]ealth Potion *\n" << "*     " << pc_potion_
                     << " left      *\n" << "*                 *\n";
                options.append(add_options, 2, 2);
              }
              if (pc_vita_ > 0) {
                cout << "*  [V]ita Potion  *\n" << "*     " << pc_vita_
                     << " left      *\n" << "*                 *\n";
                options.append(add_options, 4, 2);
              }
              cout << "*******************\n" << "*     [E]xit      *\n"
                   << "*******************\n";
              item_selection = reader.readChar(options);
              switch (toupper(item_selection)) {
                case 'A':
                  cout << " Do you want to use an Alchemist Fire?\n"
                       << " <ENTER [Y] TO CONFIRM OR [N] TO CANCEL>\n";
                  user_selection = reader.readChar("YyNn");
                  switch (toupper(user_selection)) {
                    case 'N':
                      break;
                    case 'Y':
                      ClearScreen();
                      user_loop = false;
                      pc_alch_--;
                      cout
                          << "    You pull a spherical jar from your pouch and ignite its small\n"
                          << "fuse before hurling the explosive toward your foe.  It explodes with\n"
                          << "a flash when it makes contact with your target's face!\n"
                          << "You dealt " << kAlchemistFire << " damage!\n";
                      current_enemy_hp -= kAlchemistFire;
                      if (current_enemy_hp <= 0) {
                        if (enemy_type_ == kOrc || enemy_type_ == kOrcKing) {
                          cout << "\n" << "You have dispatched an "
                               << enemy_name << ".\n";
                        } else {
                          cout << "\n" << "You have dispatched a " << enemy_name
                               << ".\n";
                        }
                        enemy_num_ -= 1;
                        if (enemy_num_ > 0) {
                          current_enemy_hp = enemy_hp;
                        } else {
                        }
                      }
                      EnterToContinue();
                      ClearScreen();
                      break;
                  }
                  break;
                case 'H':
                  cout << " Do you want to use a Health Potion?\n"
                       << " <ENTER [Y] TO CONFIRM OR [N] TO CANCEL>\n";
                  user_selection = reader.readChar("YyNn");
                  switch (toupper(user_selection)) {
                    case 'N':
                      break;
                    case 'Y':
                      ClearScreen();
                      user_loop = false;
                      pc_potion_--;
                      cout
                          << "  You lift the clear vial to your lips and pour the deep red fluid into\n"
                          << "your mouth.  It is warm and sweet and comforting all at once!\n"
                          << "You gain 10 HP!\n";
                      pc_current_hp += 10;
                      EnterToContinue();
                      ClearScreen();
                      if (pc_current_hp > pc_hp_) {
                        pc_current_hp = pc_hp_;
                      }
                      break;
                  }
                  break;
                case 'V':
                  cout << " Do you want to use a Vita Potion?\n"
                       << " <ENTER [Y] TO CONFIRM OR [N] TO CANCEL>\n";
                  user_selection = reader.readChar("YyNn");
                  switch (toupper(user_selection)) {
                    case 'N':
                      break;
                    case 'Y':
                      ClearScreen();
                      user_loop = false;
                      pc_vita_--;
                      cout
                          << "  You lift the clear vial to your lips and pour the light blue fluid into\n"
                          << "your mouth.  It is crisp and cool and exhilarating all at once!\n"
                          << "You gain 10 SP!\n";
                      pc_current_sp += 10;
                      EnterToContinue();
                      ClearScreen();
                      if (pc_current_sp > pc_sp_) {
                        pc_current_sp = pc_sp_;
                      }
                      break;
                  }
                  break;
                case 'E':
                  ClearScreen();
                  break;
              }
          }
        } while (user_loop == true);
      }
      //Now it is time for the enemies to fight back
      if (enemy_aware_ == true && enemy_num_ > 0) {
        cout << "    Your foe rushes to attack you...\n";
        EnterToContinue();
        ClearScreen();
        for (int i = enemy_num_; i > 0; i--) {
          cout << "The " << enemy_name << " attacks!\n";
          rand_int1 = (rand() % 10) + 1;
          if (enemy_hidden_ == true) {
            pc_current_ac = (pc_ac_ - 5);
            enemy_hidden_ = false;
          } else if (used_defense == true) {
            pc_current_ac = pc_ac_ + pc_dex_;
          } else {
            pc_current_ac = pc_ac_;
          }
          cout << "     " << (rand_int1 + enemy_atk) << " vs. "
               << (pc_current_ac) << "\n";
          if ((rand_int1 + enemy_atk) > (pc_current_ac)) {
            cout << "The " << enemy_name << "'s attack hits you!\n"
                 << "You take " << enemy_atk << " damage!\n\n";
            pc_current_hp -= enemy_atk;
          } else {
            cout << "The " << enemy_name << "'s attack misses.\n\n";
          }
        }
        used_defense = false;
        pc_current_ac = pc_ac_;
      }
      if (enemy_aware_ == false && used_stealth == false) {
        cout << "\n" << "The enemy has been alerted to your presence!!!\n";
        enemy_aware_ = true;
      }
      if (pc_current_hp < 1) {
        cout << "        ***YOU HAVE DIED***\n";
        gold_gained_ = 0;
        return 0;
      }
      EnterToContinue();
      ClearScreen();
    }
  }
  return enemy_xp;
}

//Function to grab fresh PC data for battle function
void Room::GetPcData(string fname, string lname, int hp, int sp, int ac,
                     int str, int dex, int intel, int find, int xp, int gold,
                     int weap, int key, int alch, int potion, int vita,
                     int amulet) {
  pc_lname_ = lname;
  pc_fname_ = fname;
  pc_hp_ = hp;
  pc_sp_ = sp;
  pc_ac_ = ac;
  pc_str_ = str;
  pc_dex_ = dex;
  pc_int_ = intel;
  pc_find_ = find;
  pc_xp_ = xp;
  pc_gold_ = gold;
  pc_weap_ = weap;
  pc_key_ = key;
  pc_alch_ = alch;
  pc_potion_ = potion;
  pc_vita_ = vita;
  pc_amulet_ = amulet;

}

//Function that forces the user to press enter to continue
void Room::EnterToContinue() {
  string press_enter;
  cout << "                     <PRESS [ENTER] TO CONTINUE>\n" << endl;
  press_enter = reader.readString(true, 0);
}

//Function to return the amount of gold gained from battle
int Room::GoldGained() {
  return gold_gained_;
}

int Room::ChangeRoom(char user_decision) {
  if (user_decision == 'U') {
    if (room_num_ == 0 || room_num_ == 7 || room_num_ == 24) {
      if ((room_num_ == 7 && pc_amulet_ > 0)
          || (room_num_ == 24 && pc_amulet_ > 1)) {
        cout
            << "  As you approach the door, the ground trembles, you feel \n"
            << "electricity in the air and suddenly, the door stands open...\n";
        door_[kNorth] = 1;
        EnterToContinue();
        return 0;
      } else {
        cout << "  That room does not unlock with a normal key.\n"
             << "No one alive knows the secret...\n";
      }
      EnterToContinue();
      return 0;
    } else {
      cout << "  The lock makes a *click* and the hinges groan...\n";
      if (door_[kNorth] == 2) {
        door_[kNorth] = 1;
        EnterToContinue();
        return 1;
      }
      if (door_[kSouth] == 2) {
        door_[kSouth] = 1;
        EnterToContinue();
        return 1;
      }
      if (door_[kEast] == 2) {
        door_[kEast] = 1;
        EnterToContinue();
        return 1;
      }
      if (door_[kWest] == 2) {
        door_[kWest] = 1;
        EnterToContinue();
        return 1;
      }

    }
  }
  if (user_decision == 'R') {
    if (pc_find_ >= (5 * room_diff_)) {
      if (room_num_ == 4) {
        cout << "   After a quick, but thorough search, you find the\n"
             << "outline of a trick door leading back the way you came...\n";
        door_[kWest] = 1;
        door_num_ = 1;
        return 0;
      } else {
        cout
            << "You thoroughly search the room, corner to corner, floor to ceiling...\n";
        if (secret_found_ == false) {
          secret_found_ = true;
          return 4;
        } else {
          cout
              << "But you have already discovered all of this room's secrets.\n";
          return 0;
        }
      }

    }
    if (pc_find_ < (5 * room_diff_)) {
      cout << "   Your cursory search of the room provides no \n"
           << "clues as to what secrets it might hold.\n";
      return 0;
    }
  }
  if (user_decision == 'O') {
    if (npc_aware_ == false) {
      npc_aware_ = true;
      cout
          << "You gently prod the old man, trying to rouse him from sleep...\n";
      EnterToContinue();
      ClearScreen();
      cout
          << "\n"
          << "    Startled, he suddenly jumps from his seat, eyes \n"
          << "wide in the confusion that follows awakening from a deep sleep.  \n"
          << "He regains his composure quickly, and looks on you with\n"
          << "kind and knowing eyes.\n" << "\n";
      if (room_num_ == 32) {
        cout
            << " \"Another level of the catacombs is behind you.  You are truely\n"
            << " proving your worth as an adventurer, and no one can doubt your\n"
            << " courage.  Your ancestors would be proud.\"\n"
            << "\n"
            << " \"Now, you must brave the depths of the third level of catacombs.\n"
            << "  Things will not get easier, I fear.  Creatures known to the folks\n"
            << "  on the surface will make way for all manner of eerie monsters down\n"
            << " here, so be on your guard, and make sure you are prepared!\"\n"
            << "[This is the end of the current build, save and load to respawn all enemies]\n";
      } else if (room_num_ == 15) {
        cout
            << " \"Oh my!  You have made it past the first level of the catacombs!\n"
            << " I never doubted you for a second, being the heir and all.  The mystery\n"
            << " to the secret doors has been solved.  It is obvious you must gather more of\n"
            << " your family amulets in order to open the deeper paths.  Now you must continue\n"
            << " on.  There is much more for your to discover below...\n";
      } else if (room_num_ == 0) {
        cout
            << "     \"Welcome, welcome!  Its been so long since I've had a visitor...\n"
            << "     Deepest apologies for having fallen asleep, but I was waiting quite\n"
            << "     some time, you know.  I have been expecting you, "
            << pc_fname_ << ", \n" << "     heir to Castle " << pc_lname_
            << " and final hope for the legacy of your house.\"\n";
        EnterToContinue();
        cout
            << "\n"
            << "     \"Fear not, I have good cause to know about you and your clan.  I am an\n"
            << "     Archivist, charged with keeping the records of history and specifically\n"
            << "     employed by your ancestors to dwell here underground and guard their\n"
            << "     tomb against raiders, monsters, and the worst enemy of all...\n"
            << "          ...the eroding force of time.\"\n"
            << "\n"
            << "     \"Against time and tomb robbers I have been successful.  The monsters,\n"
            << "     however, have proven the better of me.  In my youth I could have torn\n"
            << "     through Goblin and Orc like so many blades of grass, but it has been years\n"
            << "     since I could call myself young.  I was driven from my study deep within \n"
            << "     the catacomb by fell beasts, and now the proof you seek lies beyond the\n"
            << "     hordes below.\"\n";
        EnterToContinue();
        cout
            << "\n"
            << " \"You will have to venture into the tomb yourself, as I will be of no use in\n"
            << " battle; but this does not mean I cannot help.  As you progress on your journey\n"
            << " you will gain much of great use, not the least of which will be Gold and \n"
            << " Experience.  When you have gathered enough of either, find me.  I can exchange\n"
            << " your Gold for useful equipment, and I can use your Experience to mold you into\n"
            << " a fierce opponent.  I can teach you to be strong, to be fast, and to use your\n"
            << " mind to great effect casting magical spells.\n"
            << "\n"
            << " \"But enough from me.  You will learn only by doing.  The room to the West\n"
            << " is locked.  It has been that way since I can remember, and I know not how to\n"
            << " open it.  Your way down into the depths lies through the door to the East.\n"
            << " You will likely face Goblins nearby.  They may not prove much trouble to you\n"
            << " but there are foes much more dire below, and before long you will need my \n"
            << " services to survive.  If you have any more questions, feel free to speak to"
            << " me again\"\n" << "\n"
            << " \"Go now, your family's salvation awaits!\n";
      }
      return 0;
    } else {
      char user_decision;
      cout
          << "     \"It is good to see you again.  How may I be of assistance?\n"
          << "\n"
          << "                    What would you like to do?\n"
          << "+------------------------+-------------------+-----------------------+\n"
          << "|   Spend E[X]perience   |       [T]alk      |  Buy/Sell for [G]old  |\n"
          << "+------------------------+-------------------+-----------------------+\n"
          << "                         |       [E]xit      |\n"
          << "                         +-------------------+\n";
      user_decision = reader.readChar("EeTtGgXx");
      ClearScreen();
      switch (toupper(user_decision)) {
        case 'X':
          return 1;
          break;
        case 'T':
          cout
              << "     \"Oh good, conversation!  It gets quite lonely down here, and I do\n"
              << "     so love to hear myself speak.  What would you like to talk about?\n"
              << "\n"
              << "            *[B]attle*    *Spending E[X]perience*    *[S]ecrets*\n"
              << "                               [E]xit\n";
          user_decision = reader.readChar("BbXxEeSs");
          ClearScreen();
          switch (toupper(user_decision)) {
            case 'E':
              break;
            case 'B':
              cout
                  << " \"You will undoubtedly be forced into battle on your quest,\n"
                  << " but do not fret!  If you keep your wits about you, watch your health\n"
                  << " closely, and use your skills wisely, you will triumph over the\n"
                  << " invading creatures here.\"\n"
                  << "\n"
                  << " \"Do not wander into battle ill equipped!  The right gear and usable\n"
                  << " items can turn a losing battle into a sure victory!  Health Potions\n"
                  << " will restore your Health Points and Vita Potions will restore Skill\n"
                  << " Points, allowing you to use your skills more frequently.\"\n"
                  << "\n"
                  << " \"You only need to worry about your Health and Skill Points during battle;\n"
                  << " Both will be fully restored automatically when you have time to rest\n"
                  << " (after battle).  As you delve deeper, you will encounter more fearsome\n"
                  << " enemies, and with these cramped corridors there is no running from battle,\n"
                  << " so be sure to visit me often to spend your Experience and Gold to make\n"
                  << " yourself more formidable before venturing too far.\"\n";
              break;
            case 'X':
              cout
                  << " \"Spending Experience to increase your attributes is absolutely necessary\n"
                  << " if you are to complete your quest.  As you gain Experience, come back to me\n"
                  << " in order to trade that Experience to increase your stats.  Each of the three\n"
                  << " main attributes also increases other stats that you possess, so choosing\n"
                  << " which attributes to increase will determine your tactics in battle as well\n"
                  << " as the Skills you have access to.\"\n"
                  << "\n"
                  << " \"Strength is the primary attribute for Warriors, and determines how much\n"
                  << " physical damage you do in battle.  Increasing Strength comes with the\n"
                  << " greatest HP boost and a high enough Strength will give you access to Battle\n"
                  << " Skills.\"\n"
                  << "\n"
                  << " \"Dexterity is the primary attribute for Rogues, and determines how easily\n"
                  << " you are able to hit your enemies in battle.  Increasing Dexterity comes with\n"
                  << " a smaller HP boost but also gives you a bonus to your Armor Class, making you\n"
                  << " more difficult to be hit in battle, and a bonus to the Find skill, making\n"
                  << " secrets more easy to uncover.  A high enough Dexterity will give you access\n"
                  << " to Stealth Skills\"\n"
                  << "\n"
                  << " \"Intelligence is the primary attribute for Mages, and determines how much\n"
                  << " magic damage you can deal in battle. Increasing Intelligence comes with the\n"
                  << " lowest HP boost but is also the only attribute that gives you a boost to\n"
                  << " Skill Points.  A high enough Intelligence gives you access to Magic Skills,\n"
                  << " the most powerful skills known to mankind.\"\n";
              break;
            case 'S':
              cout
                  << " \"There are many secrets in these catacombs that even a learned \n"
                  << " man such as myself has not uncovered.  I can tell you that many of\n"
                  << " the rooms contain hidden caches of items, easily uncovered by those\n"
                  << " with the proper skill.  Do not forget to search a room when it is safe to\n"
                  << " do so, as you will likely uncover something that will aid you greatly on \n"
                  << " your journey.\"\n"
                  << "\n"
                  << " \"You must also tred with care, as there are some enemies cunning enough\n"
                  << " to hide and attack from the shadows.  Such enemies will wait until you\n"
                  << " least expect them to try and catch you unawares.\n"
                  << "  Be ever vigilant and you will prevail!\"\n"
                  << "\n"
                  << " \"Finally, we must speak of these special doors.  I have come across \n"
                  << " several in my time down here, but none would open with any key I could find.\n"
                  << " I seem to recall a scroll that spoke of family heirlooms that could open\n"
                  << " magically sealed portals, but all of my research is deep below in my study,\n"
                  << " beyond the hordes of Goblins and Orcs. Should you come across any peculiar\n"
                  << " items in your travels, take them to these special doors and see what happens.\"\n";
              break;
          }
          break;
        case 'G':
          return 2;
          break;
        case 'E':
          return 0;
          break;
      }
    }
  }
  return 0;
}

//Function that chooses random loot depending on the room (returns loot type for SetLoot function)
int Room::GetRandomLoot() {
  int rand_int;
  srand(time(0));
  if ((room_num_ == 14 && pc_amulet_ < 1)
      || (room_num_ == 25 && pc_amulet_ < 2)) {
    cout
        << "   You found an Amulet!  It is finely made and pleasant to behold.\n"
        << "You feel a strange connection to this item.  Perhaps it is an heirloom\n";
    rand_int = kAmulet;
  } else {
    rand_int = (rand() % 11);
    if (rand_int <= 2) {
      rand_int = kKey;
      if (room_diff_ == 1) {
        cout << "You found a Key!\n";
      } else {
        cout << "You found some Keys!\n";
      }
    } else if (rand_int <= 5) {
      rand_int = kHealthPotion;
      if (room_diff_ == 1) {
        cout << "You found a Health Potion!\n";
      } else {
        cout << "You found some Health Potions!\n";
      }
    } else if (rand_int <= 8) {
      rand_int = kVitaPotion;
      if (room_diff_ == 1) {
        cout << "You found a Vita Potion!\n";
      } else {
        cout << "You found some Vita Potions!\n";
      }
    } else if (rand_int > 8) {
      rand_int = kAlchemistFire;
      if (room_diff_ == 1) {
        cout << "You found an Alchemist Fire!\n";
      } else {
        cout << "You found some Alchemist Fires!\n";
      }
    }
  }
  return rand_int;
}

//function that returns the current room number
int Room::GetRoomNum() {
  return room_num_;
}

//function that returns the room's difficulty level
int Room::GetRoomDiff() {
  return room_diff_;
}
//functions to return modified totals for usable items from battle
int Room::GetNewAlch() {
  return pc_alch_;
}
int Room::GetNewPotion() {
  return pc_potion_;
}
int Room::GetNewVita() {
  return pc_vita_;
}
//Constructor for all types of enemies
Enemy::Enemy(int enemy_type) {
  switch (enemy_type) {
    case kGoblin:
      enemy_name_ = "Goblin";
      enemy_hp_ = 5;
      enemy_atk_ = 2;
      enemy_ac_ = 6;
      enemy_xp_ = 100;
      enemy_gold_ = 10;
      break;
    case kOrc:
      enemy_name_ = "Orc";
      enemy_hp_ = 10;
      enemy_atk_ = 3;
      enemy_ac_ = 8;
      enemy_xp_ = 150;
      enemy_gold_ = 25;
      break;
    case kBugBear:
      enemy_name_ = "BugBear";
      enemy_hp_ = 20;
      enemy_atk_ = 4;
      enemy_ac_ = 11;
      enemy_xp_ = 225;
      enemy_gold_ = 75;
      break;
    case kSkeleton:
      enemy_name_ = "Skeleton";
      enemy_hp_ = 35;
      enemy_atk_ = 6;
      enemy_ac_ = 13;
      enemy_xp_ = 400;
      enemy_gold_ = 175;
      break;
    case kGoblinChief:
      enemy_name_ = "Goblin Chief";
      enemy_hp_ = 70;
      enemy_atk_ = 6;
      enemy_ac_ = 10;
      enemy_xp_ = 750;
      enemy_gold_ = 150;
      break;
    case kOrcKing:
      enemy_name_ = "Orc King";
      enemy_hp_ = 150;
      enemy_atk_ = 8;
      enemy_ac_ = 12;
      enemy_xp_ = 1000;
      enemy_gold_ = 1000;
      break;
  };
}

//functions to return enemy stats for battle function
string Enemy::GetName() {
  return enemy_name_;
}
int Enemy::GetHp() {
  return enemy_hp_;
}
int Enemy::GetAtk() {
  return enemy_atk_;
}
int Enemy::GetAc() {
  return enemy_ac_;
}
int Enemy::GetXp() {
  return enemy_xp_;
}
int Enemy::GetGold() {
  return enemy_gold_;
}

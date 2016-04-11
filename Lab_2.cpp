/*
 * Name        : Lab 2 - (Shootout!)
 * Author      : Steve Ross-Byers
 * Description : This is the game Shootout!
 * Sources Used: CinReader (by Boyd Trolinger)
 */

#include <iostream>
#include <cctype>
#include <string>
#include <ctime>
#include <cstdlib>
#include "CinReader.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::srand;
using std::time;
using std::rand;

// Program starts here
int main() {
  // Set up CinReader
  CinReader reader;
  // Set up Random number generator
  srand(time(0));
  // Set up Variables
  int comp_decision, wins= 0, losses = 0, draws = 0, game = 1, round = 1;
  char again, user_decision, read_instructions, difficulty = 0;
  bool game_over = false, comp_gun_loaded, user_gun_loaded;
  string press_enter, opponent_name;
  enum ComputerChoices {kCompLoad, kCompShoot, kCompBlock};
  enum UserChoices {kUserLoad = 'L', kUserShoot = 'S', kUserBlock = 'B'};

  // Introduce the game and ask if the user would like to read the instructions
  cout << "Welcome to Shootout!\n"
       << "<PRESS ENTER TO CONTINUE>" << endl;
  press_enter = reader.readString(true, 0);

  cout << "Would you like to read the instructions?\n"
	   << "<ENTER <Y> TO READ OR <N> TO CONTINUE>" << endl;
  read_instructions = reader.readChar("YyNn");

  while(toupper(read_instructions) == 'Y'){
    cout << "You will attempt to best your opponent in a wild-west shootout!\n"
         << "In this game of life or death you must choose your actions wisely.\n"
         << "Each round will present you with 3 choices...\n"
         << "<PRESS ENTER TO CONTINUE>" << endl;
    press_enter = reader.readString(true, 0);

    cout << "You can either (L)oad your pistol...\n"
         << "               (S)hoot your pistol...\n"
         << "            or (B)lock an incoming shot\n"
         << "<PRESS ENTER TO CONTINUE>" << endl;
    press_enter = reader.readString(true, 0);

    cout << "Your guns only hold one bullet each, \n"
         << "and you can only shoot once your gun is loaded. \n"
         << "<PRESS ENTER TO CONTINUE>" << endl;
    press_enter = reader.readString(true, 0);

    cout << "Your opponent has the same three options,\n"
         << "but it is up to you to survive!\n"
         << "<PRESS ENTER TO CONTINUE>" << endl;
    press_enter = reader.readString(true, 0);

    cout << "Would you like to read the instructions again?\n"
    	 << "<ENTER <Y> TO RE-READ OR <N> TO CONTINUE>" << endl;
    read_instructions = reader.readChar("YyNn");
  };
  cout << "Are you ready to Shoot-out?!\n"
       << "<ENTER <Y> TO CONTINUE OR <N> TO QUIT>" << endl;
  again = reader.readChar("YyNn");

  // Game Loop, keeps the game going until the user inputs decides to stop
  do {
	// Set variables to their game-start values
	game_over = false;
	round = 1;
    comp_gun_loaded = false;
    user_gun_loaded = false;

	//Determine the difficulty of the current game and set the opponent name
	cout << "Who would you like to face? \n"
         << "\n"
		 << "-Cowboy Dan (Normal)-\n"
		 << "         or\n"
		 << "The Dead-Eye Gunslinger (Hard)\n"
		 << "\n"
		 << "<ENTER <N> FOR COWBOY DAN OR <H> FOR THE DEAD-EYE GUNSLINGER>" << endl;
	difficulty = reader.readChar("HhNn");
	if (toupper(difficulty) == 'H'){
	  opponent_name = "The Dead-Eye Gunslinger";
	} else if(toupper(difficulty) == 'N') {
	  opponent_name = "Cowboy Dan";
	}
	cout << "Good Luck!\n"
		 << " " << endl;

	// Notify the user which game they are playing and against whom
	cout << "-Game: " << game << "-\n"
		 << "     vs\n"
		 << opponent_name << endl;
	cout << " " << endl;

    // Loop for Dead-Eye Gunslinger difficulty
    while (toupper(difficulty) == 'H'){
      // Round loop, keeps running rounds until someone wins
      do {
        //Inform the Player of the current round
        cout << "-Round: " << round << "-\n"
    	     << " " << endl;
        //Inform the user of the status of both weapons before decisions are made
        if(comp_gun_loaded == false && user_gun_loaded == false){
          cout << "The Dead-Eye Gunslinger's gun is unloaded, as is yours..." << endl;
          cout << "Will you: \n"
               << "(L)load your gun \n"
               << "        or\n"
               << "(B)lock an incoming shot" << endl;
          //user makes their decision
          user_decision = reader.readChar("BbLl");
          if(toupper(user_decision) == kUserLoad){
            cout << "You have decided to Load your pistol...good choice!" << endl;
            user_gun_loaded = true;
          }else if(toupper(user_decision) == kUserBlock){
            cout << "You have decided to Block...but his gun is unloaded!" << endl;
          };
          //computer makes always decides to load when both guns are unloaded
          comp_decision = kCompLoad;
          if (comp_decision == kCompLoad){
            cout << "The Dead-Eye Gunslinger slaps a bullet into his pistol..." << endl;
            comp_gun_loaded = true;
          };
        // Inform the user of the status of both weapons before decisions are made
        }else if(comp_gun_loaded == true && user_gun_loaded == true){
          cout << "The Dead-Eye Gunslinger brushes the grip of his loaded pistol.\n"
               << "The weight of your own pistol tells you it is loaded, as well.\n"
               << "Will you: \n"
               << "(S)hoot your gun \n"
               << "        or \n"
               << "(B)lock an incoming shot" << endl;
          //user makes their decision
          user_decision = reader.readChar("SsBb");
          if (toupper(user_decision) == kUserShoot){
            cout << "You raise your pistol with a flash and pull the trigger..." << endl;
            user_gun_loaded = false;
          } else if (toupper(user_decision) == kUserBlock){
            cout << "You decide to enable your magical bullet shield in defense!" << endl;
          };
          // With both guns loaded, the computer decides to Shoot or Block
          comp_decision = (rand() % 2 + 1);
          if (comp_decision == kCompShoot) {
            cout << "The Dead-eye Gunslinger shoots from the hip" << endl;
            comp_gun_loaded = false;
          } else if (comp_decision == kCompBlock) {
            cout << "The Dead-Eye Gunslinger decides to block..." << endl;
          };
        // Inform the user of the status of both weapons before decisions are made
        } else if (comp_gun_loaded == true && user_gun_loaded == false){
          cout << "The Dead-Eye Gunslinger brushes the grip of his loaded pistol.\n"
               << "The weight of your pistol tells you it is empty...\n"
               << "Will you: \n"
               << "(L)load your gun \n"
               << "        or\n"
               << "(B)lock an incoming shot" << endl;
          //user makes their decision
          user_decision = reader.readChar("BbLl");
          if(toupper(user_decision) == kUserLoad){
            cout << "You have decided to Load your pistol...good choice!" << endl;
            user_gun_loaded = true;
          }else if(toupper(user_decision) == kUserBlock){
             cout << "You have decided to throw up your magical bullet shield!" << endl;
          };
          // With the User's gun unloaded, the computer always shoots!
          comp_decision = kCompShoot;
          if (comp_decision == kCompShoot){
            cout << "The Dead-Eye Gunslinger pulls the trigger with lightning speed!" << endl;
            comp_gun_loaded = false;
          };
        // Inform the user of the status of both weapons before decisions are made
        } else if (comp_gun_loaded == false && user_gun_loaded == true){
          cout << "You have not seen the Dead-Eye Gunslinger reload...yet!\n"
               << "The heavy weight of your pistol tells you it is loaded...\n"
               << "Will you: \n"
               << "(S)hoot your gun \n"
               << "        or \n"
               << "(B)lock an incoming shot" << endl;
          //user makes their decision
          user_decision = reader.readChar("SsBb");
          if (toupper(user_decision) == kUserShoot){
            cout << "You raise your pistol with a flash and pull the trigger..." << endl;
            user_gun_loaded = false;
          } else if (toupper(user_decision) == kUserBlock){
             cout << "You decide to block...but isn't his gun empty?" << endl;
         };
         //With the user's gun loaded, and the computer's gun unloaded, the computer always blocks!
         comp_decision = kCompBlock;
         if (comp_decision == kCompBlock){
            cout << "The Dead-Eye Gunslinger calls upon his magical bullet shield..." << endl;
         };
        };
        // This is where the outcome of each round is determined
        if (comp_decision == kCompShoot && toupper(user_decision) == kUserShoot){
          cout << "The Dead-Eye Gunslinger is fast, but so are you...\n"
               << "Your pistols fire simultaneously, and you both fall to the ground!\n"
               << "We will call this one a Draw" << endl;
               draws++;
               game_over = true;
               difficulty = 0;
        } else if (comp_decision == kCompShoot && toupper(user_decision) == kUserBlock){
          cout << "The Dead-Eye Gunslinger's bullet races toward you...\n"
               << "But your magical bullet shield repels the projectile!\n"
               << "Whew, that was close!" << endl;
        } else if (comp_decision == kCompShoot && toupper(user_decision) == kUserLoad){
          cout << "You fumble as you try to fit the bullet into your pistol...\n"
               << "You hear the gunshot before you feel the wound in your belly...\n"
               << "The Dead-Eye Gunslinger claims another victim, we will notify your next of kin." << endl;
               losses++;
               game_over = true;
               difficulty = 0;
        } else if (comp_decision == kCompBlock && toupper(user_decision) == kUserShoot){
          cout << "Your bullet speeds toward the Dead-Eye Gunslinger...\n"
               << "But he has a magical bullet shield!\n"
               << "Your shot is repelled, the Shootout continues!" << endl;
        } else if (comp_decision == kCompLoad && toupper(user_decision) == kUserShoot){
          cout << "Your bullet speeds toward the Dead-Eye Gunslinger...\n"
               << "The Dead-Eye Gunslinger fits his bullet into his pistol...\n"
               << "Just as your bullet strikes him in the chest!\n"
               << "You have defeated the Dead-Eye Gunslinger!\n";
               wins++;
               game_over = true;
               difficulty = 0;
        }
        round++;
        cout << "<PRESS ENTER TO CONTINUE>" << endl;
        press_enter = reader.readString(true, 0);
      } while (game_over == false);
    }
    // Loop for Cowboy Dan difficulty
    while (toupper(difficulty) == 'N'){
      // Round loop, keeps running rounds until someone wins
      do {
       //Inform the Player of the current round
       cout << "-Round: " << round << "-\n"
    	    << " " << endl;
       //Inform the user of the status of both weapons before decisions are made
       if(comp_gun_loaded == false && user_gun_loaded == false){
         cout << "Cowboy Dan's gun is unloaded, as is yours..." << endl;
         cout << "Will you: \n"
   	          << "(L)load your gun \n"
              << "        or\n"
              << "(B)lock an incoming shot" << endl;
         //user makes their decision
    	 user_decision = reader.readChar("BbLl");
         if(toupper(user_decision) == kUserLoad){
           cout << "You have decided to Load your pistol...good choice!" << endl;
    	      user_gun_loaded = true;
    	 }else if(toupper(user_decision) == kUserBlock){
           cout << "You have decided to Block...but Dan's gun is unloaded!" << endl;
         };
    	    //computer always decides to load when both guns are unloaded
    	    comp_decision = kCompLoad;
    	    if (comp_decision == kCompLoad){
    	      cout << "Cowboy Dan carefully slides a bullet into his pistol..." << endl;
    	      comp_gun_loaded = true;
    	    };
    	  // Inform the user of the status of both weapons before decisions are made
    	  }else if(comp_gun_loaded == true && user_gun_loaded == true){
    	    cout << "Cowboy Dan's hand twitches near the grip of his loaded pistol.\n"
    	         << "The weight of your own pistol tells you it is loaded, as well.\n"
    	         << "Will you: \n"
    	         << "(S)hoot your gun \n"
                 << "        or \n"
    	         << "(B)lock an incoming shot" << endl;
    	    //user makes their decision
            user_decision = reader.readChar("SsBb");
            if (toupper(user_decision) == kUserShoot){
    	      cout << "You raise your pistol with a flash and pull the trigger..." << endl;
    	      user_gun_loaded = false;
    	    } else if (toupper(user_decision) == kUserBlock){
    	      cout << "You decide to enable your magical bullet shield in defense!" << endl;
    	    };
    	    // With both guns loaded, the computer decides to Shoot or Block
    	    comp_decision = (rand() % 2 + 1);
    	    if (comp_decision == kCompShoot) {
    	      cout << "Cowboy Dan raises his pistol to fire..." << endl;
    	      comp_gun_loaded = false;
    	    } else if (comp_decision == kCompBlock) {
             cout << "Cowboy Dan decides to block..." << endl;
    	    };
    	  // Inform the user of the status of both weapons before decisions are made
          } else if (comp_gun_loaded == true && user_gun_loaded == false){
    	    cout << "Cowboy Dan seems eager to fire his loaded pistol.\n"
    	         << "The weight of your pistol tells you it is empty...\n"
    	         << "Will you: \n"
    	         << "(L)load your gun \n"
    	         << "        or\n"
    	         << "(B)lock an incoming shot" << endl;
            //user makes their decision
            user_decision = reader.readChar("BbLl");
            if(toupper(user_decision) == kUserLoad){
              cout << "You have decided to Load your pistol...good choice!" << endl;
    	      user_gun_loaded = true;
    	    }else if(toupper(user_decision) == kUserBlock){
    	      cout << "You have decided to throw up your magical bullet shield!" << endl;
    	    };
    	    // With the User's gun unloaded, the computer decides to shoot or block
            comp_decision = (rand() % 2 + 1);
            if (comp_decision == kCompShoot) {
              cout << "Cowboy Dan raises his pistol to fire..." << endl;
              comp_gun_loaded = false;
            } else if (comp_decision == kCompBlock) {
              cout << "Cowboy Dan decides to block...though no one knows why..." << endl;
    	    };
    	  // Inform the user of the status of both weapons before decisions are made
    	  } else if (comp_gun_loaded == false && user_gun_loaded == true){
    	    cout << "Cowboy Dan looks nervous with an unloaded pistol.\n"
    	         << "The heavy weight of your pistol tells you it is loaded...\n"
    	         << "Will you: \n"
    	         << "(S)hoot your gun \n"
    	         << "        or \n"
    	         << "(B)lock an incoming shot" << endl;
    	    //user makes their decision
    	    user_decision = reader.readChar("SsBb");
    	    if (toupper(user_decision) == kUserShoot){
    	      cout << "You raise your pistol with a flash and pull the trigger..." << endl;
    	      user_gun_loaded = false;
    	    } else if (toupper(user_decision) == kUserBlock){
    	      cout << "You decide to block...but isn't Dan's gun empty?" << endl;
    	   };
    	   //With the user's gun loaded, and the computer's gun unloaded, the computer blocks or loads
    	    comp_decision = (rand() % 3);
    	    if (comp_decision == kCompLoad) {
    	      cout << "Cowboy Dan rushes to fit a bullet in his pistol..." << endl;
    	      comp_gun_loaded = true;
     	    } else if (comp_decision == kCompBlock) {
              cout << "Cowboy Dan decides to block..." << endl;
    	    } else {
    	      comp_decision = kCompLoad;
    	      cout << "Cowboy Dan rushes to fit a bullet in his pistol..." << endl;
    	    }
    	  };
    	  // This is where the outcome of each round is determined
    	  if (comp_decision == kCompShoot && toupper(user_decision) == kUserShoot){
    	    cout << "Cowboy Dan fires true, but so do you...\n"
    	         << "Your pistols fire simultaneously, and you both fall to the ground!\n"
    	         << "We will call this one a Draw" << endl;
    	    draws++;
            game_over = true;
            difficulty = 0;
          } else if (comp_decision == kCompShoot && toupper(user_decision) == kUserBlock){
    	    cout << "Cowboy Dan's bullet races toward you...\n"
    	         << "But your magical bullet shield repels the projectile!\n"
    	         << "Whew, that was close!" << endl;
    	  } else if (comp_decision == kCompShoot && toupper(user_decision) == kUserLoad){
    	    cout << "You fumble as you try to fit the bullet into your pistol...\n"
    	         << "You hear the gunshot before you feel the wound in your belly...\n"
    	         << "Cowboy Dan seems almost as surprised as you are!  You lose." << endl;
    	    losses++;
            game_over = true;
            difficulty = 0;
    	  } else if (comp_decision == kCompBlock && toupper(user_decision) == kUserShoot){
    	    cout << "Your bullet speeds toward Cowboy Dan...\n"
    	         << "But he has a magical bullet shield!\n"
    	         << "Your shot is repelled, the Shootout continues!" << endl;
          } else if (comp_decision == kCompLoad && toupper(user_decision) == kUserShoot){
    	    cout << "Your bullet speeds toward Cowboy Dan...\n"
    	         << "Cowboy Dan fumbles with a bullet, trying to load his pistol...\n"
    	         << "Just as your bullet strikes him in the chest!\n"
    	         << "You have defeated Cowboy Dan!\n";
            wins++;
            game_over = true;
            difficulty = 0;
    	  }
    	  round++;
    	  cout << "<PRESS ENTER TO CONTINUE>" << endl;
    	  press_enter = reader.readString(true, 0);
    	} while (game_over == false);
    }
    // Output the ongoing results from successive shootout rounds and add to the game counter
    cout << "Wins  : " << wins << endl;
    cout << "Losses: " << losses << endl;
    cout << "Draws : " << draws << endl;
    game++;

    // Does the player want to try again?
    cout << "Care for another game of shootout?\n"
    	 << "ENTER <Y> TO PLAY AGAIN OR <N> TO QUIT" << endl;
    again = reader.readChar("YNyn");
    cout << endl;
  } while (toupper(again) == 'Y');
  // This ends the program
  return 0;
}

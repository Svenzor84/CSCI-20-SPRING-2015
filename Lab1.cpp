/*
 * program.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: mc146u02
 */
//Author : Steve Ross-Byers

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::srand;
using std::time;
using std::rand;

//Program starts here
int main(){
  //Setting up variables
  int computer_number, user_guess, user_attempts = 0;
  char user_response;
  //seeding the random number generator
  srand(time(0));
  //Tell the user that he/she will be attempting to guess a number between 1 and 10 randomly chosen by the computer
  cout << "This is a game where you will try to guess a number between 1-10, chosen at random by the computer... " << endl;
  //Tell the user that he/she will get three tries
  cout << "You will get three tries to guess the number" << endl;
  //Ask the user to input their guess
  cout << "What is your guess?" << endl;
  //Store the user's guess
  cin >> user_guess;
  //Computer randomly picks a number between 1 and 10, store the randomly chosen number
  computer_number = (rand() % 10 + 1);
  //Check the randomly chosen number against the user's chosen number and tell the user if they guessed high, low, or correctly, and add up the user's attempts
  if(user_guess == computer_number){
    //Display the computer's chosen number
    cout << "The computer has chosen " << computer_number << "." << endl;
    cout << "You guessed correctly!  You have won!  Are you some sort of wizard?" << endl;
    //Ask the user if they would like to play again.
    cout << "Would you like to play again? Y or N" << endl;
    cin >> user_response;
  }else if(user_guess > computer_number){
    cout << "You guessed too high, give it another try" << endl;
    user_attempts = user_attempts + 1;
    cout << "You have " << 3 - user_attempts << " tries remaining." << endl;
    cout << "What is your guess?" << endl;
    cin >> user_guess;
  }else if(user_guess < computer_number){
    cout << "You guessed too low, give it another try" << endl;
    user_attempts = user_attempts + 1;
    cout << "You have " << 3 - user_attempts << " tries remaining." << endl;
    cout << "What is your guess?" << endl;
    cin >> user_guess;
  }else{
  }
  //Check the randomly chosen number against the user's chosen number and tell the user if they guessed high, low, or correctly, and add up the user's attempts
  if(user_guess == computer_number){
      //Display the computer's chosen number
      cout << "The computer has chosen " << computer_number << "." << endl;
      cout << "You guessed correctly!  You have won!  Are you some sort of wizard?" << endl;
      //Ask the user if they would like to play again.
      cout << "Would you like to play again? Y or N" << endl;
      cin >> user_response;
    }else if(user_guess > computer_number){
      cout << "You guessed too high, give it another try" << endl;
      user_attempts = user_attempts + 1;
      cout << "You have " << 3 - user_attempts << " tries remaining." << endl;
      cout << "What is your guess?" << endl;
      cin >> user_guess;
    }else if(user_guess < computer_number){
      cout << "You guessed too low, give it another try" << endl;
      user_attempts = user_attempts + 1;
      cout << "You have " << 3 - user_attempts << " tries remaining." << endl;
      cout << "What is your guess?" << endl;
      cin >> user_guess;
    }else{
    }
  //Check the randomly chosen number against the user's chosen number and tell the user if they guessed correctly or incorrectly on their last attempt
  if(user_guess == computer_number){
        //Display the computer's chosen number
        cout << "The computer has chosen " << computer_number << "." << endl;
        cout << "You guessed correctly!  You have won!  Are you some sort of wizard?" << endl;
        //Ask the user if they would like to play again.
        cout << "Would you like to play again? Y or N" << endl;
        cin >> user_response;
  }else{
        //Display the computer's chosen number
        cout << "The computer has chosen " << computer_number << "." << endl;
        cout << "You have used all of your guesses, and have lost the game.  Don't cry, you can try again!" << endl;
        //Ask the user if they would like to play again.
        cout << "Would you like to play again? Y or N" << endl;
        cin >> user_response;
  }

return 0;
}





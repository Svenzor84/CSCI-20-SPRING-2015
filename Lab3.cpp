/*
 * Lab 3.cpp
 *
 *  Created on: Feb 25, 2015
 *  Author: Steve Ross-Byers
 *  Description : My Convenience Store
 *  Sources Used : CinReader (by Boyd Trolinger)
 */

#include <iostream>
#include <cstdlib>
#include "CinReader.h"

using std::cout;
using std::cin;
using std::endl;

//Program starts here
int main() {
  //Set up CinReader
  CinReader reader;

  //Set up variables
  int cust_choice = 0, cust_total = 0, cust_pay = 0, cust_change = 0,
      soda_count = 0, sand_count = 0, cards_count = 0, magic_count = 0, comic_count = 0,
	  cust_count = 0; //this last variable carries the amount to be added to the item counts above
  char cust_shop, cust_receipt_choice;

  //Set up enumerated types
  enum CustomerChoices{kSoda = 1, kSandwich = 2, kCards = 3, kMagic = 4, kComic = 5};

  //Welcome the customer to the store and ask if they would like to shop
  cout << "Welcome to SRB Corner Convenience!\n"
       << "\n"
       << "We have a few items for you to choose, and our prices are sorta-fair!\n"
       << "\n"
	   << "Unfortunately, we can only take payment in pennies...\n"
	   << "\n"
       << "Would you like to shop?\n"
       << "<ENTER <Y> TO SHOP OR <N> TO LEAVE>" << endl;
  cust_shop = reader.readChar("YyNn");
  while (toupper(cust_shop) == 'Y'){
    //Set the customer's count to zero
    cust_count = 0;

    //Explain the store's policies, list our inventory, and get the customer's choice
    cout << "\n"
         << "\n"
         << "What would you like to purchase?\n"
         << "     <1> Cherry RC Cola - 150 pennies\n"
         << "     <2> Ham & Cheese Sandwich - 500 pennies\n"
         << "     <3> Deck of Playing Cards - 350 pennies\n"
         << "     <4> Magic the Gathering Booster Pack - 400 pennies\n"
         << "     <5> New Mutants #98 (Marvel Comic Book) - 20000 pennies\n"
         << "\n"
         << "<PLEASE ENTER THE NUMBER OF YOUR CHOICE>" << endl;
    cust_choice = reader.readInt(kSoda,kComic);
    switch (cust_choice){
      case kSoda:
        cout << "Cherry RC Cola, a great choice to quench your thirst!" << endl;
        cout << "How many would you like?\n";
        cust_count = reader.readInt(0);
        cust_total = (cust_count * 150) + cust_total;
        soda_count+= cust_count;
        break;


  //make the next ones like this first one!


      case kSandwich:
        cout << "I made that sandwich myself, enjoy!" << endl;
        cout << "How many would you like?\n";
        cust_count = reader.readInt(0);
        cust_total = (cust_count * 500) + cust_total;
        sand_count+= cust_count;
        break;
      case kCards:
        cout << "These are great for Solitaire, Black Jack, or Texas Hold-Em!" << endl;
        cout << "How many would you like?\n";
        cust_count = reader.readInt(0);
        cust_total = (cust_count * 350) + cust_total;
        cards_count+= cust_count;
        break;
      case kMagic:
        cout << "Trying to improve your deck for this week's tournament?\n"
             << "Good decision, the competition should be fierce!" << endl;
        cout << "How many would you like?\n";
        cust_count = reader.readInt(0);
        cust_total = (cust_count * 400) + cust_total;
        magic_count+= cust_count;
        break;
      case kComic:
        cout << "The first appearance of the Merc with a Mouth, Deadpool!\n"
             << "I knew you had good taste!" << endl;
        cout << "How many would you like?\n";
        cust_count = reader.readInt(0);
        cust_total = (cust_count * 20000) + cust_total;
        comic_count+= cust_count;
        break;
    }
  cout << "Your current total is: " << cust_total << " cents\n"
	   << "\n";

  //Ask the customer if they would like to shop some more
  cout << "Would you like to shop some more?\n"
       << "<PLEASE ENTER <Y> TO SHOP MORE OR <N> TO CHECKOUT>" << endl;
  cust_shop = reader.readChar("YyNn");
  };
  //Tell the customer their total, receive their payment, and give change
    cout << "\n"
         << "Your total for this transaction is: " << cust_total << " cents\n"
         << "<ENTER THE NUMBER OF PENNIES YOU GIVE TO THE CLERK>" << endl;
    cust_pay = reader.readInt(0);
    //Make sure the customer gave you enough money
    while (cust_pay < cust_total){
      cout << "You have not given me enough cash, please re-enter the amount: " << endl;
      cust_pay = reader.readInt();
    };
    cout << "\n"
         << "Thank you for your payment of " << cust_pay << " cents!"
         << "\n" << endl;

    cust_change = cust_pay - cust_total;
    if (cust_change > 0){
      cout << "Looks like I owe you some change...\n"
           << "Your change will be: " << cust_change << " cents!" << endl;
    };
  //Ask the customer if they would like a receipt and show receipt if so
  cout << "Would you like to see your receipt?\n"
       << "<ENTER <Y> TO VIEW RECEIPT OR <N> FOR NO RECEIPT>" << endl;
  cust_receipt_choice = reader.readChar("YyNn");
  cout << "\n";

  if(toupper(cust_receipt_choice) == 'Y'){
    cout << "+-------------------------------------+\n"
    	 << "|       SRB Corner Convenience        |\n"
         << "|              Receipt                |\n"
		 << "|-------------------------------------+\n"
		 << "|                                     |\n"
		 << "|    Items                Cost        |\n"
		 << "|   -------              ------       |\n";
    if (soda_count != 0){
      for(soda_count; soda_count > 0; soda_count--){
	    cout << "|-Cherry RC Cola         150 cents    |\n";
	}}
    if (sand_count != 0){
      for(sand_count; sand_count > 0; sand_count--){
        cout << "|-Ham & Cheese Sandwich  500 cents    |\n";
    }}
    if (cards_count != 0){
      for(cards_count; cards_count > 0; cards_count--){
        cout << "|-Deck of Playing Cards  350 cents    |\n";
    }}
    if (magic_count != 0){
      for(magic_count; magic_count > 0; magic_count--){
      cout << "|-Magic Booster Pack     400 cents    |\n";
    }}
	if (comic_count != 0){
	  for(comic_count; comic_count > 0; comic_count--){
	  cout << "|-New Mutants #98        20000 cents  |\n";
	}}
    cout << "|\n"
	     << "|Your Total:    " << cust_total << " cents\n"
         << "|Cash Recieved: " << cust_pay << " cents\n"
         << "|                                     |\n"
         << "|Change Given:  " << cust_change << " cents\n"
         << "|-------------------------------------+\n"
         << "|Thank you for shopping with us today!|\n"
         << "+-------------------------------------+" << endl;
  }
  //This ends the program
  return 0;
}

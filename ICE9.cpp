//============================================================================
// Name        : ICE9.cpp
// Author      : Steve Ross-Byers
// Version     :
// Copyright   : Your copyright notice
// Description : Working on Classes
//============================================================================
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Card{
 public:
  void Set(int rank, char suit);
  void Output();
 private:
  int rank_;
  char suit_;
};
 int main(){
   srand(time(0));
   int rank;
   char suit;

   // Create the random rank
   rank = rand() % 13 + 1;
   suit = rand() % 4;

   if (suit == 0){
     suit = 'H';
   } else if (suit == 1){
     suit = 'D';
   } else if (suit == 2){
     suit = 'S';
   } else {
     suit = 'C';
   }

   Card srb_card;
   srb_card.Set(rank, suit);

   srb_card.Output();

   return 0;
 }


void Card::Set(int rank, char suit){
  if (rank >= 1 && rank <= 13){
    rank_ = rank;
  } else {
    rank_ = 1;
  }
  if (suit == 'H' || suit == 'D' ||
      suit == 'S' || suit == 'C'){
    suit_ = suit;
  } else {
    suit_ = 'S';
  }
}

void Card::Output(){
  switch (rank_) {
    case 1:
      cout << "Ace";
      break;
    case 11:
      cout << "Jack";
      break;
    case 12:
      cout << "Queen";
      break;
    case 13:
      cout << "King";
      break;
    default:
      cout << rank_;
  }
  cout << " of ";
  if(suit_ == 'H'){
    cout << "Hearts";
  } else if(suit_ == 'S'){
    cout << "Spades";
  } else if(suit_ == 'D'){
    cout << "Diamonds";
  } else {
    cout << "Clubs";
  }
  cout << endl;
}

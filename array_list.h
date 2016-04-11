/*
 * Name: array_list.h
 * Author: Steve Ross-Byers
 * Description: Class Header File
 */
// Header Guard
#ifndef ARRAY_LIST_SteveRossByers
#define ARRAY_LIST_SteveRossByers

#include <iostream>
#include <string>
using std::endl;
using std::cout;
using std::cerr;
using std::string;

// CLASS DESCRIPTION GOES HERE
class ArrayList {
 public:
   // Constructor
  ArrayList();

  // Insert Function
  void Insert(double value);

  //Element Return Function
  double GetElement(int location);

  //List Output Function
  void Output();

  //List Size Output Function
  int GetSize();

  //List Sum Output Function
  double Sum();

  //List Average Output Function
  double Average();

  //List Max Value Output Function
  double Max();

  //Clear List Function
  void Clear();

 private:
  // This creates a constant to use for the size of the array
  static const int kMaxArraySize = 10;
  // Create an Array of kMaxArraySize size.
  double list_[kMaxArraySize];
  // Create a variable to hold the current size of the array. Note this means
  // how many elements are in the array, not how many it can hold
  int size_;
};

#endif

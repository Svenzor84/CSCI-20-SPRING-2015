/*
 * Name        : lab_5_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit Test for class ArrayList.
 *               THIS FILE SHOUD NOT BE ALTERED, UNLESS DEBUGGING IN MAIN
 */

#include <iostream>
#include <sstream>
#include <streambuf>
#include "array_list.h"
using std::cout;
using std::endl;
using std::string;

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "");
void UnitTest();

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  // Tests
  ArrayList my_list;
  std::stringstream sserr, ssout;
  std::streambuf* old_cerr = std::cerr.rdbuf(sserr.rdbuf());
  string empty = "List Empty";
  string full = "List Full";
  string no_value = "No Item At Location";
  int value;

  Test(my_list.GetSize() == 0, "Default Constructor & GetSize()");
  value = my_list.GetElement(0);
  Test(sserr.str() == no_value && value == 0, "GetElement(0)");
  sserr.str("");
  value = my_list.GetElement(-1);
  Test(sserr.str() == no_value && value == 0, "GetElement(-1)");
  sserr.str("");
  my_list.Sum();
  Test(sserr.str() == empty, "Sum()");
  sserr.str("");
  my_list.Average();
  Test(sserr.str() == empty, "Average()");
  sserr.str("");
  my_list.Max();
  Test(sserr.str() == empty, "Max()");
  sserr.str("");

  std::streambuf* old_cout = std::cout.rdbuf(ssout.rdbuf());
  my_list.Output();
  cout.rdbuf(old_cout);
  Test(ssout.str() == "" && sserr.str() == empty, "Output()");
  sserr.str("");
  ssout.str("");

  cout << "\nAdding the values 2.5, 8.8, 5.5, 7.3, 1.1 to the list\n\n";
  my_list.Insert(2.5);
  my_list.Insert(8.8);
  my_list.Insert(5.5);
  my_list.Insert(7.3);
  my_list.Insert(1.1);
  Test(my_list.GetSize() == 5, "Insert() & GetSize()");

  old_cout = std::cout.rdbuf(ssout.rdbuf());
  my_list.Output();
  cout.rdbuf(old_cout);
  Test(ssout.str() == "2.5, 8.8, 5.5, 7.3, 1.1", "Output()");
  ssout.str("");

  Test(my_list.GetElement(3) == 5.5, "GetElement(3)");

  Test(my_list.Sum() >= 25.19 && my_list.Sum() <= 25.21, "Sum()");
  Test(my_list.Average() >= 5.039 && my_list.Average() <= 5.041, "Average()");
  Test(my_list.Max() >= 8.79 && my_list.Max() <= 8.81, "Max()");

  cout << "\nClearing the list\n\n";
  my_list.Clear();
  Test(my_list.GetSize() == 0, "Clear() & GetSize()");
  old_cout = std::cout.rdbuf(ssout.rdbuf());
  my_list.Output();
  cout.rdbuf(old_cout);
  Test(ssout.str() == "" && sserr.str() == empty, "Output()");
  sserr.str("");
  ssout.str("");

  cout << "\nAdding the values 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 to the list"
       << endl << endl;
  my_list.Insert(1);
  my_list.Insert(2);
  my_list.Insert(3);
  my_list.Insert(4);
  my_list.Insert(5);
  my_list.Insert(6);
  my_list.Insert(7);
  my_list.Insert(8);
  my_list.Insert(9);
  my_list.Insert(10);
  my_list.Insert(11);

  Test(sserr.str() == full, "Insert() \"One too many\"");
  Test(my_list.GetSize() == 10, "GetSize()");

  old_cout = std::cout.rdbuf(ssout.rdbuf());
  my_list.Output();
  cout.rdbuf(old_cout);
  Test(ssout.str() == "1, 2, 3, 4, 5, 6, 7, 8, 9, 10", "Output()");
  ssout.str("");

  // Restore cerr
  std::cerr.rdbuf(old_cerr);
  cout << string(temp.length() - 1, '-') << endl;
  cout << "Unit Test Complete!\n\n";
}

// For testing (DO NOT ALTER)
void Test(bool test, string more_info) {
  static int test_number = 1;
  if (test)
    cout << "PASSSED TEST ";
  else
    cout << "FAILED  TEST ";
  cout << test_number << " " << more_info << "!\n";
  test_number++;
}


/*
 * Name        : driver.cpp
 * Author      : Luke Sathrum
 * Description : Unit Test for Item Class
 */
#include <iostream>
#include <string>
#include <sstream>
#include "item.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void UnitTest();
void Test(bool test, int line_number, string more_info = "", string yours = "!",
          string actual = "!");
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 8;
std::vector<int> failed_tests;

// Program Execution Starts Here
int main() {
  // If you want you can create instances of your Item class and test it here.

  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// For testing (DO NOT ALTER)
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Tests: " << num_of_tests << endl;
  string yours = "", actual = "";
  stringstream ss;
  ss.setf(std::ios::showpoint | std::ios::fixed);
  ss.precision(2);

  Item test;

  yours = test.name();
  actual = "Item";
  Test(yours == actual, __LINE__, "Default Constructor and name()", yours,
       actual);

  ss << test.price();
  yours = ss.str();
  actual = "0.00";
  Test(yours == actual, __LINE__, "Default Constructor and price()", yours,
       actual);
  ss.str("");

  ss << test.quantity();
  yours = ss.str();
  actual = "0";
  Test(yours == actual, __LINE__, "Default Constructor and quantity()", yours,
       actual);
  ss.str("");

  ss << test.Subtotal();
  yours = ss.str();
  actual = "0.00";
  Test(yours == actual, __LINE__, "Default Constructor and Subtotal()", yours,
       actual);
  ss.str("");

  test.set_name("M&M");
  yours = test.name();
  actual = "M&M";
  Test(yours == actual, __LINE__, "set_name() and name()", yours, actual);

  test.set_price(1.5);
  ss << test.price();
  yours = ss.str();
  actual = "1.50";
  Test(yours == actual, __LINE__, "set_price and price()", yours, actual);
  ss.str("");

  test.set_quantity(5);
  ss << test.quantity();
  yours = ss.str();
  actual = "5";
  Test(yours == actual, __LINE__, "set_quantity and quantity()", yours, actual);
  ss.str("");

  ss << test.Subtotal();
  yours = ss.str();
  actual = "7.50";
  Test(yours == actual, __LINE__, "Subtotal()", yours, actual);
  ss.str("");

  cout << string(40, '-') << endl;
  cout << "Passed: " << ut_passed << " / " << ut_total << endl;
  OutputFailedTests();
  cout << string(40, '-') << endl;
  cout << "END OF UNIT TEST!\n";
  cout << string(40, '-') << endl;
  cout << "Be sure to run 'make style' to check for any style errors.\n"
       << "Please note that 'make style' does NOT check variable names or"
       << " indentation" << endl << endl;
}

// For testing (DO NOT ALTER)
void Test(bool test, int line_number, string more_info, string yours,
          string actual) {
  ut_total++;
  if (test) {
    cout << "PASSED TEST ";
    ut_passed++;
  } else {
    cout << "FAILED TEST ";
    ut_failed++;
    failed_tests.push_back(ut_total);
  }
  cout << ut_total << " " << more_info << "!" << endl;
  if (!test) {
    if (yours != "!")
      cout << "Yours:  \"" << yours << '"' << endl;
    if (actual != "!")
      cout << "Actual: \"" << actual << '"' << endl;
    cout << "  Check Line " << line_number << " for more info" << endl;
  }
}

void OutputFailedTests() {
  if (failed_tests.size()) {
    cout << "Failed test number(s): ";
    for (unsigned int i = 0; i < failed_tests.size() - 1; i++)
      cout << failed_tests.at(i) << ", ";
    cout << failed_tests.at(failed_tests.size() - 1) << endl;
  }
}

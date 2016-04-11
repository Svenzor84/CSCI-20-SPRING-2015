/*
 * Name        : unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit Test to test your Lab #4 Temperature Class.
 */
#include <iostream>
#include <sstream>
#include <streambuf>
#include "temperature.h"
using std::cout;
using std::endl;

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "");
void UnitTest();

// Program Execution Starts Here
int main() {
  // Any of your code to test can be put below this comment

  // To help test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// For testing (DO NOT ALTER)
void UnitTest() {
  cout << "BEGIN UNIT TEST\n" << string(50, '-') << endl;
  // Tests
  Temperature temp1;
  Test(temp1.kelvin() == 0, "Default Constructor / kelvin()");
  temp1.set_kelvin(50);
  Test(temp1.kelvin() == 50, "set_kelvin(50) / GetTempAsCelsius()");
  temp1.SetTempFromCelsius(5);
  Test(
      temp1.GetTempAsFahrenheit() >= 40.99
          && temp1.GetTempAsFahrenheit() <= 41.01,
      "SetTempFromCelsius(5) / GetTempAsFarenheit()");
  temp1.SetTempFromFahrenheit(5);
  Test(temp1.kelvin() >= 258.149 && temp1.kelvin() <= 258.151,
       "SetTempFromFahrenheit(5) / kelvin()");

  std::streambuf* old_cout = cout.rdbuf();
  std::ostringstream capture_cout;
  cout.rdbuf(capture_cout.rdbuf());
  temp1.Output();
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "258.15 Kelvin", "Output()");
  capture_cout.str("");
  Temperature temp2(50);
  Test(
      temp2.GetTempAsFahrenheit() >= -369.68
          && temp2.GetTempAsFahrenheit() <= -369.66,
      "Constructor(50) / GetTempAsFahrenheit()");

  cout.rdbuf(capture_cout.rdbuf());
  temp2.Output('C');
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "-223.15 Celsius", "Output('C')");
  capture_cout.str("");
  Temperature temp3(5, 'F');
  Test(temp3.kelvin() >= 258.14 && temp3.kelvin() <= 258.16,
       "Constructor(5, 'F') / kelvin()");
  Temperature temp4(5, 'f');
  Test(temp4.kelvin() >= 258.14 && temp4.kelvin() <= 258.16,
       "Constructor(5, 'f') / kelvin()");
  Temperature temp5(5, 'C');
  Test(temp5.kelvin() >= 278.14 && temp5.kelvin() <= 278.16,
       "Constructor(5, 'C') / kelvin()");
  Temperature temp6(5, 'c');
  Test(temp6.kelvin() >= 278.14 && temp6.kelvin() <= 278.16,
       "Constructor(5, 'c') / kelvin()");
  Temperature temp7(5, 'K');
  Test(temp7.kelvin() == 5, "Constructor(5, 'K') / kelvin()");
  Temperature temp8(5, '5');
  Test(temp8.kelvin() == 5, "Constructor(5, '5') / kelvin()");

  cout.rdbuf(capture_cout.rdbuf());
  temp8.Output('c');
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "-268.15 Celsius", "Output('c')");
  capture_cout.str("");

  cout.rdbuf(capture_cout.rdbuf());
  temp8.Output('K');
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "5.00 Kelvin", "Output('K')");
  capture_cout.str("");

  cout.rdbuf(capture_cout.rdbuf());
  temp8.Output('k');
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "5.00 Kelvin", "Output('k')");
  capture_cout.str("");

  cout.rdbuf(capture_cout.rdbuf());
  temp8.Output('F');
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "-450.67 Fahrenheit", "Output('F')");
  capture_cout.str("");

  cout.rdbuf(capture_cout.rdbuf());
  temp8.Output('f');
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "-450.67 Fahrenheit", "Output('f')");
  capture_cout.str("");

  cout.rdbuf(capture_cout.rdbuf());
  temp8.Output('1');
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "Invalid Unit", "Output('1')");
  capture_cout.str("");

  cout << string(50, '-') << endl;
  cout << "END UNIT TEST" << endl;
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

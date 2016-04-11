/*
 * ice4.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: mc146u09
 */
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
  const int kMonthsInYear = 15;
  const int kWeeksInYear = 40;
  const int kDaysInYear = 365;
  const double pi = 3.14159265358979323846;
  //a
  cout << "average days per week = " << static_cast<double>(kDaysInYear) / kWeeksInYear << endl;
  //b
  cout << "average days per month = " << static_cast<double>(kDaysInYear) / kMonthsInYear << endl;
  //c
  cout << "average weeks per month =" << static_cast<double>(kWeeksInYear) / kMonthsInYear << endl;

  cout << "The answer to the question of\n" << "Life, the Universe, and Everything is 42." << endl;

  cout << "                      Tb.          Tb.                                \n" <<
          "                      :$$b.        $$$b.                             \n" <<
          "                      :$$$$b.      :$$$$b.                           \n" <<
          "                      :$$$$$$b     :$$$$$$b                           \n" <<
          "                       $$$$$$$b     $$$$$$$b                          \n" <<
          "                       $$$$$$$$b    :$$$$$$$b\n" <<
          "                       :$$$$$$$$b---^$$$$$$$$b\n" <<
          "                       :$$$$$$$$$b        ""^Tb\n" <<
          "                        $$$$$$$$$$b    __...__`.\n" <<
          "                        $$$$$$$$$$$b.g$$$$$$$$$pb\n" <<
          "                        $$$$$$$$$$$$$$$$$$$$$$$$$b\n" <<
          "                        $$$$$$$$$$$$$$$$$$$$$$$$$$b\n" <<
          "                        :$$$$$$$$$$$$$$$$$$$$$$$$$$;\n" <<
          "                        :$$$$$$$$$$$$$^T$$$$$$$$$$P;\n" <<
          "                        :$$$$$$$$$$$$$b  '^T$$$$P' : \n" <<
          "                        :$$$$$$$$$$$$$$b._.g$$$$$p.db\n" <<
          "                        :$$$$$$$$$$$$$$$$$$$$$$$$$$$$;\n" <<
          "                        :$$$$$$$$'''^^T$$$$$$$$$$$$P^;\n" <<
          "                        :$$$$$$$$       ''^^T$$$P^'  ;\n" <<
          "                        :$$$$$$$$    .'       `'     ;\n" <<
          "                        $$$$$$$$;   /                :\n" <<
          "                        $$$$$$$$;           .----,   :\n" <<
          "                        $$$$$$$$;         ,'          ;\n" <<
          "                        $$$$$$$$$p.                   |\n" <<
          "                       :$$$$$$$$$$$$p.                :\n" <<
          "                       :$$$$$$$$$$$$$$$p.            .'\n" <<
          "                       :$$$$$$$$$$$$$$$$$$p...___..-'\n" <<
          "                       $$$$$$$$$$$$$$$$$$$$$$$$$;\n" <<
          "    .db.          bug  $$$$$$$$$$$$$$$$$$$$$$$$$$\n" <<
          "   d$$$$bp.            $$$$$$$$$$$$$$$$$$$$$$$$$$;\n" <<
          "  d$$$$$$$$$$pp..__..gg$$$$$$$$$$$$$$$$$$$$$$$$$$$\n" <<
          " d$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$p._           .gp.\n" <<
          " $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$p._.ggp._.d$$$$b\n" << endl;

  cout.setf(std::ios::showpoint|std::ios::fixed);
  cout.precision(0);
  cout << pi << endl;
  cout.precision(1);
  cout << pi << endl;
  cout.precision(3);
  cout << pi << endl;
  cout.precision(10);
  cout << pi << endl;
  cout.precision(20);
  cout << pi << endl;
  cout.precision(80);
  cout << pi << endl;

  string first_name, last_name;
  int age;
  cout << "Enter your first name: " << endl;
  cin >> first_name;
  cout << "Enter your last name: " << endl;
  cin >> last_name;
  cout << "Enter your age: " << endl;
  cin >> age;
  cout << "You are " << age << " years old, " << first_name << " " << last_name <<endl;

}






/*
 * Name: temperature.cpp
 * Author: Steve Ross-Byers
 * Description: Temperature conversion program
 */

#include "temperature.h"

// CLASS FUNCTION DEFINITIONS GO HERE

Temperature::Temperature(){
  kelvin_ = 0;
}

Temperature::Temperature(double kelvin){
  kelvin_ = kelvin;
}

Temperature::Temperature(double temp, char unit){
  if(unit == 'C' || unit == 'c'){
    SetTempFromCelsius(temp);
  } else if (unit == 'F' || unit == 'f'){
    SetTempFromFahrenheit (temp);
  } else {
    set_kelvin(temp);
  }
}

void Temperature::set_kelvin(double kelvin){
  kelvin_ = kelvin;
}

void Temperature::SetTempFromCelsius(double celsius){
  kelvin_ = celsius + 273.15;
}

void Temperature::SetTempFromFahrenheit(double fahrenheit){
  kelvin_ = (5.0 * (fahrenheit - 32) / 9) + 273.15;
}

double Temperature::kelvin(){
  return kelvin_;
}

double Temperature::GetTempAsCelsius(){
  return (kelvin_ - 273.15);
}

double Temperature::GetTempAsFahrenheit(){
  return (((GetTempAsCelsius()) * 9.0) / 5) + 32;
}

void Temperature::Output(char unit){
  cout.setf(std::ios::showpoint|std::ios::fixed);
  cout.precision(2);
  unit = toupper(unit);
  if(unit == 'K'){
    cout << kelvin() << " Kelvin";
  } else if(unit == 'C'){
    cout << GetTempAsCelsius() << " Celsius";
  } else if(unit == 'F'){
    cout << GetTempAsFahrenheit() << " Fahrenheit";
  } else {
    cout << "Invalid Unit";
  }
}

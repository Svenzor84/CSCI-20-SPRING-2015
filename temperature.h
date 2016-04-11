/*
 * Name        : temperature.h
 * Author      : Steve Ross-Byers
 * Description : Class Header File
 */

// Header Guard
#ifndef TEMPERATURE_H_SteveRossByers
#define TEMPERATURE_H_SteveRossByers
 
#include <string>
#include <iostream>
using std::cout;
using std::string;

/*
 * Class Temperature.
 * A class that converts temperatures. It will always internally store the value
 * in kelvin.
 */
class Temperature {
 public:
  /*
   * Constructor #1.
   * Sets kelvin_ to 0
   */
  Temperature();

  /*
   * Constructor #2.
   * Sets kelvin_ to the supplied value
   * @param double kelvin - The value to set the internal kelvin_ to
   */
  Temperature(double kelvin);

  /*
   * Constructor #3.
   * Converts the supplied temperature to kelvin and internally stores it.
   * The temperature's unit will be provided in the second parameter.
   * If the second parameter is not valid (i.e. not 'F' or 'C') assume the
   * temperature is in kelvin
   * @param double temp - The value to set the internal kelvin to once
   *                    - converted.
   * @param char unit - The type of unit temp is. Will be either 'F' or 'C',
   *                    case-insensitive
   */
  Temperature(double temp, char unit);

  /*
   * Mutator
   * The temperature will come in as kelvin and this function will set the
   * internal temp to this value
   * @param double kelvin - The value to set the internal kelvin_ to.
   */
  void set_kelvin(double kelvin);

  /*
   * The temperature will come in as Celsius and this function will set the
   * internal temp to this value, once converted to kelvin
   * Formula: k = c + 273.15;
   * @param double celsius - The value (in celsius) to set the internal kelvin_
   *                         to.
   */
  void SetTempFromCelsius(double celsius);

  /*
   * The temperature will come in as Fahrenheit and this function will set the
   * internal temp to this value, once converted to kelvin
   * Formula: k = (5.0 * (f - 32) / 9) + 273.15
   * @param double fahrenheit - The value (in fahrenheit) to set the internal
   *                            kelvin to.
   */
  void SetTempFromFahrenheit(double fahrenheit);

  /*
   * Accessor
   * Gets the internal temperature in Kelvin.
   * @return double - The temperature in Kelvin
   */
  double kelvin();

  /*
   * Returns the internal temp converted to celsius
   * Formula: c = k - 273.15
   * @return double - The temperature in celsius
   */
  double GetTempAsCelsius();

  /*
   * Returns the internal temp converted to fahrenheit
   * Formula: f = ((c * 9.0) / 5) + 32;
   * @return double - The temperature in Fahrenheit
   */
  double GetTempAsFahrenheit();

  /*
   * Outputs a representation of the temperature.
   * NOTE: There is NO newline character at the end of output.
   * The output will be formatted as:
   * "TEMP UNIT"
   * where TEMP is the temperature to 2 decimal places and UNIT is either
   * "Kelvin", "Celsius", or "Fahrenheit".
   * The conversion to perform is denoted by the parameter.
   * If the unit given through the argument is invalid, output:
   * "Invalid Unit"
   * @param char unit - The conversion to perform, either 'K', 'C' or 'F',
   *                    defaults to 'K' and is case-insensitive
   */
  void Output(char unit = 'K');

 private:
  double kelvin_;
};

// The rest of the header guard
#endif /* TEMPERATURE_H */

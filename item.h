/*
 * Name          : item.h
 * Group Number  : 3
 * Group Members : Steve Ross-Byers & Austin Brake
 * Description   : Creating a class to represent an item.
 */

// Opening Header Guard
// HEADER GUARD GOES HERE

#include <string>
using std::string;

/*
 * The Item class represents a real world item that may be used in something
 * like a Convenience Store
 */
class Item {
 public:
  /*
   * Constructor
   * Sets name to "Item", price to 0 and quantity to 0
   */
  // CONSTRUCTOR DECLARATION / PROTOTYPE
   Item();
  /*
   * Function Name: Subtotal 
   * Returns quantity * price
   * @return double - The Quantity * The Price
   */
  // MEMBER FUNCTION DECLARATION / PROTOTYPE
   double Subtotal();

  // Accessors and Mutators (You will need 6 total, 3 of each)
  // ACCESSOR AND MUTATOR DECLARATIONS / PROTOTYPES
   string name();

   double price();

   int quantity();

   void set_name(string name);

   void set_price(double price);

   void set_quantity(int quantity);

 private:
  string name_;
  double price_;
  int quantity_;
};

// Closing Header Guard
// HEADER GUARD GOES HERE

/*
 * Name          : counter_type.cpp
 * Group Number  : Group 5
 * Group Members : Steve Ross-Byers and Luke Cramer
 * Description   : Creating a class to hold non-negative whole numbers.
 */

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

class CounterType {
 public:
  CounterType(int count);
  void set_count(int count);
  void Increase();
  void Decrease();
  int count();
  void Output();
 private:
  int count_;
  bool IsLegal(int count);
};

// Execution begins here
int main() {
  // Uncomment to test

  CounterType my_count(5);
  my_count.Output();
  my_count.Increase();
  cout << "count() is: " << my_count.count() << endl;
  my_count.Decrease();
  my_count.Output();
  my_count.set_count(500);
  my_count.Output();
  my_count.set_count(-10);
  my_count.Output();
  my_count.Decrease();
  my_count.Output();
  my_count.Increase();
  my_count.Output();

  // Program ends here
  return 0;
}

// Write Function Definitions Here
//Constructor
CounterType::CounterType(int count){
  if(IsLegal(count) == true){
    count_ = count;
} else {
  cerr << "Invalid value input, setting count to 0." << endl;
  count_ = 0;
  }
}
//Mutator
void CounterType::set_count(int count){
  if (IsLegal(count) == true){
    count_ = count;
  } else {
    cerr << "Invalid value input, setting count to 0." << endl;
    count_ = 0;   
  }
}

//Accessor
int CounterType::count(){
  return count_; 
  }

//Private function to check Legality
bool CounterType::IsLegal(int count){
  if (count >= 0){
    return true;
  } else {
    return false;
  }
}

//Other functions
void CounterType::Increase(){
  count_++;
}

void CounterType::Decrease(){
  if (count_ > 0){
    count_--;
  } else {
    cout << "The count has reached zero." << endl;
    count_ = 0;
  }
}

void CounterType::Output(){
  cout << "The current count is " << count_ << endl;
}

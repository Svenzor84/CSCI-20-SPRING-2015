#include "array_list.h"

// The second part of creating a constant for our class
const int ArrayList::kMaxArraySize;

// YOUR MEMBER FUNCTION DEFINITIONS GO HERE
// Constructor
  ArrayList::ArrayList(){
    size_ = 0;
  }

  // Insert Function
  void ArrayList::Insert(double value){
    if(size_ < 10){
      list_[size_] = value;
      size_++;
    } else {
      cerr << "List Full";
    }
  }

  //Element Return Function
  double ArrayList::GetElement(int location){
    if((location - 1) >= 0 && (location - 1) < size_){
      return list_[location - 1];
    } else {
      cerr << "No Item At Location";
      return 0;
    }
  }

  //List Output Function
  void ArrayList::Output(){
    if(size_ >  0){
      for(int i = 0; i < (size_ - 1); i++){
        cout << list_[i] << ", ";
      }
      cout << list_[(size_ - 1)];
    } else {
      cerr << "List Empty";
    }
  }

  //List Size Output Function
  int ArrayList::GetSize(){
    return size_;
  }

  //List Sum Output Function
  double ArrayList::Sum(){
    if(size_ >  0){
      double list_sum = 0.0;
      for(int i = 0; i < size_; i++){
        list_sum = list_sum + list_[i];
      }
      return list_sum;
    } else {
      cerr << "List Empty";
      return 0.0;
    }
  }

  //List Average Output Function
  double ArrayList::Average(){
    if(size_ > 0){
      return (Sum()/GetSize());
    } else {
      cerr << "List Empty";
      return 0.0;
    }
  }

  //List Max Value Output Function
  double ArrayList::Max(){
    if(size_ > 0){
      double max_val = 0;
      for(int i = 0; i < size_; i++){
        if(list_[i] > max_val){
          max_val = list_[i];
        }
      }
      return max_val;
    } else {
      cerr << "List Empty";
      return 0.0;
    }
  }

  //Clear List Function
  void ArrayList::Clear(){
	  size_ = 0;
  }

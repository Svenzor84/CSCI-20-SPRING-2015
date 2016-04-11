/*
 * Name          : item.cpp
 * Group Number  : 3
 * Group Members : Steve Ross-Byers & Austin Brake
 * Description   : Creating a class to represent an item.
 */

#include "item.h"

// Member Function Definitions

Item::Item(){
  name_ = "Item";
  price_ = 0;
  quantity_ = 0;
}

double Item::Subtotal(){
  return price_ * quantity_;
}

string Item::name(){
  return name_;
}

double Item::price(){
  return price_;
}

int Item::quantity(){
  return quantity_;
}

void Item::set_name(string name){
  name_ = name;
}

void Item::set_price(double price){
  price_ = price;
}

void Item::set_quantity(int quantity){
  quantity_ = quantity;
}

#pragma once
#include <iostream>
#include "node.h"

class List{
 private:
  Node *head;
 public:
  List();
  void insert(std::string data);
  void insert(int loc, std::string data); //0 indexed
  int length();
  bool contains(std::string item);
  std::string toString(); // for testing purposes
  void remove(int loc);
  void destructor();
  /*
    Try to complete for Monday:
    
    get()
    and think about the remove and 
    other insert routine
    
    -------------------
    ~List();
    
  void remove(int loc);
  std::string get(int loc);
  bool contains();
  int length(); // the # of elements
  */
  
  

};
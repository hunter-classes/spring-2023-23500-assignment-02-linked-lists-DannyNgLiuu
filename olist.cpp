#include <iostream>
#include "node.h"
#include "olist.h"

Olist::Olist() {
    head = nullptr;
}

    Olist::~Olist() {
    Node *walker;
    walker = this->head;

    while(walker != nullptr) {
      walker = head;
      head = head->getNext();
      free(walker);
      walker = head;
    }

}

int Olist::length(){
  int count = 0;
  Node *walker = head;
  while (walker != nullptr){
    count++;
    walker = walker->getNext();
  }
  return count;
}

void Olist::insert(std::string value){
  Node *tmp = new Node(value);
  tmp->setNext(head);
  head = tmp;
}

void Olist::insert(int loc, std::string data){
  Node *walker, *trailer;
  walker = this->head; // start of the list
  trailer = nullptr; // one behind
  
  while(loc>0 && walker != nullptr){
    loc=loc-1;

    /* trailer will always be one node
       behind walker */
    trailer=walker;
    walker = walker->getNext();
    
  }

  // At this point, trailer points to the Node
  // BEFORE where we want to insert


  // test to see if we're trying to
  // insert past the end 
  if (loc > 0){
    // do something to indicate this is invalid
    throw std::out_of_range("Our insert is out of range");
  }

  Node *newNode = new Node(data);
  // Inserting at true location 0
  // will have trailer == nullptr
  // - we have to treat that as a special case
  if (trailer == nullptr){
    newNode->setNext(head);
    head = newNode;
  } else {
    // do the regular case 
    newNode->setNext(walker);
    trailer->setNext(newNode);
  }
}

std::string Olist::toString(){
  Node *tmp = this->head;
  std::string result = "";
  while (tmp != nullptr){
    result = result + tmp->getData();
    result = result + "-->";
    tmp = tmp->getNext();
  }
  result = result + "nullptr";
  return result;
}

bool Olist::contains(std::string item) {
  Node *walker = head;
  while(walker != nullptr) {
    if(walker->getData() == item) {
        return true;
    }
    walker = walker->getNext();
  }
  return false;      
}

std::string Olist::get(int loc) {
  
  int count = 0;
  Node *walker = head;
  while (walker != nullptr){
    count++;
    walker = walker->getNext();
  }

  if(loc >= count) {
    //throw std::out_of_range("Our insert is out of range");
    return "Our insert is out of range";
  }

 Node *trailer;
  walker = this->head;
  trailer = nullptr;

  while(loc>0 && walker != nullptr){
    loc=loc-1;

    trailer=walker;
    walker = walker->getNext();
  }

  if (loc < 0){
    //throw std::out_of_range("Our insert is out of range");
    return "Our insert is out of range";
  }

  return walker->getData();
}

void Olist::remove(int loc) {
  Node *walker, *trailer;
  walker = this->head;
  trailer = nullptr;
  
  while(loc>0 && walker != nullptr){
    loc=loc-1;
    trailer=walker;
    walker = walker->getNext();
  }

  if (walker == nullptr){
    throw std::out_of_range("Tried to remove out of range");
  }

  if (trailer == nullptr){
    head = walker->getNext();
    delete walker;
  } else {
    trailer->setNext(walker->getNext());
    delete walker;   
  }
}

void Olist::reverse() {
    Node* trailer = nullptr;
    Node* walker = this->head;
    Node* dog = nullptr;
    
    while (walker != nullptr) {
        dog = walker->getNext();
        walker->setNext(trailer);
        trailer = walker;
        walker= dog;
    }
    
    head = trailer;
}
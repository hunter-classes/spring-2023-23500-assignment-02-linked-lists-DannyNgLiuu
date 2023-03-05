#pragma once
#include <iostream>
#include "node.h"

class Olist {
    private:
    Node *head;
    public:
    Olist();
    void destructor();
    int length();
    void insert(std::string value);
    void insert(int loc, std::string value);
    std::string toString();
    bool contains(std::string item);
    std::string get(int loc);
    void remove(int loc);
    void reverse();
};
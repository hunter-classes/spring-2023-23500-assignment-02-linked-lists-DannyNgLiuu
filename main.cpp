#include <iostream>
#include "list.h"
#include "node.h"

int main() {
    List *l = new List();
    std::cout << l->toString() << " " << l->length() << "\n";
    l->insert(0,"a");
    std::cout << l->toString() << " " << l->length() << "\n";
    l->insert(0,"b");
    l->insert(0,"c");
    l->insert(0,"d");
    std::cout << l->toString() << " " << l->length() << "\n";
    if(l->contains("aa")) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
    l->remove(3);
    std::cout << l->toString() << " " << l->length() << "\n";
}
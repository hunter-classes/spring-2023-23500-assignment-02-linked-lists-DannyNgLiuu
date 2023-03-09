#include <iostream>
#include "list.h"
#include "olist.h"
#include "node.h"

int main() {
    //part 1 testing

    List *l = new List();
    std::cout << l->toString() << " " << l->length() << "\n";
    l->insert(0,"a");
    std::cout << l->toString() << " " << l->length() << "\n";
    l->insert(0,"b");
    l->insert(0,"c");
    l->insert(0,"d");
    std::cout << l->toString() << " " << l->length() << "\n";
    if(l->contains("dd")) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
    l->remove(3);
    std::cout << l->toString() << " " << l->length() << "\n";
    std::cout << "-------- \n";
    delete l;

    // //part 2 testing
    // Olist *l = new Olist();
    // std::cout << l->toString() << " " << "\n";
    // l->insert(0,"1");
    // std::cout << l->toString() << " " << "\n";
    // l->insert(0,"2");
    // l->insert(0,"4");
    // l->insert(0,"5");
    // std::cout << l->toString() << " " << "\n";
    // //l->destructor();
    // std::cout << l->toString() << " " << "\n";
    // std::cout << l->get(4) << "\n";
    // //l->remove(3);
    // std::cout << l->toString() << " " << "\n";
    // //l->reverse();
    // //std::cout << l->toString() << " " << "\n";  
}   
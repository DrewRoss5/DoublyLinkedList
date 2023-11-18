#include <iostream>
#include "linkedlist.h"


int main(){
    LinkedList list(1, 2);
    // insert values
    list.pushEnd(4);
    list.pushStart(0);
    list.insertAfter(2, 3);
    list.insertBefore(3, 2);
    // remove values
    list.deleteVal(2);
    Node *node = list.popStart();
    std::cout << node->getVal() << std::endl;
    delete node;
    // display nodes
    list.printNodes();
    std::cout << "----------" << std::endl;
    list.printNodesReverse();
    // clear memory
    list.deleteNodes();
}
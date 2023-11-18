#include <iostream>
#include "node.h"

class LinkedList{
    private: 
        Node *head;
        Node *tail;

    public:
        // initalizes a linked list with head and tail
        LinkedList(int headVal, int tailVal){
            head = new Node(headVal, NULL, NULL);
            tail = new Node(tailVal, head, NULL);
            head->setNext(tail);
        }
        // linked list functions
        void printNodes(){
            Node *node = head;
            while (node != NULL){
                std::cout << node->getVal() << std::endl;
                node = node->getNext();
            }
        }
        void printNodesReverse(){
            Node *node = tail;
            while (node != NULL){
                std::cout << node->getVal() << std::endl;
                node = node->getPrev();
            }
        }
        // pushes a value to the start of the linked list
        void pushStart(int val){
            Node *newNode = new Node(val, NULL, head);
            head->setPrev(newNode);
            head = newNode;
        }
        // pushes a value to the end of the linked list
        void pushEnd(int val){
            Node *newNode = new Node(val, tail, NULL);
            tail->setNext(newNode);
            tail = newNode;
        }
        // inserts a value before a specified value, inserts the new value at the end if the specified value could not be found
        void insertBefore(int val, int newVal){
            Node *node = head;
            while (node->getVal() != val && node->getNext() != NULL){
                node = node->getNext();
            }
            if (node->getVal() == val){
                Node *prev = node->getPrev();
                Node* newNode = new Node(newVal, prev, node);
                node->setPrev(newNode);
                prev->setNext(newNode);
            }
            else{
                pushEnd(newVal);
            }
        }
        // inserts a new value before a specified value, inserts the new value at the end if the specified value could not be found
        void insertAfter(int val, int newVal){
            Node *node = head;
            while (node->getVal() != val && node->getNext() != NULL){
                node = node->getNext();
            }
            if (node->getVal() == val){
                Node *next = node->getNext();
                Node* newNode = new Node(newVal, node, next);
                node->setNext(newNode);
                next->setPrev(newNode);
            }
            else{
                pushEnd(newVal);
            }
        }
        // pops the first element
        Node *popStart(){
            Node *returnVal = head;
            // make the node after the head the new head
            head = head->getNext();
            head->setPrev(NULL);
            return returnVal;

        }
        // pops the last element
        Node *popEnd(){
            Node *returnVal = tail;
            // make the node after the head the new head
            head = tail->getPrev();
            head->setNext(NULL);
            return returnVal;
        }
        // deletes the first node with a specified value
        void deleteVal(int val){
            Node *node = head;
            while(node->getVal() != val && node->getNext() != NULL){
                node = node->getNext();
            }
            // ensure the value was actually found and the search didn't simply reach the end of the list
            if (node->getVal() == val){
                node->deleteNode();
            }
        }
        // deletes each node, freeing the memory
        void deleteNodes(){
            Node *current = head->getNext();
            Node *next;
            while(current->getNext() != NULL){
                next = current->getNext();
                delete current;
                current = next;
            }
            delete current;
            delete head;
        }
        // getter functions
        Node *getHead(){
            return head;
        }

        Node *getTail(){
            return tail;
        }
        // returns a node with a specified value or NULL if no node with the appropriate value can be found
        Node *getNode(int val){
            Node *node = head;
            while (node->getNext() != NULL && node->getVal() != val){
                node = node->getNext();
                if (node->getVal() == val){
                    return node;
                }
            }
            return NULL;
        }

};
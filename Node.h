#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std;

class Node {
 public:
  Node();
  Node(char* nStr);
  ~Node();
  
  char* getStr();

  void setNext(Node* nNext);
  Node* getNext();

 private:
  char* str;
  Node* next;
};

#endif

#include "Node.h"

Node::Node() {}

Node::Node(char* nStr) {
  strcpy(str, nStr);
  next = NULL;
}

Node::~Node() {
  str = NULL;	
  next = NULL;
}

char* Node::getStr() {
  return str;
}

void Node::setNext(Node* nNext) {
  next = nNext;
}

Node* Node::getNext() {
  return next;
}

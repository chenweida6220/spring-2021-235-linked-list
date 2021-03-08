#include <iostream>
using namespace std;

#include "DNode.h"

DNode::DNode() {
}

DNode::DNode(string data) {
  this->data = data;
}

DNode::DNode(string data, DNode *next, DNode *prev) {
  this->data = data;
  this->next = next;
  this->prev = prev;
}

DNode::~DNode() {
  data = "";
  delete next, prev;
  next = nullptr;
  prev = nullptr;
}

void DNode::setNext(DNode *next) {
  this->next = next;
}

void DNode::setPrev(DNode *prev) {
  this->prev = prev;
}

void DNode::setData(string data) {
  this->data = data;
}

DNode *DNode::getNext() {
  return next;
}

DNode *DNode::getPrev() {
  return prev;
}

string DNode::getData() {
  return data;
}

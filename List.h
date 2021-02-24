#pragma once
using namespace std;

#include "Node.h"

class List{
 private:
  Node *head;

 public:
  List();
  void insert(string data);
  void insert(int loc, string data);
  void remove(int loc);
  string get(int loc);
  ~List();
  string toString();
};

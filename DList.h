#pragma once
using namespace std;

#include "DNode.h"

class DList {
  private:
  	DNode *head;
  	DNode *tail;
  	DNode *cur;
  	int size;

  public:
  	DList();
    ~DList();
    string toString();
  	void insert(string data);
  	void insert(int loc, string data);
  	void remove(int loc);
  	string get(int loc);
};

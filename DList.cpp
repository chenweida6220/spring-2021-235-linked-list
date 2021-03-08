#include <iostream>
using namespace std;

#include "DList.h"

DList::DList() {
  size = 0;

  head = new DNode();
  head->setNext(tail);
  head->setPrev(nullptr);

  tail = new DNode();
  tail->setNext(nullptr);
	tail->setPrev(head);
}

DList::~DList() {
  head = head->getNext();
  while (head != nullptr) {
    DNode *walker = head;
    head = head->getNext();
    walker->~DNode();
  }
}

string DList::toString() {
  DNode *walker = head;
  string s = "";

  while (walker != nullptr){
    s = s + walker->getData() + "<-->";
    walker = walker->getNext();
  }

  s = "nullptr " + s + " nullptr";
  return s;
}

void DList::insert(string data) {
  // create a new node
  DNode *new_node = new DNode(data);

  // insert a new node at the beginning
  if (size == 0){
     head->setData(data);
     cur = head;
  }
  else {
     cur->setNext(new_node);
     cur->getNext()->setPrev(cur);
     cur = new_node;
     tail = new_node;
  }
  size++;
}

void DList::insert(int loc, string data) {
  DNode *n_node = new DNode(data);
	//if nothing is inserted
	if(loc == 0)
	{
		n_node->setNext(head);
		n_node->setPrev(nullptr);
		if(head != nullptr)
		{
			head->setPrev(n_node);
		}
		head = n_node;
		cur = n_node;
		size++;
	}

	else if(loc < 0 || loc > size)
	{
		cout << "Out of bound" << "\n";
	}

	else if(loc <= size/2)
	{
		//Dnode *first = head;
		cur = head;
		int j = 1;
		while(j != loc)
		{

			cur = cur->getNext();
			j++;
		}
			n_node->setNext(cur->getNext());
			cur->setNext(n_node);
			n_node->setPrev(cur);
			n_node->getNext()->setPrev(n_node);
			size++;
	}

	else if(loc >size/2 && loc < size)
	{
		int j = size-1;
		cur = tail;
		while(j != loc)
		{
			cur = cur->getPrev();
			j--;
		}

		n_node->setPrev(cur->getPrev());
		n_node->setNext(cur);
		cur->setPrev(n_node);
		n_node->getPrev()->setNext(n_node);
		size++;
	}

	else if(loc == size)
	{
		cur = tail;
		n_node->setNext(nullptr);
		cur->setNext(n_node);
		n_node->setPrev(cur);
		size++;
	}
}

void DList::remove(int loc) {
  // if out of bounds
  if (loc < 0 || loc > size) {
    cout << "Out of bound" << endl;
    return;
  }
  else if (loc == 0) {
    head = head->getNext();
    size--;
  }
  else if (loc == (size-1)){
    cur = tail;
    cur->setPrev(cur->getPrev()->getPrev());
    size--;
  }
  else if (loc <= size/2) {
    cur = head;
    int count = 1;

    while (count != loc) {
      if (cur->getNext()->getNext() == nullptr) {
        cout << "Out of bound" << endl;
        return;
      }

      cur = cur->getNext();
      count++;
    }

    cur->setNext(cur->getNext()->getNext());
    size--;
  }
  else if (loc > (size/2) && loc < size) {
    cur = tail;
    int count = size-1;

    while (count != loc) {
      if (cur->getPrev()->getPrev() == nullptr) {
        cout << "Out of bound" << endl;
        return;
      }

      cur = cur->getPrev();
      count--;
    }
    cur->getPrev()->setNext(cur->getNext());
    size--;
  }
}

string DList::get(int loc) {
  // if out of bounds
  if (loc < 0 || loc > size) {
    return "Out of bound";
  }
  else if (loc == 0) {
		cur = head;
		return cur->getData();
	}
  else if (loc <= (size/2)) {
    int count = 0;
    cur = head;
    while(count != loc) {
      cur = cur->getNext();
      count++;
    }
    return cur->getData();
  }
  else if (loc > (size/2)) {
    int count = size-1;
    cur = tail;
    while(count != loc){
      cur = cur->getPrev();
      count--;
    }
    return cur->getData();
  }

  return cur->getData();
}

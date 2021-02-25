#include <iostream>
using namespace std;
#include "List.h"


List::List(){
  head = nullptr;
}

void List::insert(string data){
  // create a new node
  Node *new_node = new Node(data);

  // insert the new node  
  new_node->setNext(head);
  head = new_node;
  }

void List::insert(int loc, string data) {
  Node *new_node = new Node(data);

  if (loc < 0) {
    cout << "Out of bound." << endl;
    return;
  }
  else if (loc == 0) {
    new_node->setNext(head);
    head = new_node;
  }
  else {
    Node *main = head;

    for (int i = 0; i < loc - 1; i++) {
      if (main->getNext() == nullptr) {
        cout << "Invalid index.";
        return;
      }
      main = main->getNext();
    }

    new_node->setNext(main->getNext());
    main->setNext(new_node);
  }
}

void List::remove(int loc) {
  if (loc < 0){
    cout << "Out of bound." << endl;
    return;
  }
  else if (loc == 0){
    head = head->getNext();
  }
  else {
    Node *main = head;
    int count = 0;

    while (count != loc - 1) {
	  if (main->getNext()->getNext() == nullptr) {
          cout << "Invalid index." << endl;
          return;
        }
         main = main->getNext();
         count++;
    }

    main->setNext(main->getNext()->getNext());
  }
}

string List::get(int loc) {
  if (loc < 0) {
    return "Out of bound.";
  }
  else {
    Node *main = head;

    for (int i = 0; i < loc - 1; i++) {
      if (main->getNext() == nullptr) {
        return "Invalid index.";
      }
      main = main->getNext();
    }

    return main->getData();
  }
}

List::~List() {
  Node *main = head;
  Node *temp = new Node();
  while (main != nullptr) {
    temp = main->getNext();
    delete main;
    main = temp;
  }
}


string List::toString(){
  Node *walker = head;
  string s = "";
  while (walker != nullptr){
    s = s + walker->getData() + "-->";
    walker = walker->getNext();

  }
  s=s+"nullptr";
  return s;
}

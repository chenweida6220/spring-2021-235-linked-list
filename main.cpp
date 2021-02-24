#include <iostream>
using namespace std;

#include "List.h"
int main(int argc, char *argv[]) {

  List *l1 = new List();
  cout << l1->toString() << "\n";

  cout << "----------------------------" << endl << endl;

  l1->insert("e");
  l1->insert("d");
  l1->insert("c");
  l1->insert("b");
  l1->insert("a");
  cout << l1->toString() << "\n";

  cout << "----------------------------" << endl << endl;

  l1->insert(2,"X");
  cout << l1->toString() << "\n";

  cout << "----------------------------" << endl << endl;

  l1->remove(2);
  cout << l1->toString() << "\n";

  cout << "----------------------------" << endl << endl;

  cout << l1->get(3) << "\n";

  cout << "----------------------------" << endl << endl;

  return 0;

}

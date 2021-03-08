#include <iostream>
using namespace std;

#include "List.h"
#include "DList.h"

int main(int argc, char *argv[]) {
  // PART 1
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

  cout << endl << "----------------------------" << endl;
  cout << "----------------------------" << endl;
  cout << "----------------------------" << endl << endl;

  // PART 2
  DList *l2 = new DList();
  cout << l2->toString() << "\n";

  cout << "----------------------------" << endl << endl;

  l2->insert("1");
  l2->insert("2");
  l2->insert("3");
  l2->insert("4");
  l2->insert("5");
  cout << l2->toString() << "\n";

  cout << "----------------------------" << endl << endl;

  l2->insert(4, "x");
  cout << l2->toString() << "\n";

  cout << "----------------------------" << endl << endl;

  l2->remove(1);
  cout << l2->toString() << "\n";

  cout << "----------------------------" << endl << endl;

  cout << l2->get(4) << "\n";

  return 0;

}

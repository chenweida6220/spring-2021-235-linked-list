#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "List.h"

List *temp = new List();

TEST_CASE("testing insert") {
  CHECK(temp->toString() == "nullptr");
  temp->insert("!");
  temp->insert("1");
  temp->insert("2");
  temp->insert("3");
  CHECK(temp->toString() == "3-->2-->1-->!-->nullptr");

  temp->insert(0, "0");
  temp->insert(3, "3");
  CHECK(temp->toString() == "0-->3-->2-->3-->1-->!-->nullptr");
}

TEST_CASE("testing remove") {
  temp->remove(0);
  temp->remove(1);
  temp->remove(2);
  CHECK(temp->toString() == "3-->3-->!-->nullptr");
}

TEST_CASE("testing get") {
    CHECK(temp->get(-1) == "Out of bound.");
    CHECK(temp->get(0) == "3");
    CHECK(temp->get(3) == "!");
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "list.h"
#include "olist.h"
#include "node.h"

TEST_CASE("constructor") {
    Olist *l = new Olist();
    CHECK(l->toString() == "nullptr");
}

TEST_CASE("destructor") {
    Olist *l = new Olist();
    l->insert("1");
    l->insert("2");
    l->insert("3");
    CHECK(l->length() == 3);
    l->destructor();
    CHECK(l->length() == 0);
}

TEST_CASE("insert") {
    Olist *l = new Olist();
    l->insert("5");
    CHECK(l->get(0) == "5");
    l->insert("10");
    CHECK(l->get(0) == "10");
    l->insert(1, "7");
    CHECK(l->get(1) == "7");
}

TEST_CASE("toString") {
    Olist *l = new Olist();
    l->insert("1");
    l->insert("2");
    l->insert("3");
    CHECK(l->toString() == "3-->2-->1-->nullptr");
}

TEST_CASE("contains") {
    Olist *l = new Olist();
    l->insert("1");
    l->insert("2");
    l->insert("3");
    CHECK(l->contains("2") == true);
    CHECK(l->contains("10") == false);
}

TEST_CASE("get") {
    Olist *l = new Olist();
    l->insert("10");
    l->insert("20");
    l->insert("30");
    CHECK(l->get(0) == "30");
    CHECK(l->get(2) == "10");
    CHECK(l->get(-2) == "Our insert is out of range");
    CHECK(l->get(10) == "Our insert is out of range");
}

TEST_CASE("remove") {
    Olist *l = new Olist();
    l->insert("10");
    l->insert("20");
    l->insert("30");
    l->remove(1);
    CHECK(l->get(0) == "30");
    CHECK(l->get(1) == "10");
}

TEST_CASE("reverse") {
    Olist *l = new Olist();
    l->insert("10");
    l->insert("20");
    l->insert("30");
    CHECK(l->get(0) == "30");
    CHECK(l->get(1) == "20");
    CHECK(l->get(2) == "10");
    l->reverse();
    CHECK(l->get(0) == "10");
    CHECK(l->get(1) == "20");
    CHECK(l->get(2) == "30");
}
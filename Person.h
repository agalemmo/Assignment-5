#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person
{
  private:
    string id;
    string name;
    string level;
  public:
    Person();
    Person(string iden, string nam, string lvl);
    ~Person();

    string getId();
    string getName();
    string getLevel();

    void setId(string n);
    void setName(string s);
    void setLevel(string s);

    //overloading operators

    void print();
};

Person::Person()
{
  id = "";
  name = "";
  level = "";
}

Person::Person(string iden, string nam, string lvl)
{
  id = iden;
  name = nam;
  level = lvl;
}

Person::~Person()
{}

string Person::getId()
{
  return id;
}

string Person::getName()
{
  return name;
}

string Person::getLevel()
{
  return level;
}

void Person::setId(string n)
{
  id = n;
}

void Person::setName(string s)
{
  name = s;
}

void Person::setLevel(string s)
{
  level = s;
}

void Person::print()
{
}

#endif

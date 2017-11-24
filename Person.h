#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person
{
  private:
    int id;
    string name;
    string level;
  public:
    Person();
    Person(int iden, string nam, string lvl);
    ~Person();

    int getId();
    string getName();
    string getLevel();

    void setId(int n);
    void setName(string s);
    void setLevel(string s);

    //overloading operators

    void print();
};

Person::Person()
{
  id = 0;
  name = "";
  level = "";
}

Person::Person(int iden, string nam, string lvl)
{
  id = iden;
  name = nam;
  level = lvl;
}

Person::~Person()
{}

int Person::getId()
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

void Person::setId(int n)
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

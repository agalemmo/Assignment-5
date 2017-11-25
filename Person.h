/**
Sarah Lasman and Amanda Galemmo
2278776          2270004
lasma101@mail.chapman.edu  galem100@mail.chapman.edu
CS 350 Section 3
Assignment #5
*/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

/**
A person class. Has the shared methods/member variables of Student and Faculty.
*/

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

/**
Default constructor.
*/
Person::Person()
{
  id = 0;
  name = "";
  level = "";
}

/**
Overloaded constructor.
Takes in ID, name, and level.
*/
Person::Person(int iden, string nam, string lvl)
{
  id = iden;
  name = nam;
  level = lvl;
}

/**
Destructor.
Does nothing.
*/
Person::~Person()
{}

/**
getID returns ID.
*/
int Person::getId()
{
  return id;
}

/**
getName returns name.
*/
string Person::getName()
{
  return name;
}

/**
getLevel returns level.
*/
string Person::getLevel()
{
  return level;
}

/**
setID sets ID to parameter int.
*/
void Person::setId(int n)
{
  id = n;
}

/**
setName sets name to parameter string.
*/
void Person::setName(string s)
{
  name = s;
}

/**
setLevel sets level to parameter string.
*/
void Person::setLevel(string s)
{
  level = s;
}

/**
Print
To be overridden in sub-classes.
*/
void Person::print()
{
}

#endif

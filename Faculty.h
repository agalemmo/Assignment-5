/**
  @TODO
    all that array business
**/

#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"

class Faculty : public Person
{
  private:
    string dept;
    Person base;
    string advArray[10];
    int numAdvisees;
    int arraySize;
    string* array;

  public:
    Faculty();
    Faculty(string id, string name, string level, string dpt);
    ~Faculty();

    string getDept();
    string* getAdvisees();

    void setDept(string s);
    void addAdvisee(string s);

    //bool advFull();

    string returnArray();
    void print();
};

Faculty::Faculty() : Person()
{
  dept = "";
  numAdvisees = 0;
  arraySize = 10;
  array = advArray;
}

Faculty::Faculty(string id, string name, string level, string dpt) : Person(id, name, level) //add advisees?
{
  dept = dpt;
}


Faculty::~Faculty()
{
}

string Faculty::getDept()
{
  return dept;
}

string* Faculty::getAdvisees()
{
  return advArray;
}

void Faculty::setDept(string s)
{
  dept = s;
}

void Faculty::addAdvisee(string s)
{
  if (numAdvisees < arraySize)
  {
    advArray[numAdvisees] = s;
    numAdvisees++;
  }
  else
  {
    string newArray[arraySize*2];
    for (int i = 0; i < arraySize; ++i)
      newArray[i] = advArray[i];
    arraySize = arraySize *2;
    array = newArray;
    delete [] advArray;
    string advArray[arraySize];
    for (int i = 0; i < arraySize; ++i)
      advArray[i] = newArray[i];
    array = advArray;
    delete [] newArray;
    advArray[numAdvisees] = s;
    numAdvisees++;
  }
}

string Faculty::returnArray()
{
  string adviseeString = "";
  for (int i = 0; i < arraySize; ++i) //@TODO - un-hardcode this
  {
    adviseeString += advArray[i];
    adviseeString += "\n";
  }
  return adviseeString;
}

bool operator==(Faculty& x, Faculty& y)
{
  return x.getId() == y.getId()
      && x.getName() == y.getName()
      && x.getLevel() == y.getLevel()
      && x.getDept() == y.getDept();
      //&& x.getAdvisor() == y.getAdvisor(); advisee bs
}

bool operator < (Faculty& x, Faculty& y)
{
  return x.getId() < y.getId();
}

bool operator > (Faculty& x, Faculty& y)
{
  return x.getId() > y.getId();
}

void Faculty::print()
{
  cout << "FACULTY ID: " << getId() << endl;
  cout << "FACULTY NAME: " << getName() << endl;
  cout << "FACULTY DEPARTMENT: " << dept << endl;
  cout << "FACULTY TITLE: " << getLevel() << endl;
  //cout << "FACULTY ADVISEES: "<< returnArray() << endl; //probably a print function for the array itself. not bad. printAdv()?
}

#endif

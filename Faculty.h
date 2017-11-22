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

  public:
    Faculty();
    Faculty(string id, string name, string level, string dpt);
    ~Faculty();

    string getDept();
    //void getAdvisees();

    void setDept(string s);
    void addAdvisee(string s);

    string returnArray();
    void print();
};

Faculty::Faculty() : Person()
{
  dept = "";
  //advArray = new string[10];
}

Faculty::Faculty(string id, string name, string level, string dpt) : Person(id, name, level)
{
  dept = dpt;
  //advArray = new string[10];
}


Faculty::~Faculty()
{
}

string Faculty::getDept()
{
  return dept;
}

/*string* Faculty::getAdvisees()
{
  return advArray;
}*/

void Faculty::setDept(string s)
{
  dept = s;
}

void Faculty::addAdvisee(string s)
{
  //add advisee to array
}

string Faculty::returnArray()
{
  string adviseeString = "";
  for (int i = 0; i < 10; ++i) //@TODO - un-hardcode this
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
  cout << "FACULTY ADVISEES: "<< returnArray() << endl; //probably a print function for the array itself. not bad. printAdv()?
}

#endif

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
    int advArray[10];
    int numAdvisees;
    int arraySize;
    int* array;

  public:
    Faculty();
    Faculty(int id, string name, string level, string dpt);
    ~Faculty();

    string getDept();
    int* getAdvisees();

    void setDept(string s);
    void addAdvisee(int s);
    void removeAdvisee(int s);

    //bool advFull();

    string returnArray();
    void print();
    string printToFile();
};

Faculty::Faculty() : Person()
{
  dept = "";
  numAdvisees = 0;
  arraySize = 10;
  array = advArray;
}

Faculty::Faculty(int id, string name, string level, string dpt) : Person(id, name, level) //add advisees?
{
  dept = dpt;
  numAdvisees = 0;
  arraySize = 10;
  array = advArray;
}


Faculty::~Faculty()
{
}

string Faculty::getDept()
{
  return dept;
}

int* Faculty::getAdvisees()
{
  return array;
}

void Faculty::setDept(string s)
{
  dept = s;
}

void Faculty::addAdvisee(int s)
{
  if (numAdvisees < arraySize)
  {
    advArray[numAdvisees] = s;
    numAdvisees++;
    cout << numAdvisees << "He has an advisee, computer.\n";
  }
  else
  {
    int *newArray = new int[arraySize*2];
    for (int i = 0; i < arraySize; ++i)
      newArray[i] = advArray[i];
    arraySize = arraySize *2;
    array = newArray;
    int *advArray = new int[arraySize];
    for (int i = 0; i < arraySize; ++i)
      advArray[i] = newArray[i];
    array = advArray;
    delete [] newArray;
    advArray[numAdvisees] = s;
    numAdvisees++;
  }
}

void Faculty::removeAdvisee(int s)
{
  if (numAdvisees >= 0)
  {
    for (int i = arraySize - 1; i > 0; --i)
    {
      if (array[i] == s)
      {
        for (int n = i; n < arraySize; ++n)
        {
          if (n == (arraySize - 1))
            array[n] = 0;
          else
            array[n] = array[n+1];
        }
        numAdvisees--;
        cout << "Student " << s << " removed." << endl;
      }
      else if (i == arraySize - 1 && array[i] != s)
        cout << "Student " << s << " not found." << endl;
    }
  }
  else
    cout << "Action invalid. No advisees found." << endl;
}

string Faculty::returnArray()
{
  cout << "ReturnArray called. The prof has this many advisees: " << numAdvisees << "\n";
  string adviseeString = "";
  for (int i = 0; i < numAdvisees; ++i)
  {
    adviseeString += advArray[i];
    adviseeString += "\n";
  }
  cout << adviseeString;
  return adviseeString;
}

bool operator==(Faculty& x, Faculty& y)
{
  return x.getId() == y.getId()
      && x.getName() == y.getName()
      && x.getLevel() == y.getLevel()
      && x.getDept() == y.getDept()
      && x.getAdvisees() == y.getAdvisees();
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
  cout << "FACULTY DEPARTMENT: " << getDept() << endl;
  cout << "FACULTY TITLE: " << getLevel() << endl;
  cout << "FACULTY ADVISEES: "<< returnArray() << endl;
}

string Faculty::printToFile()
{
  string returnString = "";
  returnString += "BEGIN NODE\n";
  returnString += getId();
  returnString += "\n";
  returnString += getName();
  returnString += "\n";
  returnString += getDept();
  returnString += "\n";
  returnString += getLevel();
  returnString += "\n";
  returnString += returnArray();
  returnString += "\n";
  returnString += "END NODE\n";
  return returnString;
}

#endif

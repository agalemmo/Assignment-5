#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"


class Faculty : public Person
{
  private:
    string dept;
    Person base;
    int advArray[10];
    int arraySize;
    int numAdvisees;
//  int* array;

  public:

    Faculty();
    Faculty(int id, string name, string level, string dpt);
    ~Faculty();

    string getDept();
    int* getAdvisees();

    void setDept(string s);
    void addAdvisee(int s);
    void removeAdvisee(int s);
    int getNumAdvisees();
    void setNumAdvisees(int n);

    //bool advFull();

    string returnArray();
    void print();
    string printToFile();
};

/**
Default constructor.
Inherits from parent and assigns default arraySize to 10.
*/
Faculty::Faculty() : Person()
{
  cout << "Constructor called for Faculty number " << getId() << endl;
  dept = "";
  numAdvisees = 0;
  cout << "numAdvisees set to 0\n";
  arraySize = 10;
  for (int i = 0; i < 10; ++i)
  {
    advArray[i] = 0;
  }
//  array = advArray;
}

/**
Overloaded constructor.
Inherits from parents and assigns member variables to parameters.
*/
Faculty::Faculty(int id, string name, string level, string dpt) : Person(id, name, level) //add advisees?
{
  cout << "Overloaded constructor.\n";
  dept = dpt;
  numAdvisees = 0;
  arraySize = 10;
  for (int i = 0; i < 10; ++i)
  {
    advArray[i] = 0;
  }
//  array = advArray;
}

/**
Destructor.
Does nothing.
*/
Faculty::~Faculty()
{
}

/**
getDept returns department.
*/
string Faculty::getDept()
{
  return dept;
}

/**
getAdvisor returns a pointer to int array of advisees.
*/
int* Faculty::getAdvisees()
{
  return advArray;
}

/**
setDept sets department to parameter.
*/
void Faculty::setDept(string s)
{
  dept = s;
}

<<<<<<< HEAD
=======
/**
getNumAdvisees gets number of advisees this faculty member has.
*/
>>>>>>> c5e3770da027bd6f8595089e1bc6d5e219326686
int Faculty::getNumAdvisees()
{
  return numAdvisees;
}

<<<<<<< HEAD
=======
/**
setNumAdvisees sets number of advisees to parameter.
*/
>>>>>>> c5e3770da027bd6f8595089e1bc6d5e219326686
void Faculty::setNumAdvisees(int n)
{
  numAdvisees = n;
}

<<<<<<< HEAD
=======
/**
addAdvisee
Adds a student to list of advisees. Increments numAdvisees.
If necessary, increases array size.
Parameter s - ID number of student to be added.
*/
>>>>>>> c5e3770da027bd6f8595089e1bc6d5e219326686
void Faculty::addAdvisee(int s)
{
  if (numAdvisees < arraySize)
  {
    advArray[numAdvisees] = s;
    numAdvisees++;
    cout << to_string(getNumAdvisees()) << endl;
  }
  else
  {
    int *newArray = new int[arraySize*2];
    for (int i = 0; i < arraySize; ++i)
      newArray[i] = advArray[i];
    arraySize = arraySize *2;
    // array = newArray;
    int *advArray = new int[arraySize];
    for (int i = 0; i < arraySize; ++i)
      advArray[i] = newArray[i];
//    array = advArray;
    delete [] newArray;
    advArray[numAdvisees] = s;
    numAdvisees++;
  }
}

/**
removeAdvisee
Removes advisee with ID number given by parameter.
Paramter s - ID number of student to be removed.
*/
void Faculty::removeAdvisee(int s)
{
  if (numAdvisees >= 0)
  {
    for (int i = arraySize - 1; i > 0; --i)
    {
      if (advArray[i] == s)
      {
        for (int n = i; n < arraySize; ++n)
        {
          if (n == (arraySize - 1))
            advArray[n] = 0;
          else
            advArray[n] = advArray[n+1];
        }
        numAdvisees--;
        cout << "Student " << s << " removed." << endl;
      }
      else if (i == arraySize - 1 && advArray[i] != s)
        cout << "Student " << s << " not found." << endl;
    }
  }
  else
    cout << "Action invalid. No advisees found." << endl;
}

/**
returnArray
Creates and returns a string containing the data of all of this faculty's advisees.
*/
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

/**
Overloaded equality operator.
Returns true if all properties are equal.
*/
bool operator==(Faculty& x, Faculty& y)
{
  return x.getId() == y.getId()
      && x.getName() == y.getName()
      && x.getLevel() == y.getLevel()
      && x.getDept() == y.getDept()
      && x.getAdvisees() == y.getAdvisees();
}

/**
Overloaded less than operator.
Returns true if the first faculty's ID is less than the second faculty member's.
*/
bool operator < (Faculty& x, Faculty& y)
{
  return x.getId() < y.getId();
}

/**
Overloaded greater than operator.
Returns true if the first faculty's ID is greater than the second faculty member's.
*/
bool operator > (Faculty& x, Faculty& y)
{
  return x.getId() > y.getId();
}

/**
print outputs Faculty's data to screen.
*/
void Faculty::print()
{
  cout << "FACULTY ID: " << getId() << endl;
  cout << "FACULTY NAME: " << getName() << endl;
  cout << "FACULTY DEPARTMENT: " << getDept() << endl;
  cout << "FACULTY TITLE: " << getLevel() << endl;
  cout << "FACULTY ADVISEES: "<< returnArray() << endl;
}

/**
printToFile creates and returns string of Faculty's data.
Does not actually print to file, but the resulting string can be printed to file.
*/
string Faculty::printToFile()
{
  string returnString = "";
  returnString += "BEGIN NODE\n";
  returnString += to_string(getId());
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

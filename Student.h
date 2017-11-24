#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

using namespace std;

/**
A student class.
Students have a name, level, ID, major, GPA, and advisor.
*/
class Student : public Person
{
  private:
    string major;
    double gpa;
    int advisor;

  public:
    Student();
    Student(int ident, string nam, string lvl, string maj, double grade, int adv);
    ~Student();

    string getMajor();
    double getGpa();
    int getAdvisor();

    void setMajor(string s);
    void setGPA(double d);
    void setAdvisor(int s);

    void print();
    void printToFile();
};

/**
Default constructor inherits from Person's constructor.
*/
Student::Student() : Person()
{
  major = "";
  gpa = 0;
  advisor = 0;
}

/**
Overloaded constructor sets major, GPA, and advisor, in addition to inheriting from Person.
*/
Student::Student(int ident, string nam, string lvl, string maj, double grade, int adv) : Person(ident, nam, lvl)
{
  major = maj;
  gpa = grade;
  advisor = adv;
}

/**
Destructor does nothing.
*/
Student::~Student()
{

}

/**
getMajor returns major.
*/
string Student::getMajor()
{
  return major;
}

/**
getGpa returns GPA.
*/
double Student::getGpa()
{
  return gpa;
}

/**
getAdvisor returns advisor.
*/
int Student::getAdvisor()
{
  return advisor;
}

void Student::setMajor(string s)
{
  major = s;
}

void Student::setGPA(double d)
{
  gpa = d;
}

void Student::setAdvisor(int s)
{
  advisor = s;
}

/**
Overloaded equality operator.
Returns true if all elements of the students are equal.
*/
bool operator==(Student& x, Student& y)
{
  return x.getId() == y.getId()
      && x.getName() == y.getName()
      && x.getLevel() == y.getLevel()
      && x.getMajor() == y.getMajor()
      && x.getGpa() == y.getGpa()
      && x.getAdvisor() == y.getAdvisor();
}

/**
Overloaded less than operator.
Returns true if the first student's ID is less than the second student's.
*/
bool operator < (Student& x, Student& y)
{
  return x.getId() < y.getId();
}

/**
Overloaded greater than operator.
Returns true if the first student's ID is greater than the second student's.
*/
bool operator > (Student& x, Student& y)
{
  return x.getId() > y.getId();
}

/**
print prints student's data to cout.
*/
void Student::print()
{
  cout << "STUDENT ID: " << Person::getId() << endl;
  cout << "STUDENT NAME: " << Person::getName() << endl;
  cout << "STUDENT LEVEL: " << Person::getLevel() << endl;
  cout << "STUDENT MAJOR: " << major << endl;
  cout << "STUDENT GPA: " << gpa << endl;
  cout << "STUDENT'S ADVISOR: " << advisor << endl;
}

/**
printToFile prints student's data to file, to be used when loading database.
*/
void Student::printToFile()
{
  cout << "BEGIN NODE" << endl;       //0
  cout << getId() << endl;            //1
  cout << getName() << endl;          //2
  cout << getLevel() << endl;         //3
  cout << getMajor() << endl;         //4
  cout << getGpa() << endl;           //5
  cout << getAdvisor() << endl;       //6
  cout << "END NODE" << endl;         //7
}

#endif

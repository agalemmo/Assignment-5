#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

using namespace std;

class Student : public Person
{
  private:
    string major;
    double gpa;
    string advisor;

  public:
    Student();
    Student(string ident, string nam, string lvl, string maj, double grade, string adv);
    ~Student();

    string getMajor();
    double getGpa();
    string getAdvisor();

    void setMajor(string s);
    void setGPA(double d);
    void setAdvisor(string s);

    void print();
    void printToFile();
};

Student::Student() : Person()
{
  major = "";
  gpa = 0;
  advisor = "";
}

Student::Student(string ident, string nam, string lvl, string maj, double grade, string adv) : Person(ident, nam, lvl)
{
  major = maj;
  gpa = grade;
  advisor = adv;
}

Student::~Student()
{

}

string Student::getMajor()
{
  return major;
}

double Student::getGpa()
{
  return gpa;
}

string Student::getAdvisor()
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

void Student::setAdvisor(string s)
{
  advisor = s;
}

bool operator==(Student& x, Student& y)
{
  return x.getId() == y.getId()
      && x.getName() == y.getName()
      && x.getLevel() == y.getLevel()
      && x.getMajor() == y.getMajor()
      && x.getGpa() == y.getGpa()
      && x.getAdvisor() == y.getAdvisor();
}

bool operator < (Student& x, Student& y)
{
  return x.getId() < y.getId();
}

bool operator > (Student& x, Student& y)
{
  return x.getId() > y.getId();
}

void Student::print()
{
  cout << "STUDENT ID: " << Person::getId() << endl;
  cout << "STUDENT NAME: " << Person::getName() << endl;
  cout << "STUDENT LEVEL: " << Person::getLevel() << endl;
  cout << "STUDENT MAJOR: " << major << endl;
  cout << "STUDENT GPA: " << gpa << endl;
  cout << "STUDENT'S ADVISOR: " << advisor << endl;
}

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

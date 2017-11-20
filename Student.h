#include "Person.h"

using namespace std;

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
    void setAdvisor(int n);

    void print();
};

Student::Student() : Person()
{
  major = "";
  gpa = 0;
  advisor = 0;
}

Student::Student(int ident, string nam, string lvl, string maj, double grade, int adv) : Person(ident, nam, lvl)
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

void Student::setAdvisor(int n)
{
  advisor = n;
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

#include "Person.h"

using namespace std;

class Student
{
  private:
    int id;
    string name;
    string level;
    string major;
    double gpa;
    int advisor;
    
  public:
    Student();
    Student(int ident, string nam, string lvl, string maj, double grade, int adv);
    ~Student();

    int getId();
    string getName();
    string getLevel();
    string getMajor();
    double getGpa();
    int getAdvisor();

    void setId(int n);
    void setName(string s);
    void setLevel(string s);
    void setMajor(string s);
    void setGPA(double d);
    void setAdvisor(int n);

    void print();
};

Student::Student()
{
  id = 0;
  name = "";
  level = "";
  major = "";
  gpa = 0;
  advisor = 0;
}

Student::Student(int ident, string nam, string lvl, string maj, double grade, int adv)
{
  id = ident;
  name = nam;
  level = lvl;
  major = maj;
  gpa = grade;
  advisor = adv;
}

Student::~Student()
{

}

int Student::getId()
{
  return id;
}

string Student::getName()
{
  return name;
}

string Student::getLevel()
{
  return level;
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

void Student::setId(int n)
{
  id = n;
}

void Student::setName(string s)
{
  name = s;
}

void Student::setLevel(string s)
{
  level = s;
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
  cout << "STUDENT ID: " << id << endl;
  cout << "STUDENT NAME: " << name << endl;
  cout << "STUDENT LEVEL: " << level << endl;
  cout << "STUDENT MAJOR: " << major << endl;
  cout << "STUDENT GPA: " << gpa << endl;
  cout << "STUDENT'S ADVISOR: " << advisor << endl;
}

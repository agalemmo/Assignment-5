#include "Person.h"

class Faculty : public Person
{
  private:
    string dept;
    int advisee;
    Person base;
    int advArray[10];

  public:
    Faculty();
    Faculty(int id, string name, string level, string dpt);
    ~Faculty();

    string getDept();
    void getAdvisees();

    void setDept(string s);
    void addAdvisee(int n);

    string returnArray();
    void print();
};

Faculty::Faculty() : Person()
{
  dept = "";
  int advArray[10];
  advisee = advArray[0];
}

Faculty::Faculty(int id, string name, string level, string dpt) : Person(id, name, level)
{
  dept = dpt;
  int advArray[10];
  advisee = advArray[0];
}


Faculty::~Faculty()
{
}

string Faculty::getDept()
{
  return dept;
}

void Faculty::getAdvisees()
{
  //return
}

/** @TODO
Is setLevel needed for faculty?
*/
// void Faculty::setLevel(string s)
// {
//   level = s;
// }

void Faculty::setDept(string s)
{
  dept = s;
}

void Faculty::addAdvisee(int n)
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

void Faculty::print()
{
  cout << "FACULTY ID: " << getId() << endl;
  cout << "FACULTY NAME: " << getName() << endl;
  cout << "FACULTY DEPARTMENT: " << dept << endl;
  //cout << "FACULTY TITLE: " << title << endl; @TODO ??? what do you mean by this
  cout << "FACULTY ADVISEES: "<< returnArray() << endl; //probably a print function for the array itself. not bad. printAdv()?
}

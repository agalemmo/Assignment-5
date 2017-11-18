#include "Person.h"

class Faculty : public Person
{
  private:
    Person p;
    string dept;
    int advisee;
    Person base;
    int advArray[10];

  public:
    Faculty();
    Faculty(Person psn, string dpt);
    Faculty(int ident, string nam, string lvl, string dpt);
    ~Faculty();

    string getDept();
    void getAdvisees();

    void setDept(string s);
    void addAdvisee(int n);

    string returnArray();
    void print();
};

Faculty::Faculty()
{
  p = *new Person();
  dept = "";
  //int advArray[10];
  //advisee = advArray[0];
}

Faculty::Faculty(Person psn, string dpt)
{
  p = psn;
  dept = dpt;
}

Faculty::Faculty(int ident, string nam, string lvl, string dpt)//rework this
{
  p = *new Person();
  p.setId(ident);
  p.setName(nam);
  p.setLevel(lvl);
  dept = dpt;
  advisee = advArray[0];//djfdskfj this seems wrong
}

Faculty::~Faculty()
{
  delete &p;
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

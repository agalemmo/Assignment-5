#include "Person.h"

class Faculty
{
  private:
    Person* p;
    string dept;
    int[]* advisee;
    Person* base;

  public:
    Faculty();
    Faculty(Person* psn, string dpt);
    Faculty(int ident, string nam, string lvl, string dpt);
    ~Faculty();

    string getDept();
    void getAdvisees();

    void setDept(string s);
    void addAdvisee(int n);

    void printArray();
    void print();
};

Faculty::Faculty()
{
  p = new Person();
  dept = "";
  //int advArray[10];
  //advisee = advArray[0];
}

Faculty::Faculty(Person* psn, string dpt)
{
  p = &psn;
  dept = dpt;
}

Faculty::Faculty(int ident, string nam, string lvl, string dpt)//rework this
{
  p = new Person();
  p.setId(ident);
  p.setName(nam);
  p.setLevel(lvl);
  dept = dpt;
  int advArray[10];
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

void Faculty::setLevel(string s)
{
  level = s;
}

void Faculty::setDept(string s)
{
  dept = s;
}

void Faculty::addAdvisee(int n)
{
  //add advisee to array
}

void Faculty::printArray()
{
  for (int i = 0; i < advNum; ++i)
  {
    cout << p[i].getId() << endl;
  }
}

void Faculty::print()
{
  cout << "FACULTY ID: " << id << endl;
  cout << "FACULTY NAME: " << name << endl;
  cout << "FACULTY DEPARTMENT: " << dept << endl;
  cout << "FACULTY TITLE: " << title << endl;
  cout << "FACULTY ADVISEES: "<< printArray() << endl; //probably a print function for the array itself. not bad. printAdv()?
}

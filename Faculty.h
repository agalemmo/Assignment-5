#include <iostream>;

using namespace std;

class Faculty
{
  private:
    int id;
    string name;
    string level;
    string dept;
    int[]* advisee;

  public:
    Faculty();
    Faculty(int ident, string nam, string lvl, string dpt, int advNum);
    Faculty(int ident, string nam, string lvl, string dpt, int[]* adv); //not sure about the pointer array thing
    ~Faculty();

    int getId();
    string getName();
    string getLevel();
    string getDept();
    void getAdvisees();

    void setId(int n);
    void setName(string s);
    void setLevel(string s);
    void setDept(string s);
    void addAdvisee(int n);

    void print();
};

Faculty::Faculty()
{
  id = 0;
  name = "";
  level = "";
  dept = "";
  int advArray[10];
  advisee = advArray[0];
}

Faculty::Faculty(int ident, string nam, string lvl, string dpt)
{
  id = ident;
  name = nam;
  level = lvl;
  dept = dpt;
  int advArray[10];
  advisee = advArray[0];//djfdskfj this seems wrong
}

Faculty::Faculty(int ident, string nam, string lvl, string dpt, int[]* adv)
{
  id = ident;
  name = nam;
  level = lvl;
  dept = dpt;
  advisee = adv[0];//djfdskfj this seems wrong
}
Faculty::~Faculty()
{

}

int Faculty::getId()
{
  return id;
}

string Faculty::getName()
{
  return name;
}

string Faculty::getLevel()
{
  return level;
}

string Faculty::getDept()
{
  return dept;
}

void Faculty::getAdvisees()
{
  return
}

void Faculty::setId(int n)
{
  id = n;
}

void Faculty::setName(string s)
{
  name = s;
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

void Faculty::print()
{
  
}

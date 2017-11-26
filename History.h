#include <iostream>

using namespace std;

class History
{
  private:
    string st0, st1, st2, st3, st4;
    string ft0, ft1, ft2, ft3, ft4;

    int count;

  public:
    History();
    ~History();

    void addHistory(string stud, string fac);

    string getStudHist();
    string getFacHist();
};

History::History()
{
  count = 0;
}

History::~History()
{
}

void History::addHistory(string stud, string fac)
{
  if (count == 0)
  {
    st0 = stud;
    ft0 = fac;
    count++;
    cout << st0;
    cout << ft0;
  }
  else if (count == 1)
  {
    st1 = stud;
    ft1 = fac;
    count++;
    cout << st1;
    cout << ft1;
  }
  else if (count == 2)
  {
    st2 = stud;
    ft2 = fac;
    count++;
    cout << st2;
    cout << ft2;
  }
  else if (count == 3)
  {
    st3 = stud;
    ft3 = fac;
    count++;
    cout << st3;
    cout << ft3;
  }
  else if (count == 4)
  {
    st4 = stud;
    ft4 = fac;
    count++;
  }
  else if (count == 5)
  {
    st0 = st1;
    st1 = st2;
    st2 = st3;
    st3 = st4;
    st4 = stud;
    ft0 = ft1;
    ft1 = ft2;
    ft2 = ft3;
    ft3 = ft4;
    ft4 = fac;
  }
  cout << "Last instances of masterStudent and masterFaculty added to rollback" << endl;
}

string History::getStudHist()
{
  if (count == 1)
  {
    count--;
    cout << st0;
    return st0;
  }
  else if (count == 2)
  {
    count--;
    cout << st1;
    return st1;
  }
  else if (count == 3)
  {
    count--;
    cout << st2;
    return st2;
  }
  else if (count == 4)
  {
    count--;
    cout << st3;
    return st3;
  }
  else if (count == 5)
  {
    count--;
    return st4;
  }
  else
    return "";
}

string History::getFacHist()
{
  if (count == 1)
  {
    count--;
    return ft0;
  }
  else if (count == 2)
  {
    count--;
    return ft1;
  }
  else if (count == 3)
  {
    count--;
    return ft2;
  }
  else if (count == 4)
  {
    count--;
    return ft3;
  }
  else if (count == 5)
  {
    count--;
    return ft4;
  }
  else
    return "";
}

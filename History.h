#include <iostream>

using namespace std;

class History
{
  private:
    StudentTree st0, st1, st2, st3, st4, tempST;
    FacultyTree ft0, ft1, ft2, ft3, ft4, tempFT;

    int count;

  public:
    History();
    ~History();

    void addHistory(StudentTree stud, FacultyTree fac);

    StudentTree getStudHist();
    FacultyTree getFacHist();
};

History::History()
{
  count = 0;
}

History::~History()
{
}

void History::addHistory(StudentTree stud, FacultyTree fac)
{
  if (count == 0)
  {
    st0 = stud;
    ft0 = fac;
    count++;
  }
  else if (count == 1)
  {
    st1 = stud;
    ft1 = fac;
    count++;
  }
  else if (count == 2)
  {
    st2 = stud;
    ft2 = fac;
    count++;
  }
  else if (count == 3)
  {
    st3 = stud;
    ft3 = fac;
    count++;
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

StudentTree History::getStudHist()
{
  if (count == 1)
  {
    count--;
    return st0;
  }
  else if (count == 2)
  {
    count--;
    return st1;
  }
  else if (count == 3)
  {
    count--;
    return st2;
  }
  else if (count == 4)
  {
    count--;
    return st3;
  }
  else if (count == 5)
  {
    count--;
    return st4;
  }
  else
    return st4;
}

FacultyTree History::getFacHist()
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
    return ft4;
}

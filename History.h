#include <iostream>
#include "DoubleListNode.h"

using namespace std;

class History
{
  private:
    //DoublyLinkedList<StudentTree> *studHist;
    //DoublyLinkedList<FacultyTree> *facHist;
    //DoublyLinkedList<StudentTree, FacultyTree>* hist;

    StudentTree st0;
    StudentTree st1;
    StudentTree st2;
    StudentTree st3;
    StudentTree st4;

    FacultyTree ft0;
    FacultyTree ft1;
    FacultyTree ft2;
    FacultyTree ft3;
    FacultyTree ft4;

    int sCount;
    int fCount;

  public:
    History();
    ~History();

    void addHistory(StudentTree stud);
    void addHistory(FacultyTree fac);

    StudentTree getStudHist();
    FacultyTree getFacHist();
};

History::History()
{
  sCount = 0;
  fCount = 0;
  //studHist = new DoublyLinkedList<StudentTree>();
  //facHist = new DoublyLinkedList<FacultyTree>();

  //hist = new DoublyLinkedList<StudentTree, FacultyTree>();
}

History::~History()
{
  //delete studHist;
  //delete facHist;
  //delete hist;
}

void History::addHistory(StudentTree stud)
{
  if (sCount == 0)
  {
    st0 = stud;
    sCount++;
  }
  else if (sCount == 1)
  {
    st1 = stud;
    sCount++;
  }
  else if (sCount == 2)
  {
    st2 = stud;
    sCount++;
  }
  else if (sCount == 3)
  {
    st3 = stud;
    sCount++;
  }
  else if (sCount == 4)
  {
    st4 = stud;
    sCount++;
  }
  else if (sCount == 5)
  {
    st0 = st1;
    st1 = st2;
    st2 = st3;
    st3 = st4;
    st4 = stud;
  }
  /*if (studHist->getSize() == 5)
    studHist->removeBack();
  studHist->insertFront(*stud);*/
}

void History::addHistory(FacultyTree fac)
{
  if (fCount == 0)
  {
    ft0 = fac;
    fCount++;
  }
  else if (fCount == 1)
  {
    ft1 = fac;
    fCount++;
  }
  else if (fCount == 2)
  {
    ft2 = fac;
    fCount++;
  }
  else if (fCount == 3)
  {
    ft3 = fac;
    fCount++;
  }
  else if (fCount == 4)
  {
    ft4 = fac;
    fCount++;
  }
  else if (fCount == 5)
  {
    ft0 = ft1;
    ft1 = ft2;
    ft2 = ft3;
    ft3 = ft4;
    ft4 = fac;
  }
}

StudentTree History::getStudHist()
{
  if (sCount == 1)
  {
    sCount--;
    return st0;
  }
  else if (sCount == 2)
  {
    sCount--;
    return st1;
  }
  else if (sCount == 3)
  {
    sCount--;
    return st2;
  }
  else if (sCount == 4)
  {
    sCount--;
    return st3;
  }
  else if (sCount == 5)
  {
    sCount--;
    return st4;
  }
  else
    return st4;
  /*if (studHist->front == NULL)
  {
    cerr << "No history." << endl;
    return StudentTree();
  }
  else
  {
    StudentTree s;
    s = studHist->front->data;
    studHist->removeFront();
    return s;
  }*/
}

FacultyTree History::getFacHist()
{
  if (fCount == 1)
  {
    fCount--;
    return ft0;
  }
  else if (fCount == 2)
  {
    fCount--;
    return ft1;
  }
  else if (fCount == 3)
  {
    fCount--;
    return ft2;
  }
  else if (fCount == 4)
  {
    fCount--;
    return ft3;
  }
  else if (fCount == 5)
  {
    fCount--;
    return ft4;
  }
  else
    return ft4;
}

#include <iostream>
#include "DoubleListNode.h"

using namespace std;

class History
{
  private:
    DoublyLinkedList<StudentTree> *studHist;
    DoublyLinkedList<FacultyTree> *facHist;
    //DoublyLinkedList<StudentTree, FacultyTree>* hist;
  public:
    History();
    ~History();

    void addHistory(StudentTree* stud);
    void addHistory(FacultyTree* fac);

    StudentTree getStudHist();
    FacultyTree getFacHist();
};

History::History()
{
  studHist = new DoublyLinkedList<StudentTree>();
  facHist = new DoublyLinkedList<FacultyTree>();

  //hist = new DoublyLinkedList<StudentTree, FacultyTree>();
}

History::~History()
{
  delete studHist;
  delete facHist;
  //delete hist;
}

void History::addHistory(StudentTree* stud)
{
  if (studHist->getSize() == 5)
    studHist->removeBack();
  studHist->insertFront(&stud);
}

void History::addHistory(FacultyTree* fac)
{
  if (facHist->getSize() == 5)
    facHist->removeBack();
  facHist->insertFront(&fac);
}

StudentTree History::getStudHist()
{
  if (studHist->front == NULL)
    cout << "No history." << endl;
  else
  {
    StudentTree s;
    s = studHist->front->data;
    studHist->removeFront();
    return s;
  }
}

FacultyTree History::getFacHist()
{
  if (facHist->front == NULL)
    cout << "No history." << endl;
  else
  {
    FacultyTree f;
    f = facHist->front->data;
    facHist->removeFront();
    return f;
  }
}

#include <iostream>
#include "DoubleListNode.h"

using namespace std;

class History
{
  private:
    DoublyLinkedList<StudentTree> studHist*;
    DoublyLinkedList<FacultyTree> facHist*;

    StudentTree* s;
    FacultyTree* f;
  public:
    History();
    ~History();

    void addStudHistory(StudentTree* stud);
    void addFacHistory();

    StudentTree* getLastStud();
    FacultyTree* getLastFac();
};

History::History()
{
  studHist = new DoublyLinkedList<StudentTree>();
  facHist = new DoublyLinkedList<FacultyTree>();
}

History::~History()
{
  delete studHist;
  delete facHist;
  delete s;
  delete f;
}

void History::addStudHistory(StudentTree* stud)
{
  if (studHist->getSize() == 5)
    studHist->removeBack();
  studHist->insertFront(stud);
}

StudentTree* History::getLastStud();
{
  if (studHist->front == NULL)
    cout << "No history." << endl;
  else
  {
    s = studHist->front;
    studHist->removeFront();
    return s;
  }
}

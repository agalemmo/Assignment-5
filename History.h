#include <iostream>
#include "DoubleListNode.h"

using namespace std;

class History
{
  private:
    DoublyLinkedList<StudentTree, FacultyTree>* hist;
  public:
    History();
    ~History();

    void addHistory(StudentTree* stud);
    void addHistory(FacultyTree* fac);

    StudentTree* getHist();
    FacultyTree* getHist();
};

History::History()
{
  hist = new DoublyLinkedList<StudentTree, FacultyTree>();
}

History::~History()
{
  delete hist;
}

void History::addHistory(StudentTree* stud)
{
  if (hist->getSize() == 5)
    hist->removeBack();
  hist->insertFront(stud);
}

void History::addHistory(FacultyTree* fac)
{
  if (hist->getSize() == 5)
    hist->removeBack();
  hist->insertFront(fac);
}

StudentTree* History::getHist();
{
  if (hist->front == NULL)
    cout << "No history." << endl;
  else
  {
    StudentTree* s = hist->front;
    hist->removeFront();
    return s;
  }
}

FacultyTree* History::getHist();
{
  if (hist->front == NULL)
    cout << "No history." << endl;
  else
  {
    FacultyTree* f = hist->front;
    hist->removeFront();
    return f;
  }
}

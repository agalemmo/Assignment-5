//@TODO: Fix the dumb seg fault with insertion

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

    void addHistory(StudentTree stud);
    void addHistory(FacultyTree fac);

    StudentTree getStudHist();
    FacultyTree getFacHist();
};

/*
  Constructor for the History class
*/
History::History()
{
  studHist = new DoublyLinkedList<StudentTree>();
  facHist = new DoublyLinkedList<FacultyTree>();

}

/*
  Destructor for the history class
*/
History::~History()
{
  delete studHist;
  delete facHist;
  //delete hist;
}

/*
  Adds a node to the student history list
*/
void History::addHistory(StudentTree stud)
{
  cout << "line 39 add student history" << endl;
  if (studHist->getSize() == 5)
  {
    cout << "student history if check" << endl;
    studHist->removeBack();
    cout << "student history back removed" << endl;
  }
  cout << "student history less than 5" << endl;
  studHist->insertFront(stud); //@TODO it gets to the end of the insert front function?
  cout << "front inserted" << endl; //@TODO now it doesn't get here for some reason??
  // cout << "size before" << studHist->getSize() << endl;
  // if (studHist->getSize() == 5)
  //   studHist->removeBack();
  // studHist->insertFront(*stud);
  // cout << "size after" << studHist->getSize() << endl;
}

/*
  Adds a node to the faculty history list
*/
void History::addHistory(FacultyTree fac)
{
  if (facHist->getSize() == 5)
    facHist->removeBack();
  facHist->insertFront(fac); //@TODO: ditto
  // cout << "size before" << facHist->getSize() << endl;
  // if (facHist->getSize() == 5)
  //   facHist->removeBack();
  // facHist->insertFront(*fac);
  // cout << "size after" << facHist->getSize() << endl;
}

/*
  returns the most recent instance of StudentTree
*/
StudentTree History::getStudHist()
{
  if (studHist->front == NULL)
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
  }
}

/*
  returns the most recent instance of FacultyTree
*/
FacultyTree History::getFacHist()
{
  if (facHist->front == NULL)
  {
    cerr << "No history." << endl;
    return FacultyTree();
  }
  else
  {
    FacultyTree f;
    f = facHist->front->data;
    facHist->removeFront();
    return f;
  }
}

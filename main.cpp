/**
  @TODO
**/

#include "Student.h"
#include "StudentTree.h"
#include "FacultyTree.h"
#include "History.h"

int main()
{
  StudentTree* students = new StudentTree();
  FacultyTree* faculty = new FacultyTree();

  StudentTree* st;
  FacultyTree* ft;

  int option;
  string idToBeFound;
  string info;
  string facID;
  string studID;
  double d;

  History* hist = new History();

  Student* s = new Student();
  Faculty* f = new Faculty();

  switch(option)
  {
    case 1: //print all students
      students->printTree(students->root);
      break;
    case 2: //print all Faculty
      faculty->printTree(faculty->root);
      break;
    case 3: //find student given id
      cout << "Enter the ID number.\n";
      cin >> idToBeFound;
      cout << students->getNode(idToBeFound) << endl;
      break;
    case 4: //find faculty member given id
      cout << "Enter the ID Number." << endl;
      cin >> idToBeFound;
      cout << faculty->getNode(idToBeFound) << endl;
      break;
    case 5: //with id of student print info of faculty ADVISOR
      cout << "Enter the ID Number." << endl;
      cin >> idToBeFound;
      cout << faculty->getNode(students->getNode(idToBeFound)->getObj().getAdvisor()) << endl;
      break;
    case 6: //with id of faculty print names and id of adviseeString
      cout << "Enter the ID Number." << endl;
      cin >> idToBeFound;
      cout << faculty->getNode(idToBeFound)->getObj().returnArray() << endl;
      break;
    case 7: //add a new student to StudentTree
      hist->addHistory(students);
      hist->addHistory(faculty);
      cout << "Enter student information: " << endl;
      cout << "NAME: ";
      cin >> info;
      s->setName(info);
      cout << "\nID: ";
      cin >> info;
      s->setId(info);
      cout << "\nYEAR: ";
      cin >> info;
      s->setLevel(info);
      cout << "\nMAJOR: ";
      cin >> info;
      s->setMajor(info);
      cout << "\nGPA: ";
      cin >> d;
      s->setGPA(d);
      cout << "\nADVISOR: ";
      cin >> info;
      s->setAdvisor(info);
      //students->insert(s->getId(), &s); //trouble with pointers come back to this
      cout << "\n New student object created and inserted into tree." << endl;
      break;
    case 8: //remove student from StudentTree
      hist->addHistory(students);
      hist->addHistory(faculty);
      cout << "Enter the ID Number: " << endl;
      cin >> idToBeFound;
      students->deleteNode(idToBeFound);
      break;
    case 9: //add a new faculty member to FacultyTree
      hist->addHistory(students);
      hist->addHistory(faculty);
      //initialize based on 7
      break;
    case 10: //remove faculty from FacultyTree
      hist->addHistory(students);
      hist->addHistory(faculty);
      cout << "Enter the ID Number: " << endl;
      cin >> idToBeFound;
      faculty->deleteNode(idToBeFound);
      break;
    case 11: //change student's advisor
      hist->addHistory(students);
      hist->addHistory(faculty);
      cout << "Enter the Student's ID Number: " << endl;
      cin >> studID;
      cout << "Enter the Faculty Member's ID Number: " << endl;
      cin >> facID;
      if (faculty->contains(facID))
      {
        students->getNode(studID)->getObj().setAdvisor(facID);
        cout << "Student " << studID << "'s advisor successfully changed to " << facID << "." << endl;
      }
      else
        cout << "Faculty member " << facID << " not found." << endl;
      break;
    case 12: //remove advisee from faculty member
      hist->addHistory(students);
      hist->addHistory(faculty);
      cout << "Enter the Faculty Member's ID Number: " << endl;
      cin >> facID;
      cout << "Enter the Student's ID Number: " << endl;
      cin >> studID;
      faculty->getNode(facID)->getObj().removeAdvisee(studID);
      break;
    case 13: //rollback
      st = hist->getStudHist();
      students = &st;
      ft = hist->getFacHist();
      faculty = &ft;
      cout << "Last version restored." << endl;
      break;
    case 14: //exit
      cout << "Goodbye." << endl;
      return 0;
      break;


  }
}

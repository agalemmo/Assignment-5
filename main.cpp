/**
  @TODO
**/

#include "Student.h"
#include "StudentTree.h"
#include "FacultyTree.h"
//#include "History.h"
#include <fstream>

int main()
{
  string line;
  ifstream studFile;
  ifstream facfile;
  ofstream studentTable;
  ofstream facultyTable;

  studFile.open("Assignment-5\\studentTable.txt");
  if (studFile.is_open())
  {
    
  }

  StudentTree* masterStudent = new StudentTree();
  FacultyTree* masterFaculty = new FacultyTree();

  int option;
  string idToBeFound;
  string info;
  string facID;
  string studID;
  double d;

  //History* hist = new History();

  Student* s = new Student();
  Faculty* f = new Faculty();

  switch(option)
  {
    case 1: //print all masterStudent
      masterStudent->printTree(masterStudent->root);
      break;
    case 2: //print all masterFaculty
      masterFaculty->printTree(masterFaculty->root);
      break;
    case 3: //find student given id
      cout << "Enter the ID number.\n";
      cin >> idToBeFound;
      cout << masterStudent->getNode(idToBeFound) << endl;
      break;
    case 4: //find faculty member given id
      cout << "Enter the ID Number." << endl;
      cin >> idToBeFound;
      cout << masterFaculty->getNode(idToBeFound) << endl;
      break;
    case 5: //with id of student print info of faculty ADVISOR
      cout << "Enter the ID Number." << endl;
      cin >> idToBeFound;
      cout << masterFaculty->getNode(masterStudent->getNode(idToBeFound)->getObj().getAdvisor()) << endl;
      break;
    case 6: //with id of faculty print names and id of adviseeString
      cout << "Enter the ID Number." << endl;
      cin >> idToBeFound;
      cout << masterFaculty->getNode(idToBeFound)->getObj().returnArray() << endl;
      break;
    case 7: //add a new student to StudentTree
      //hist->addHistory(masterStudent);
      //hist->addHistory(masterFaculty);
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
      //masterStudent->insert(s->getId(), &s); //trouble with pointers come back to this
      cout << "\n New student object created and inserted into tree." << endl;
      break;
    case 8: //remove student from StudentTree
      //hist->addHistory(masterStudent);
      //hist->addHistory(masterFaculty);
      cout << "Enter the ID Number: " << endl;
      cin >> idToBeFound;
      masterStudent->deleteNode(idToBeFound);
      break;
    case 9: //add a new faculty member to FacultyTree
      //hist->addHistory(masterStudent);
      //hist->addHistory(masterFaculty);
      //initialize based on 7
      break;
    case 10: //remove faculty from FacultyTree
      //hist->addHistory(masterStudent);
      //hist->addHistory(masterFaculty);
      cout << "Enter the ID Number: " << endl;
      cin >> idToBeFound;
      masterFaculty->deleteNode(idToBeFound);
      break;
    case 11: //change student's advisor
      //hist->addHistory(masterStudent);
      //hist->addHistory(masterFaculty);
      cout << "Enter the Student's ID Number: " << endl;
      cin >> studID;
      cout << "Enter the Faculty Member's ID Number: " << endl;
      cin >> facID;
      if (masterFaculty->contains(facID))
      {
        masterStudent->getNode(studID)->getObj().setAdvisor(facID);
        cout << "Student " << studID << "'s advisor successfully changed to " << facID << "." << endl;
      }
      else
        cout << "Faculty member " << facID << " not found." << endl;
      break;
    case 12: //remove advisee from faculty member
      //hist->addHistory(masterStudent);
      //hist->addHistory(masterFaculty);
      cout << "Enter the Faculty Member's ID Number: " << endl;
      cin >> facID;
      cout << "Enter the Student's ID Number: " << endl;
      cin >> studID;
      masterFaculty->getNode(facID)->getObj().removeAdvisee(studID);
      break;
    case 13: //rollback
      /*st = hist->getStudHist();
      masterStudent = &st;
      ft = hist->getFacHist();
      masterFaculty = &ft;
      cout << "Last version restored." << endl;*/
      break;
    case 14: //exit
      cout << "Goodbye." << endl;
      return 0;
      break;


  }
}

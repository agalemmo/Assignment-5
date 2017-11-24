/**
  @TODO
**/

#include "Student.h"
#include "StudentTree.h"
#include "FacultyTree.h"
//#include "History.h"
#include <fstream>
#include <string>

using namespace std;

int main()
{
  string line;
  ifstream studFile;
  ifstream facfile;
  ofstream studentTable ("studentTable.txt");
  ofstream facultyTable ("facultyTable.txt");

  StudentTree* masterStudent = new StudentTree();
  FacultyTree* masterFaculty = new FacultyTree();

  int option;
  string idToBeFound;
  string info;
  string facID;
  string studID;
  double d;

  int lineCount;

  //History* hist = new History();

  /*studFile.open("Assignment-5\\studentTable.txt");
  if (studFile.is_open())
  {
    while ( getLine (studFile, line))
    {
      if (line == "BEGIN NODE")
      {
        Student* s = new Student();
        lineCount == 0;
      }
      if (lineCount == 1)
        s->setId(line);
      if (lineCount == 2)
        s->setName(line);
      if (lineCount == 3)
        s->setLevel(line);
      if (lineCount == 4)
        s->setMajor(line);
      if (lineCount == 5)
        s->setGPA((double)line);
      if (lineCount == 6)
        s->setAdvisor(line);
      if (line == "END NODE")
      {
        masterStudent->insert(s->getId(), s);
        delete s;
      }
      lineCount++;
    }
    studFile.close();
  }

  facFile.open("Assignment-5\\facultyTable.txt");
  if (facfile.is_open())
  {
    while ( getLine (facfile, line))
    {
      if (line == "BEGIN NODE")
      {
        Faculty* f = new Faculty();
        lineCount = 0;
      }
      if (lineCount == 1)
        f->setId(line);
      if (lineCount == 2)
        f->setName(line);
      if (lineCount == 3)
        f->setDept(line);
      if (lineCount == 4)
        f->setLevel(line);
      if (lineCount >= 5)
        f->addAdvisee(line);
      if (line == "END NODE")
      {
        masterFaculty->insert(f->getId(), f);
        delete f;
      }
      lineCount++;
    }
    facfile.close();
  }*/
  while (true)
  {
    cout << "DATABASE MENU: " << endl;
    cout << "[1] Print all students and their information (sorted by ascending id #)" << endl;
    cout << "[2] Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "[3] Find and display all student information given the student's ID" << endl;
    cout << "[4] Find and display all faculty information given the faculty member's ID" << endl;
    cout << "[5] Given a student's ID print the name and info of their faculty advisor" << endl;
    cout << "[6] Given a faculty ID, print ALL the names and info of their advisees" << endl;
    cout << "[7] Add a new student" << endl;
    cout << "[8] Delete a student given the ID" << endl;
    cout << "[9] Add a new faculty member" << endl;
    cout << "[10] Delete a faculty member given the ID" << endl;
    cout << "[11] Change a student's advisor given the student ID and the new faculty ID" << endl;
    cout << "[12] Remove an advisee from a faculty member given the ID" << endl;
    cout << "[13] Rollback" << endl;
    cout << "[14] Exit." << endl;
    cin >> option;

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
        /*if (studentTable.is_open())
        {
          studentTable << masterStudent->printTreeToFile(masterStudent->root);
          studentTable.close();
        }
        if (facultyTable.is_open())
        {
          facultyTable << masterFaculty->printTreeToFile(masterFaculty->root);
          facultyTable.close();
        }*/
        cout << "Saved to studentTable.txt and facultyTable.txt. Goodbye." << endl;
        return 0;
        break;
    }
  }
}

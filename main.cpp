/**
  @TODO
    FUNCTIONS TO BE ADDED:
      - Fix write/restore from file
      - Should be randomly generating our own ID, not prompting
      - Rollback/history
      - Exception handling for case 11 and 12.
    BUGS:
      - Print all students only works once (also with faculty) TEMP FIX
      - Advisors recognize that they have advisees when students added, but don't remember that later on. WHY???
**/

#include "Student.h"
#include "StudentTree.h"
#include "FacultyTree.h"
#include "History.h"
#include <fstream>
#include <string>
#include <limits>

using namespace std;

void printOptions()
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
}


int main()
{
  string line;
  ifstream studFile;
  ifstream facFile;
  ofstream studentTable ("studentTable.txt");
  ofstream facultyTable ("facultyTable.txt");

  StudentTree* masterStudent = new StudentTree();
  FacultyTree* masterFaculty = new FacultyTree();

  int option;
  int idToBeFound;
  string info;
  int facID;
  int studID;
  double d;
  Student* s;
  Faculty* f;
  TreeNode<Student>* ts;
  TreeNode<Faculty>* tf;
  StudentTree st;
  FacultyTree ft;

  int lineCount;

  History* hist = new History();

  studFile.open("Assignment-5\\studentTable.txt");
  if (studFile.is_open())
  {
    while ( getline (studFile, line))
    {
      if (line == "BEGIN NODE")
      {
        Student* s = new Student();
        lineCount = 0;
      }
      if (lineCount == 1)
        s->setId(stoi(line));
      if (lineCount == 2)
        s->setName(line);
      if (lineCount == 3)
        s->setLevel(line);
      if (lineCount == 4)
        s->setMajor(line);
      if (lineCount == 5)
        s->setGPA(stoi(line));
      if (lineCount == 6)
        s->setAdvisor(stoi(line));
      if (line == "END NODE")
      {
        masterStudent->insert(s->getId(), *s);
        delete s;
      }
      lineCount++;
    }
    studFile.close();
  }

  facFile.open("Assignment-5\\facultyTable.txt");
  if (facFile.is_open())
  {
    Faculty* f = new Faculty();
    while ( getline (facFile, line))
    {
      if (line == "BEGIN NODE")
      {
        lineCount = 0;
      }
      if (lineCount == 1)
        f->setId(stoi(line));
      if (lineCount == 2)
        f->setName(line);
      if (lineCount == 3)
        f->setDept(line);
      if (lineCount == 4)
        f->setLevel(line);
      if (lineCount >= 5)
        f->addAdvisee(stoi(line));
      if (line == "END NODE")
      {
        masterFaculty->insert(f->getId(), *f);
        delete f;
      }
      lineCount++;
    }
    facFile.close();
  }
  while (true)
  {
    printOptions();
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
        cin >> (idToBeFound);
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
          cin >> facID;
        }
        ts = (masterStudent->getNode(idToBeFound));
        if (ts)
        {
          ts->getObj().print();
        }
        else
          cerr << "No student exists with that ID number. Please try again.\n";
        break;
      case 4: //find faculty member given id
        cout << "Enter the ID Number." << endl;
        cin >> (idToBeFound);
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
          cin >> facID;
        }
        tf = masterFaculty->getNode(idToBeFound);
        if (tf)
          tf->getObj().print();
        else
          cerr << "No faculty exists with that ID number. Please try again.\n";
        break;
      case 5: //with id of student print info of faculty ADVISOR
        cout << "Enter the ID Number." << endl;
        cin >> (idToBeFound);
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
          cin >> facID;
        }
        ts = (masterStudent->getNode(idToBeFound));
        if (ts)
        {
          masterFaculty->getNode(ts->getObj().getAdvisor())->getObj().print();
        }
        else
          cerr << "No student exists with that ID number. Please try again.\n";
        break;
      case 6: //with id of faculty print names and id of adviseeString
        cout << "Enter the ID Number." << endl;
        cin >> (idToBeFound);
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
          cin >> facID;
        }
        tf = masterFaculty->getNode(idToBeFound);
        if (tf)
          cout << tf->getObj().returnArray() << endl;
        else
          cerr << "No faculty exists with that ID number. Please try again.\n";
        break;
      case 7: //add a new student to StudentTree
        hist->addHistory(masterStudent);
        hist->addHistory(masterFaculty);
        if (masterFaculty->isEmpty())
        {
          cerr << "Your faculty tree is empty. You can't add a student until you have at least one faculty member, or your student can't have an advisor.\n";
          continue;
        }
        s = new Student();
        cout << "Enter student information: " << endl;
        cout << "NAME: ";
        cin >> info;
        s->setName(info);
        cout << "\nID: ";
        cin >> studID;
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
          cin >> facID;
        }
        s->setId(studID);
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
        cin >> facID;
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
          cin >> facID;
        }
        if (masterFaculty->contains(facID))
        {
          s->setAdvisor(facID);
          masterFaculty->getNode(facID)->getObj().addAdvisee(studID);
        }
        else
        {
          cerr << "This advisor does not exist. Please try creating the student again, with a valid advisor ID.\n";
          continue;
        }
        masterStudent->insert(s->getId(), *s);
        cout << "\n New student object created and inserted into tree." << endl;
        break;
      case 8: //remove student from StudentTree
        hist->addHistory(masterStudent);
        hist->addHistory(masterFaculty);
        cout << "Enter the ID Number: " << endl;
        cin >> (idToBeFound);
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
          cin >> facID;
        }
        if (!masterStudent->deleteNode(idToBeFound))
          cerr << "This student does not exist, and therefore could not be removed.\n";
        break;
      case 9: //add a new faculty member to FacultyTree
        hist->addHistory(masterStudent);
        hist->addHistory(masterFaculty);
        f = new Faculty();
        cout << "Enter faculty information: " << endl;
        cout << "NAME: ";
        cin >> info;
        f->setName(info);
        cout << "\nID: ";
        cin >> facID;
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
          cin >> facID;
        }
        f->setId(facID);
        cout << "\nLEVEL: ";
        cin >> info;
        f->setLevel(info);
        cout << "\nDEPARTMENT: ";
        cin >> info;
        f->setDept(info);
        masterFaculty->insert(f->getId(), *f);
        cout << "\n New faculty object created and inserted into tree." << endl;
        break;
      case 10: //remove faculty from FacultyTree
        hist->addHistory(masterStudent);
        hist->addHistory(masterFaculty);
        cout << "Enter the ID Number: " << endl;
        cin >> idToBeFound;
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
          cin >> facID;
        }
        if (!masterFaculty->getNode(idToBeFound)->left && !masterFaculty->getNode(idToBeFound)->right && !masterStudent->isEmpty())
        {
          cerr << "You are trying to delete the only faculty member listed. This will leave several students without an advisor, so you can not do this until there are more faculty.\n";
        }
        if (!masterFaculty->deleteNode(idToBeFound))
          cerr << "This faculty member does not exist, and therefore could not be removed.\n";
        break;
      case 11: //change student's advisor
        hist->addHistory(masterStudent);
        hist->addHistory(masterFaculty);
        cout << "Enter the Student's ID Number: " << endl;
        cin >> studID;
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
          cin >> facID;
        }
        cout << "Enter the Faculty Member's ID Number: " << endl;
        cin >> facID;
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
          cin >> facID;
        }
        if (masterFaculty->contains(facID))
        {
          masterStudent->getNode(studID)->getObj().setAdvisor(facID);
          cout << "Student " << studID << "'s advisor successfully changed to " << facID << "." << endl;
        }
        else
          cout << "Faculty member " << facID << " not found." << endl;
        break;
      case 12: //remove advisee from faculty member
        hist->addHistory(masterStudent);
        hist->addHistory(masterFaculty);
        cout << "Enter the Faculty Member's ID Number: " << endl;
        cin >> facID;
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
          cin >> facID;
        }
        cout << "Enter the Student's ID Number: " << endl;
        cin >> studID;
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
          cin >> facID;
        }
        if (masterFaculty->contains(facID))
        {
          masterFaculty->getNode(facID)->getObj().removeAdvisee(studID);
          cout << "Student " << studID << " successfully removed." << endl;
        }
        else
          cout << "Student " << studID << " not found." << endl;
        break;
      case 13: //rollback
        st = hist->getStudHist();
        masterStudent = &st;
        ft = hist->getFacHist();
        masterFaculty = &ft;
        cout << "Last version restored." << endl;
        break;
      case 14: //exit
        if (studentTable.is_open())
        {
          studentTable << masterStudent->printTreeToFile(masterStudent->root);
          studentTable.close();
        }
        if (facultyTable.is_open())
        {
          facultyTable << masterFaculty->printTreeToFile(masterFaculty->root);
          facultyTable.close();
        }
        cout << "Saved to studentTable.txt and facultyTable.txt. Goodbye." << endl;
        return 0;
        break;
    }
  }
}

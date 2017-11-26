/**
Sarah Lasman and Amanda Galemmo
2278776          2270004
lasma101@mail.chapman.edu  galem100@mail.chapman.edu
CS 350 Section 3
Assignment #5
*/

#include "Student.h"
#include "StudentTree.h"
#include "FacultyTree.h"
#include "History.h"
#include <fstream>
#include <string>
#include <limits>

using namespace std;

/**
printOptions prints the database MENU
*/
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
  cout << "[14] Change a student's major" << endl;
  cout << "[15] Exit" << endl;
}

/**
generateStudID generates an ID for a student between 1000 and 4999.
*/
int generateStudID(StudentTree* masterStudent)
{
  while (true)
  {
    int num = rand() % 4000 + 1000;
    if (masterStudent->contains(num))
      continue;
    else return num;
  }
}

/**
generateFacID generates an ID for the faculty between 5000 and 8999.
*/
int generateFacID(FacultyTree* masterFaculty)
{
  while (true)
  {
    int num = rand() % 4000 + 5000;
    if (masterFaculty->contains(num))
      continue;
    else return num;
  }
}

/**
main does most of the work. sorry.
*/
int main()
{
  string line;
  ifstream studFile;
  ifstream facFile;
  ofstream studentTable;
  ofstream facultyTable;

  StudentTree* masterStudent = new StudentTree();
  FacultyTree* masterFaculty = new FacultyTree();

  /**
  Temporary variables used in the gathering of info in the below switch statement.
  */
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
  int* tempArray;
  Faculty fac;
  Student stud;

  int lineCount;

  History* hist = new History();

  /**
  Create/access and restore facultyTable text file.
  */
  facFile.open("facultyTable.txt", fstream::in);
  while (facFile.is_open())
  {
    f = new Faculty();
    lineCount = 0;
    while (getline (facFile, line))
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
      if (line == "END NODE")
      {
        masterFaculty->insert(f->getId(), *f);
        cout << to_string(f->getId());
      }
      lineCount++;
    }
    facFile.close();
  }

  /**
  Create/access and restore studentTable text file.
  */
  studFile.open("studentTable.txt", fstream::in);
  while (studFile.is_open())
  {
      s = new Student();
      lineCount = 0;
      while ( getline (studFile, line))
      {
        if (line == "BEGIN NODE")
        {
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
        {
          s->setAdvisor(stoi(line));
          fac = masterFaculty->getNode(stoi(line))->getObj();
          fac.addAdvisee(s->getId());
          masterFaculty->getNode(stoi(line))->setObj(fac);
        }
        if (line == "END NODE")
        {
          masterStudent->insert(s->getId(), *s);
        }
        lineCount++;
    }
    break;
    studFile.close();
  }


  while (true)
  {
    printOptions();
    cin >> option;
    while (cin.fail())
    {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cerr << "That's not a valid option, I'm afraid. Please try again.\n";
      cin >> facID;
    }
    /**
    The big switch statement.
    Each case corresponds with the action on the printout.
    */
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
        {
          for (int i = 0; i < tf->getObj().getNumAdvisees(); ++i)
          {
            stud = masterStudent->getNode(tf->getObj().getAdvisees()[i])->getObj();
            stud.print();
            cout << endl;
          }
        }
        else
          cerr << "No faculty exists with that ID number. Please try again.\n";
        break;
      case 7: //add a new student to StudentTree
        if (masterFaculty->isEmpty())
        {
          cerr << "Your faculty tree is empty. You can't add a student until you have at least one faculty member, or your student can't have an advisor.\n";
          continue;
        }
        s = new Student();
        cout << "Enter student information: " << endl;
        getline(cin, info);
        cout << "NAME: ";
        getline(cin, info);
        s->setName(info);
        studID = generateStudID(masterStudent);
        s->setId(studID);
        cout << "YEAR: ";
        getline(cin, info);
        s->setLevel(info);
        cout << "MAJOR: ";
        getline(cin, info);
        s->setMajor(info);
        cout << "GPA: ";
        cin >> d;
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. GPA should be an double.\n";
          cin >> d;
        }
        s->setGPA(d);
        cout << "ADVISOR: ";
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
          fac = (Faculty)masterFaculty->getNode(facID)->getObj();
          fac.addAdvisee(studID);
          masterFaculty->getNode(facID)->setObj(fac);
        }
        else
        {
          cerr << "This advisor does not exist. Please try creating the student again, with a valid advisor ID.\n";
          continue;
        }
        masterStudent->insert(s->getId(), *s);
        cout << "New student object created and inserted into tree." << endl;
        hist->addHistory(*masterStudent, *masterFaculty);
        break;
      case 8: //remove student from StudentTree
        cout << "Enter the ID Number: " << endl;
        cin >> (studID);
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
          cin >> studID;
        }
        if (!masterStudent->contains(studID))
          cerr << "This student does not exist, and therefore could not be removed.\n";
        else
        {
          cout << "This student has been successfully deleted.\n";
          facID = masterStudent->getNode(studID)->getObj().getAdvisor();
          fac = masterFaculty->getNode(facID)->getObj();
          fac.removeAdvisee(studID);
          masterFaculty->getNode(facID)->setObj(fac);
          masterStudent->deleteNode(studID);
          hist->addHistory(*masterStudent, *masterFaculty);
        }
        break;
      case 9: //add a new faculty member to FacultyTree
        cout << "added faculty history" << endl;
        f = new Faculty();
        cout << "Enter faculty information: " << endl;
        getline(cin, info);
        cout << "NAME: ";
        getline(cin, info);
        f->setName(info);
        facID = generateFacID(masterFaculty);
        f->setId(facID);
        cout << "LEVEL: ";
        getline(cin, info);
        f->setLevel(info);
        cout << "DEPARTMENT: ";
        getline(cin, info);
        f->setDept(info);
        masterFaculty->insert(f->getId(), *f);
        cout << "New faculty object created and inserted into tree." << endl;
        hist->addHistory(*masterStudent, *masterFaculty);
        break;
      case 10: //remove faculty from FacultyTree
        cout << "Enter the ID Number: " << endl;
        cin >> facID;
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
          cin >> facID;
        }
        if (!masterFaculty->getNode(facID)->left && !masterFaculty->getNode(facID)->right && !masterStudent->isEmpty())
        {
          cerr << "You are trying to delete the only faculty member listed. This will leave several students without an advisor, so you can not do this until there are more faculty.\n";
          break;
        }
        if (!masterFaculty->contains(facID))
          cerr << "This faculty member does not exist, and therefore could not be removed.\n";
        else
        {
          *f = masterFaculty->getNode(facID)->getObj();
          tempArray = f->getAdvisees();
          masterFaculty->deleteNode(facID);
          for (int i = 0; i < f->getNumAdvisees(); ++i)
          {
            stud = masterStudent->getNode(tempArray[i])->getObj();
            stud.setAdvisor(masterFaculty->getMin()->getObj().getId());
            masterStudent->getNode(tempArray[i])->setObj(stud);
            fac = masterFaculty->getMin()->getObj();
            fac.addAdvisee(tempArray[i]);
            masterFaculty->getMin()->setObj(fac);
          }
          cout << "Faculty member deleted. His advisees have been reassigned to the faculty with the lowest ID.\n";
          hist->addHistory(*masterStudent, *masterFaculty);
        }
        break;
      case 11: //change student's advisor
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
          if (masterStudent->contains(studID))
          {
            masterStudent->getNode(studID)->getObj().setAdvisor(facID);
            cout << "Student " << studID << "'s advisor successfully changed to " << facID << "." << endl;
            hist->addHistory(*masterStudent, *masterFaculty);
          }
          else
          {
            cout << "Student " << studID << " not found.";
          }
        }
        else
          cout << "Faculty member " << facID << " not found." << endl;
        break;
      case 12: //remove advisee from faculty member
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
          if (masterStudent->contains(studID))
          {
            fac = masterFaculty->getNode(facID)->getObj();
            fac.removeAdvisee(studID);
            masterFaculty->getNode(facID)->setObj(fac);
            cout << "Student " << studID << " successfully removed." << endl;
            hist->addHistory(*masterStudent, *masterFaculty);
          }
          else
          {
            cout << "Student " << studID << " not found.\n";
          }
        }
        else
          cout << "Faculty " << facID << " not found." << endl;
        break;
      case 13: //rollback
        cout << "\n+++Student before" << endl;
        masterStudent->printTree(masterStudent->root);
        cout << "\n+++Faculty before" << endl;
        masterFaculty->printTree(masterFaculty->root);
        st = hist->getStudHist();
        masterStudent = &st;
        cout << "\n+++Student after" << endl;
        masterStudent->printTree(masterStudent->root);
        ft = hist->getFacHist();
        masterFaculty = &ft;
        cout << "\n+++Faculty after" << endl;
        masterFaculty->printTree(masterFaculty->root);
        cout << "Last version restored." << endl;
        break;
      case 14: //change major
        cout << "Enter the student's ID number:\n";
        cin >> studID;
        while (cin.fail())
        {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
          cin >> facID;
        }
        if (masterStudent->contains(studID))
        {
          stud = masterStudent->getNode(studID)->getObj();
          cout << "This student's major is " << stud.getMajor() << ". What would you like to change it to?\n";
          getline(cin, info);
          getline(cin, info);
          stud.setMajor(info);
          masterStudent->getNode(studID)->setObj(stud);
          cout << "Student's major has been changed.\n";
        }
        else
        {
          cout << "Student " << studID << " not found.\n";
        }
        break;
      case 15: //exit
        studentTable.open("studentTable.txt", fstream::in | fstream::out | fstream::trunc);
        facultyTable.open("facultyTable.txt", fstream::in | fstream::out | fstream::trunc);
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
      default:
        cout << "That's not a valid choice, I'm afraid. Please try again.\n";
        break;
    }
  }
}

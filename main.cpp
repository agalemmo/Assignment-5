/**
  @TODO
    FUNCTIONS TO BE ADDED:
      - Rollback/history
    BUGS:
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
  cout << "[14] Exit." << endl;
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

int main()
{
  string line;
  ifstream studFile;
  ifstream facFile;
  fstream studentTable ("studentTable.txt");
  fstream facultyTable ("facultyTable.txt");

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
  int* tempArray;

  int lineCount;

  History* hist = new History();

  facFile.open("facultyTable.txt");
  if (facFile.is_open())
  {
    f = new Faculty();
    while ( getline (facFile, line))
    {
      if (line == "BEGIN NODE")
      {
        s = new Student();
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
        delete f;
      }
      lineCount++;
    }
    facFile.close();
  }

  studFile.open("studentTable.txt");
  if (studFile.is_open())
  {
    while ( getline (studFile, line))
    {
      if (line == "BEGIN NODE")
      {
        s = new Student();
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
        masterFaculty->getNode(stoi(line))->getObj().addAdvisee(s->getId());
      }
      if (line == "END NODE")
      {
        masterStudent->insert(s->getId(), *s);
        delete s;
      }
      else if (lineCount >= 5)
      {
        try
        {
          f->addAdvisee(stoi(line));
        }
        catch (exception)
        {
          continue;
        }
      }
      lineCount++;
    }
    studFile.close();
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
        hist->addHistory(*masterStudent);
        hist->addHistory(*masterFaculty);
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
        // cout << "\nID: ";
        // cin >> studID;
        // while (cin.fail())
        // {
        //   cin.clear();
        //   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //   cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
        //   cin >> facID;
        // }
        studID = generateStudID(masterStudent);
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
          cout << "1. " << to_string(masterFaculty->getNode(facID)->getObj().getNumAdvisees()) << endl;
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
        hist->addHistory(*masterStudent);
        hist->addHistory(*masterFaculty);
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
        hist->addHistory(*masterStudent);
        hist->addHistory(*masterFaculty);
        cout << "added faculty history" << endl;
        f = new Faculty();
        cout << "Enter faculty information: " << endl;
        cout << "NAME: ";
        cin >> info;
        f->setName(info);
        // cout << "\nID: ";
        // cin >> facID;
        // while (cin.fail())
        // {
        //   cin.clear();
        //   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //   cerr << "Data is formatted improperly. Please try again. ID should be an int.\n";
        //   cin >> facID;
        // }
        facID = generateFacID(masterFaculty);
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
        hist->addHistory(*masterStudent);
        hist->addHistory(*masterFaculty);
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
        if (!masterFaculty->deleteNode(facID))
          cerr << "This faculty member does not exist, and therefore could not be removed.\n";
        else
        {
          *f = masterFaculty->getNode(facID)->getObj();
          tempArray = f->getAdvisees();
          for (int i = 0; i < f->getNumAdvisees(); ++i)
          {
            masterStudent->getNode(tempArray[i])->getObj().setAdvisor(masterFaculty->getMin()->getObj().getId());
            masterFaculty->getMin()->getObj().addAdvisee(tempArray[i]);
          }
          masterFaculty->deleteNode(facID);
          cout << "Faculty member deleted. His advisees have been reassigned to the faculty with the lowest ID.\n";
        }
        break;
      case 11: //change student's advisor
        hist->addHistory(*masterStudent);
        hist->addHistory(*masterFaculty);
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
        hist->addHistory(*masterStudent);
        hist->addHistory(*masterFaculty);
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
            masterFaculty->getNode(facID)->getObj().removeAdvisee(studID);
            cout << "Student " << studID << " successfully removed." << endl;
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

#include "Student.h"
#include "StudentTree.h"
#include "FacultyTree.h"
int main()
{
  StudentTree* students = new StudentTree();
  FacultyTree* faculty = new FacultyTree();

  int option;
  string idToBeFound;
  string info;

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
      //cout << students->getNode(idToBeFound) << endl;
      break;
    case 4: //find faculty member given id
      cout << "Enter the ID Number." << endl;
      cin >> idToBeFound;
      //cout << faculty.getNode(idToBeFound) << endl;
      break;
    case 5: //with id of student print info of faculty ADVISOR
      cout << "Enter the ID Number." << endl;
      cin >> idToBeFound;
      //cout << faculty.getNode((students->getNode(idToBeFound).getAdvisor()) << endl;
      break;
    case 6: //with id of faculty print names and id of adviseeString
      cout << "Enter the ID Number." << endl;
      cin >> idToBeFound;
      //cout << faculty.getNode(id.ToBeFound).getAdvisees() << endl;
      break;
    case 7: //add a new StudentTree
      Student* s = new Student();
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
      double d;
      cout << "\nGPA: ";
      cin >> d;
      s->setGPA(d);
      cout << "\nADVISOR: ";
      cin >> info;
      s->setAdvisor(info);
      //students->insert(s);  NEED TO OVERWRITE INSERT TO CHECK IDS ONLY?
      cout << "\n New student object created and inserted into tree." << endl;
  }
}

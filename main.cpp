#include "Student.h"
#include "StudentTree.h"
#include "FacultyTree.h"
int main()
{
  StudentTree* students = new StudentTree();
  FacultyTree* faculty = new FacultyTree();

  int option;
  string idToBeFound;

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
  }
}

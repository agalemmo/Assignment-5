#include "BST.h"
#include "Student.h"

class StudentTree : public BST<Student>
{
public:
  StudentTree();
};

StudentTree::StudentTree() : BST()
{
}

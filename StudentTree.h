#include "BST.h"
#include "Student.h"

class StudentTree : public BST<Student>
{
public:
  StudentTree();
  //TreeNode<Student>* getNode(string id);
};

StudentTree::StudentTree() : BST()
{
}

/*TreeNode<Student>* StudentTree::getNode(string id) : BST()
{
  return (Student)BST::getNode(string id);
}*/

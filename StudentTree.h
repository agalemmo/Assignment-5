#include "BST.h"
#include "Student.h"

class StudentTree : public BST<Student>
{
public:
  StudentTree();
  void printTree(TreeNode<Student>* root);
  void printTreeToFile(TreeNode<Student>* root);
  //TreeNode<Student>* getNode(string id);
};

StudentTree::StudentTree() : BST()
{
}

/*TreeNode<Student>* StudentTree::getNode(string id) : BST()
{
  return (Student)BST::getNode(string id);
}*/

void StudentTree::printTree(TreeNode<Student>* root)
{
  TreeNode<Student>* n = root;
  if (n)
  {
    printTree(n->left);
    n->data.print();
    printTree(n->right);
  }
  delete n;
}

void StudentTree::printTreeToFile(TreeNode<Student>* root)
{
  TreeNode<Student>* n = root;
  if (n)
  {
    printTreeToFile(n->left);
    n->data.printToFile();
    printTreeToFile(n->right);
  }
  delete n;
}

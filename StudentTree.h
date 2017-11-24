#include "BST.h"
#include "Student.h"

class StudentTree : public BST<Student>
{
public:
  StudentTree();
  void printTree(TreeNode<Student>* root);
  void printTreeToFile(TreeNode<Student>* root);
  //TreeNode<Student>* getNode(int id);
};

StudentTree::StudentTree() : BST()
{
}

/*TreeNode<Student>* StudentTree::getNode(int id) : BST()
{
  return (Student)BST::getNode(int id);
}*/

void StudentTree::printTree(TreeNode<Student>* root)
{
  cout << "PrintTree has been called.\n";
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

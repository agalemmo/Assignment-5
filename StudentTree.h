#include "BST.h"
#include "Student.h"

class StudentTree : public BST<Student>
{
public:
  StudentTree();
  void printTree(TreeNode<Student>* root);
  string printTreeToFile(TreeNode<Student>* root);
  //TreeNode<Student>* getNode(int id);
};

StudentTree::StudentTree() : BST()
{
}

/*TreeNode<Student>* StudentTree::getNode(int id) : BST()
{
  return (Student)BST::getNode(int id);
}*/

//TEMP FIX OF NO DELETE - look at this pls
void StudentTree::printTree(TreeNode<Student>* root)
{
  TreeNode<Student>* n = root;
  if (n)
  {
    printTree(n->left);
    n->data.print();
    printTree(n->right);
  }
}

string StudentTree::printTreeToFile(TreeNode<Student>* root)
{
  string returnString = "";
  TreeNode<Student>* n = root;
  if (n)
  {
    printTreeToFile(n->left);
    returnString += n->data.printToFile();
    printTreeToFile(n->right);
  }
  delete n;
  return returnString;
}

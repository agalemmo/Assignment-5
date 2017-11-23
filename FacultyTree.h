#include "BST.h"
#include "Faculty.h"

class FacultyTree : public BST<Faculty>
{
public:
  FacultyTree();
  void printTree(TreeNode<Faculty>* root);
  void printTreeToFile(TreeNode<Faculty>* root);
};

FacultyTree::FacultyTree() : BST()
{
}

void FacultyTree::printTree(TreeNode<Faculty>* root)
{
  TreeNode<Faculty>* n = root;
  if (n)
  {
    printTree(n->left);
    n->data.print();
    printTree(n->right);
  }
  delete n;
}

void FacultyTree::printTreeToFile(TreeNode<Faculty>* root)
{
  TreeNode<Faculty>* n = root;
  if (n)
  {
    printTreeToFile(n->left);
    n->data.printToFile();
    printTreeToFile(n->right);
  }
  delete n;
}

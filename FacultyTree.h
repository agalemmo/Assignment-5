#include "BST.h"
#include "Faculty.h"

class FacultyTree : public BST<Faculty>
{
public:
  FacultyTree();
  void printTree(TreeNode<Faculty>* root);
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
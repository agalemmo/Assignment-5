#include "BST.h"
#include "Faculty.h"

class FacultyTree : public BST<Faculty>
{
public:
  FacultyTree();
  void printTree(TreeNode<Faculty>* root);
  string printTreeToFile(TreeNode<Faculty>* root);
};

FacultyTree::FacultyTree() : BST()
{
}

//TEMP FIX OF NO DELETE - look at this pls
void FacultyTree::printTree(TreeNode<Faculty>* root)
{
  TreeNode<Faculty>* n = root;
  if (n)
  {
    printTree(n->left);
    n->data.print();
    printTree(n->right);
  }
}

string FacultyTree::printTreeToFile(TreeNode<Faculty>* root)
{
  string returnString = "";
  TreeNode<Faculty>* n = root;
  if (n)
  {
    printTreeToFile(n->left);
    returnString += n->data.printToFile();
    printTreeToFile(n->right);
  }
  delete n;
  return returnString;
}

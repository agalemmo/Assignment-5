#include "BST.h"
#include "Faculty.h"

class FacultyTree : public BST<Faculty>
{
public:
  FacultyTree();
  ~FacultyTree();
  void printTree(TreeNode<Faculty>* root);
  string printTreeToFile(TreeNode<Faculty>* root);
};

/**
Constructor inherits from BST Constructor
*/
FacultyTree::FacultyTree() : BST()
{
}

/**
Destructor empty - will automatically call parent's destructor upon Exit
*/
FacultyTree::~FacultyTree()
{}

/**
printTree outputs the tree to standard out in order
Parameter root - the root of the tree
*/
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

/**
printTreeToFile returns a string that is the tree in order
Does not actually print to file, but the resulting string can be printed.
Parametr root - the root of the tree
*/
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

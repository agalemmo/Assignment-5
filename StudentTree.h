/**
Sarah Lasman and Amanda Galemmo
2278776          2270004
lasma101@mail.chapman.edu  galem100@mail.chapman.edu
CS 350 Section 3
Assignment #5
*/

#include "BST.h"
#include "Student.h"

class StudentTree : public BST<Student>
{
public:
  StudentTree();
  ~StudentTree();
  void printTree(TreeNode<Student>* root);
  string printTreeToFile(TreeNode<Student>* root);
  //TreeNode<Student>* getNode(int id);
};

/**
Constructor inherited from parent
*/
StudentTree::StudentTree() : BST()
{
}

/**
Destructor empty - will automatically call parent's destructor upon Exit
*/
StudentTree::~StudentTree()
{}

/**
printTree outputs the tree to standard out in order
Parameter root - the root of the tree
*/
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

/**
printTreeToFile returns a string that is the tree in order
Does not actually print to file, but the resulting string can be printed.
Parameter root - the root of the tree
*/
string StudentTree::printTreeToFile(TreeNode<Student>* root)
{
  string returnString = "";
  TreeNode<Student>* n = root;
  if (n)
  {
    returnString += printTreeToFile(n->left);
    returnString += n->data.printToFile();
    returnString += printTreeToFile(n->right);
  }
  return returnString;
}

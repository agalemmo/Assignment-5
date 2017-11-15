#include "Student.h"

class TreeNode
{
  public:
    TreeNode* left;
    TreeNode* right;
    int height;
    int key; //ID Number
    Student data; //the student object

    TreeNode();
    TreeNode(int k, Student s);
    ~TreeNode();

    //create front pointer?
};

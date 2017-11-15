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

TreeNode::TreeNode()
{
  left = NULL;
  right = NULL;
  key = 0;
  data = NULL;
}

TreeNode::TreeNode(int k, Student s)
{
  left = NULL;
  right = NULL;
  key = k;
  data = s;
}

TreeNode::~TreeNode()
{
  //let's build character, have fun!!!!!!!!!!!@!!@!!!!!!
}

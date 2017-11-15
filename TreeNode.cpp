#include "TreeNode.h"

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

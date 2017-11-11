#include "BST.h"

BST::BST()
{
  root = NULL
}

BST::~BST()
{
  //build more character

  //iterate and delete
}

TreeNode* BST::getMin()
{
  TreeNode *current = root; //always start at root

  if(root == NULL)
    return null;

  while (current->left != NULL)
  {
    current = current -> left;
  }

  return current;
}

TreeNode* BST::getMax()
{
  TreeNode *current = root; //always start at root

  if(root == NULL)
    return null;

  while (current->right != NULL)
  {
    current = current -> right;
  }

  return current;
}

void BST::insert(int value)
{
  TreeNode *newNode = new TreeNode(value);

  if (root == NULL) //empty TreeNode
    root = newNode;

  else //not empty
  {
    TreeNode *current = root; //always start at the root
    TreeNode *parent; //empty node

    while (true)
    {
      parent = current;

      if (value < current->key)
      {
        current = current->left;

        if (current == NULL)
        {
          //found the location for the new node
          parent->left = newNode;
          break;
        }
      }
      else //go right
      {
        current = current->right;
        if (current == NULL)
        {
          parent->right = newNode;
          break;
        }
      }
    }
  }
}

bool BST::contains(int value)
{
  if (root == NULL)
    return false;

  else
  {
    TreeNode* current = root;

    while (current->key != value)
    {
      if (value < current->key)
        current = current->left;
      else
        current = current->right;

      if (current == NULL)
        return false;
    }
  }
  return true;
}

bool BST::deleteNode(int k)
{
  if(root == NULL)
    return false;

  TreeNode *current = root;
  TreeNode *parent = root;
  bool isLeft = true;

  //need to find the node we want to deleteNode

  while(current->key != k)
  {
    parent = current;

    if (k < current->key)
    {
      isLeft = true;
      curent = current->left;
    }
    else
    {
      isLeft = false;
      current = current->right;
    }

    if (current == NULL)
    {
      return false;
    }
  }

  //we have found the node we want to delete. now it's time to build character.

  //the node is a leaf, no children
  if (current->left == NULL && current->right == NULL)
  {
    if (current == root)
      root == NULL;
    else if (isLeft)
      parent->left = NULL;
    else //it's right
      parent->right = NULL;
  }
  //one child
  else if (current->right == NULL) //then it's the left child
  {
    if (current == root)
      root = current->left;
    else if (isLeft)
      parent->left = current->left;
    else //right
      parent->right = current->left;
  }
  else if (current->left == NULL)
  {
    if (current == root)
      root = current->right;
    else if (isLeft)
      parent->left = current->right;
    else
      parent->right = current->right;
  }
  else //the node has two children, now rip
  {
      TreeNode *successor = getSuccessor(current);

      if (current == root)
        root = successor;
      else if (isLeft)
        parent->left = successor;
      else
        parent->right = successor;

      successor->left = current->left;
  }
  return true;
}

TreeNode* BST::getSuccessor(TreeNode *d)
{
  TreeNode *current = d->right;
  TreeNode *successor = d;
  TreeNode *sp = d;

  while (current != NULL)
  {
    sp = successor;
    successor = current;
    current = current->left;
  }

  if (successor != d->right) //update pointers, descendent of right child
  {
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

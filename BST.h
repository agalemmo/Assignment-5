#ifndef BST_H
#define BST_H

#include "TreeNode.h"

template <class T>
class BST
{
  public:
    BST();
    ~BST();

    void insert (string id, T data);
    bool contains(string id);
    bool deleteNode(string id);
    TreeNode<T>* getNode(string id);
    TreeNode<T>* getSuccessor(TreeNode<T>* d);
    TreeNode<T>* getMin();
    TreeNode<T>* getMax();

    void printTree();

  private:
    TreeNode<T>* root;
};

template <class T>
BST<T>::BST()
{
  root = NULL;
}

template <class T>
BST<T>::~BST()
{
  //build more character

  //iterate and delete
}

template <class T>
TreeNode<T>* BST<T>::getMin()
{
  TreeNode<T>* current = root; //always start at root

  if(root == NULL)
    return NULL;

  while (current->left != NULL)
  {
    current = current -> left;
  }

  return current;
}

template <class T>
TreeNode<T>* BST<T>::getMax()
{
  TreeNode<T>* current = root; //always start at root

  if(root == NULL)
    return NULL;

  while (current->right != NULL)
  {
    current = current -> right;
  }

  return current;
}

template <class T>
void BST<T>::insert(string id, T data)
{
  TreeNode<T>* newNode = new TreeNode<T>(id, data);

  if (root == NULL) //empty TreeNode
    root = newNode;

  else //not empty
  {
    TreeNode<T>* current = root; //always start at the root
    TreeNode<T>*parent; //empty node

    while (true)
    {
      parent = current;

      if (id < current->key)
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

template <class T>
bool BST<T>::contains(string id)
{
  if (root == NULL)
    return false;

  else
  {
    TreeNode<T>* current = root;

    while (current->key != id)
    {
      if (id < current->key)
        current = current->left;
      else
        current = current->right;

      if (current == NULL)
        return false;
    }
  }
  return true;
}

template <class T>
bool BST<T>::deleteNode(string id)
{
  if(root == NULL)
    return false;

  TreeNode<T>* current = root;
  TreeNode<T>*parent = root;
  bool isLeft = true;

  //need to find the node we want to deleteNode

  while(current->key != id)
  {
    parent = current;

    if (id < current->key)
    {
      isLeft = true;
      current = current->left;
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
      root = NULL;
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
      TreeNode<T>*successor = getSuccessor(current);

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

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>*d)
{
  TreeNode<T>* current = d->right;
  TreeNode<T>*successor = d;
  TreeNode<T>*sp = d;

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

template <class T>
TreeNode<T>* BST<T>::getNode(string id)
{
  if (root == NULL)
  {
    cout << "Node not found" << endl;
    return NULL;
  }

  else
  {
    TreeNode<T>* current = root;

    while (current->key != id)
    {
      if (id < current->key)
        current = current->left;
      else
        current = current->right;

      if (current == NULL)
      {
        cout << "Node not found" << endl;
        return NULL;
      }
    }
    return current;
  }
}

#endif

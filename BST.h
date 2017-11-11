#include "TreeNode.h"

class BST
{
  public:
    BST();
    virtual ~BST(); //you know the drill

    void insert (int value);
    bool contains(int value);
    bool deleteNode(TreeNode* node);
    TreeNode* getSuccessor(TreeNode* d);
    TreeNode* getMin();
    TreeNode* getMax();

    void printTree();

  private:
    TreeNode* root;
};

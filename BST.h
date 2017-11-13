#include "TreeNode.h"

class BST
{
  public:
    BST();
    virtual ~BST(); //you know the drill

    void insert (int id, Student data);
    bool contains(int id);
    bool deleteNode(int id);
    TreeNode* getSuccessor(TreeNode* d);
    TreeNode* getMin();
    TreeNode* getMax();

    void printTree();

  private:
    TreeNode* root;
};

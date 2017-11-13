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
    virtual ~TreeNode();

    //create front pointer?
};

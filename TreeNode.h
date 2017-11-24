
template <class T>
class TreeNode
{
  public:
    TreeNode<T>* left;
    TreeNode<T>* right;
    int height;
    int key; //ID Number
    T data; //the T object

    TreeNode();
    TreeNode(int k, T s);
    ~TreeNode();

    T getObj();

    //create front pointer?
};

template <class T>
TreeNode<T>::TreeNode()
{
  left = NULL;
  right = NULL;
  key = 0;
  data = *new T();
}

template <class T>
TreeNode<T>::TreeNode(int k, T s)
{
  left = NULL;
  right = NULL;
  key = k;
  data = s;
}
template <class T>
TreeNode<T>::~TreeNode()
{
  //let's build character, have fun!!!!!!!!!!!@!!@!!!!!!
}

template <class T>
T TreeNode<T>::getObj()
{
  return data;
}

/**
Sarah Lasman and Amanda Galemmo
2278776          2270004
lasma101@mail.chapman.edu  galem100@mail.chapman.edu
CS 350 Section 3
Assignment #5
*/

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
    void setObj(T obj);

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
  delete left;
  delete right;
  delete &data;
}

template <class T>
T TreeNode<T>::getObj()
{
  return data;
}

template <class T>
void TreeNode<T>::setObj(T obj)
{
  data = obj;
}

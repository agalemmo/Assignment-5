#include "BST.h"
#include "Faculty.h"

class FacultyTree : public BST<Faculty>
{
public:
  FacultyTree();
};

FacultyTree::FacultyTree() : BST()
{
}

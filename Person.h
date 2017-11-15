#include <iostream>

using namespace std;

class Person
{
  private:
    int id;
    string name;
    string level;
  public:
    Person();
    Person(int iden, string nam, string lvl);
    ~Person();

    int getId();
    string getName();
    string getLevel();

    void setId(int n);
    void setName(string s);
    void setLevel(string s);

    //overloading operators
    
    print();
};

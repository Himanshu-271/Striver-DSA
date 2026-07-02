#include <iostream>
using namespace std;

// base class
class employee
{
public:
    int id;

    float salary;
    employee(int inpid)
    {
        id = inpid;
        salary = 34000;
    }

    employee() {}
};

// derived class
class programmer : employee
{
public:
    int languagecode = 9;
    programmer(int inid)
    {
        id = inid;
    }
};

int main()
{
    employee harry(1), rohan(2);
    cout << "salary harry:" << harry.salary << endl;
    cout << "salary of rohan: " << rohan.salary << endl;
    programmer skillf(1);
    cout << skillf.languagecode;
    return 0;
}
/*    // Derived Class syntax
class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
    class members/methods/etc...
}*/
/* Default visibility mode is private
Public Visibility Mode: Public members of the base class becomes Public members of the derived class
Private Visibility Mode: Public members of the base class become private members of the derived class
Private members are never inherited */
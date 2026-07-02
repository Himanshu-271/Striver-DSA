#include <iostream>
using namespace std;

class number
{
    int a;

public:
    // number() {}

    number()
    {
        a = 0;
    }

    number(int num)
    {
        a = num;
    }

    // when no copy cons found , compiler supplies it own copy cons. ;
    number(number &obj)
    {
        cout << " copy cons called!! " << endl;
        a = obj.a;
    }

    void display()
    {
        cout << "the no. of this obj is :" << a << endl;
    }
};

int main()
{
    number x, y, z(45), z2;
    x.display();
    y.display();
    z.display();
    number z1(x);
    z1.display();

    z2 = z; // copy cons not invoked;
    z2.display();

    number z3 = z; // invoked
    z3.display();
    return 0;
}
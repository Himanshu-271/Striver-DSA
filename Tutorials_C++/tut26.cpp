#include <iostream>
using namespace std;

class complex
{
    int a, b;

public:
    void setNUmber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    friend complex complexSum(complex o1, complex o2); // here complexSum fxn xs to use private xs of class use friend with comples class
    void print()
    {
        cout << "your cmplx no is :" << a << " + " << b << "i" << endl;
    }
};
complex complexSum(complex o1, complex o2)
{
    complex o3;
    o3.setNUmber((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}
int main()
{
    complex c1, c2;
    c1.setNUmber(1, 4);
    c1.print();

    c2.setNUmber(3, 6);
    c2.print();

    complex sum = complexSum(c1, c2);
    sum.print();
    return 0;
}

/*
-> * Properties of friend functions
1. Not in the scope of class
2. since it is not in the scope of the class, it cannot be called from the object of that class. c1.sumComplex() == Invalid
3. Can be invoked without the help of any object
4. Usually contans the objects as arguments
5. Can be declared inside public or private section of the class
6. It cannot access the members directly by their names and need object_name.member_name to access any member.

*/

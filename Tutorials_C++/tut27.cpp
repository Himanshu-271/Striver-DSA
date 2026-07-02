#include <iostream>
using namespace std;

class complex;
class calc
{

    int a, b;

public:
    int add(int a, int b)
    {
        return (a + b);
    }

    int sumrealcomplex(complex, complex);
};

class complex
{
    int a, b;
    friend int calc ::sumrealcomplex(complex, complex);
    // eg friend class calc; -> whole class cmplx friend of calc

    //   we can also make whole calss as friend so we xs to use
    // any data  of cmplx class by calc class use if full trust to whole class ;
    // if indu. fxn ko hi premit karna h to no use only that sep fxns ko hi friend bna ke use karo;
public:
    void setData(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    void print()
    {
        cout << "your no is: " << a << " + " << b << "i" << endl;
    }
};

int calc ::sumrealcomplex(complex o1, complex o2)
{
    return (o1.a + o2.a);
}

int main()
{
    complex o1, o2;
    int a, b, c, d;
    cout << "enter the a:" << endl;
    cin >> a;
    cout << "enter the b:" << endl;
    cin >> b;
    cout << "enter the c:" << endl;
    cin >> c;
    cout << "enter the d:" << endl;
    cin >> d;
    o1.setData(a, b);
    o2.setData(c, d);
    calc C;
    int res = C.sumrealcomplex(o1, o2);
    cout << "the sum of real part is:" << res << endl;

    return 0;
}
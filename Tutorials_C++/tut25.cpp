#include <iostream>
using namespace std;
/*class Employee
{
    int id;
    int salary;

public:
    void setID(void)
    {
        cout << "enter the ID:" << endl;
        cin >> id;
    }
    void getID(void)
    {
        cout << "the id of this emp is:" << id << endl;
    }
};*/

class complex
{
    int a, b;

public:
    void setdata(int v1, int v2)
    {
        a = v1;
        b = v2;
    }
    void setdatasub(complex o1, complex o2) // comlex -> use data type here o1 -> that obj of cmplx data tpe
    // o1 can xs class any var pub or priv we know class ke andar we xs any class var wether priv or pub;
    {
        a = o1.a - o2.a;
        b = o1.b - o2.b;
    }
    void print()
    {
        if (b >= 0)
            cout << "your complex no is: " << a << " + " << b << "i" << endl;
        else
            cout << "your complex no is: " << a << " - " << -b << "i" << endl;
    }
};
int main()
{
    // Employee em[10];
    // for (int i = 0; i < 3; i++)
    // {
    //     em[i].setID();
    //     em[i].getID();
    // }
    complex c1, c2, c3;
    int x, y, p, q;

    cout << "enter x:" << endl;
    cin >> x;
    cout << "enter y:" << endl;
    cin >> y;
    cout << "enter p:" << endl;
    cin >> p;
    cout << "enter q:" << endl;
    cin >> q;

    c1.setdata(x, y);
    c1.print();

    c2.setdata(p, q);
    c2.print();

    c3.setdatasub(c1, c2);
    c3.print();

    return 0;
}
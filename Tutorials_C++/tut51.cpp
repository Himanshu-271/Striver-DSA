#include <iostream>
using namespace std;

class complex
{
    int real, im;

public:
    void getdata()
    {
        cout << "the real part :" << real << endl;
        cout << "the img part :" << im << endl;
    }
    void setdata(int x, int y);
};

void complex ::setdata(int x, int y)
{
    real = x;
    im = y;
}
int main()
{
    complex c;
    int a, b;
    cin >> a >> b;

    complex *ptr = &c;
    // arrow operator

    c.setdata(a, b); // (*ptr).setdata(a,b)==== ptr->setdata(a,b)
    c.getdata();     // (*ptr).getdata()======ptr-> getdata()

    return 0;
}
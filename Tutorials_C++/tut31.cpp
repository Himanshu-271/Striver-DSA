#include <iostream>
using namespace std;

class complex
{
    int a, b;

public:
    complex(int x, int y)
    {
        a = x;
        b = y;
    }
    complex(int x) // we make multi constructor;
    {
        a = x;
        b = 0;
    }
    void print()
    {
        cout << "your no is: " << a << " + " << b << "i" << endl;
    }
};

int main()
{
    complex c(4, 6);
    c.print();

    complex c2(4);
    c2.print(); // b -> automatic set 0  // match atq to argument pass

    return 0;
}
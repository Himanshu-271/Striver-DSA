#include <iostream>
using namespace std;

class complex
{
    int a, b;

public:
    complex(int, int); // cons. declatration
    void print()
    {
        cout << "your no is: " << a << " + " << b << "i" << endl;
    }
};
complex ::complex(int x, int y) // -> parametrise constructor;
{
    a = x;
    b = y;
}
int main()
{
    int a, b;
    cout << "enter a:";
    cin >> a;
    cout << "enter b:";
    cin >> b;

    complex c(a, b);
    c.print();

    return 0;
}
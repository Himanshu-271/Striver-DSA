#include <iostream>
using namespace std;

class simple
{
    int data1, data2;

public:
    simple(int a, int b = 3) // we use cons. with deafult arg;
    {
        data1 = a;
        data2 = b;
    }
    void print()
    {
        cout << " the vla of data is:" << data1 << "and " << data2;
    }
};

int main()
{
    simple s(1); // b already set deafult 3;
    s.print();

    return 0;
}
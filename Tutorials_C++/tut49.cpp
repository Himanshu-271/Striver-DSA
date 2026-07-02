#include <iostream>
using namespace std;

class test
{
    int a, b;
    // int b, a; //> for lat wale ke liya ;

public:
    // test(int i, int j) : a(i), b(j)
    // test(int i, int j) : a(i + 1), b(j * 2)
    // test(int i, int j) : a(i + 1), b(a * 2)
    test(int i, int j) : a(b + 1), b(j * 2) // -> order materr of intilising var so here a need b first then
    // b intiliase first warna error com garbage val come a;
    {
        cout << " the val of a:" << a << endl;
        cout << "the val of b:" << b << endl;
    }
};

int main()
{
    test val(5, 6);
    return 0;
}
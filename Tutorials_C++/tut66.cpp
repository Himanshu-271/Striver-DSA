#include <iostream>
using namespace std;

template <class t1 = int, class t2 = float> // t= data type var store
class boby
{
public:
    t1 a;
    t2 b;
    boby(t1 x, t2 y)
    {
        a = x;
        b = y;
    }
    void display()
    {
        cout << "the val of a :" << a << endl;
        cout << "the val of b :" << b << endl;
    }
};

int main()
{
    boby<> b(4, 9.1);
    b.display();
    boby<float, int> b2(1.1, 2); // change
    b2.display();
    return 0;
}
/*
-> by using template we change data type atq
-> use template when we need chnage data type in progrrame



*/
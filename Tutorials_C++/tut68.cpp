#include <iostream>
using namespace std;

template <class t1>

class boby
{

public:
    t1 data;
    boby(t1 a)
    {
        data = a;
    }

    void display();
};
template <class t1>

// void boby<t1>::display()
// {
//     cout << data << endl;
// }

void func(t1 a)
{
    cout << " I am fine:" << endl;
}
void func(int a)
{
    cout << " I am ok" << endl;
}

int main()
{

    // boby<int> b(5);
    // boby<int> h(5);
    func(6); // ->if exat match highest prior call

    // cout << h.data << endl;
    return 0;
}
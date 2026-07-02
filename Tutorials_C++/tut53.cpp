#include <iostream>
using namespace std;

class A
{

    int a;

public:
    A &setdata(int a)
    // void setdata(int a)
    {
        this->a = a;  // this pointer
        return *this; //*this == obj original onj return
    }

    void getdata()
    {
        cout << " the val of is :" << a << endl;
    }
};
int main()
{
    A a;
    a.setdata(0);
    a.getdata();

    return 0;
}

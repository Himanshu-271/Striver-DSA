#include <iostream>
#include <string>
using namespace std;

// class emp
// {
// private:
//     int a, b, c;

// public:
//     int d, e;
//     void setData(int a, int b, int c);
//     void getData()
//     {
//         cout << "the value of a:" << a << endl;
//         cout << "the value of b:" << b << endl;
//         cout << "the value of c:" << c << endl;
//         cout << "the value of d:" << d << endl;
//         cout << "the value of e:" << e << endl;
//     }
// };

// void emp ::setData(int a1, int b1, int c1)
// {
//     a = a1;
//     b = b1;
//     c = c1;
// }

class Dog
{
private:
    string myDog;

public:
    string dogesh;
    void setData(string myDog);
    void getData()
    {
        cout << "my dog name is: " << myDog << endl;
        cout << "dogesh bhai is: " << dogesh << endl;
    }
};
void Dog ::setData(string myDog)
{
    this->myDog = myDog;
}

int main()
{
    // emp boby;
    // // boby.a=11;
    // // boby.b=12;
    // // boby.c=13;
    // boby.d = 34;
    // boby.e = 33;
    // boby.setData(1, 2, 3);
    // boby.getData();

    Dog D;
    D.dogesh = "katiya";
    D.setData("Tommy");
    D.getData();
    return 0;
}
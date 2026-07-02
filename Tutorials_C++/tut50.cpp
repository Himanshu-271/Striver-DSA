#include <iostream>
using namespace std;

int main()
{
    // int a = 9;
    // int *p = &a;
    // cout << p << endl;
    // cout << &a << endl;
    // cout << *p << endl;
    // cout << a << endl;
    // *p = 1;
    // cout << *p << endl;
    // cout << a;

    int *arr = new int[3]; // heap meomry allocate  us when size input decided ho
    // fxn ke bad b chiye meomry; size flexible
    arr[0] = 1;
    arr[1] = 8;
    arr[2] = 3;

    // delete[] arr;  // -> free array (dynamic allocate memory)
    //-> but pointer whi h abhi tak : Dangling pointer
    cout << *arr << endl;
    cout << *(arr + 1) << endl;
    cout << *(arr + 2) << endl;

    // delet operator

    return 0;
}
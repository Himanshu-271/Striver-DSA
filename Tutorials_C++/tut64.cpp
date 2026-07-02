#include <iostream>
using namespace std;

template <class T>
class vector
{

    int size;

public:
    T *arr;
    vector(int m)
    {
        size = m;
        arr = new int[size];
    }
    int dotpro(vector &v)
    {
        int d = 0;
        for (int i = 0; i < size; i++)
        {
            d += this->arr[i] * v.arr[i];
        }
        return d;
    }
};
int main()
{
    vector<int> v1(3);
    cout << "enter v1: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cin >> v1.arr[i];
    }

    vector<int> v2(3);
    cout << "enter v2: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cin >> v2.arr[i];
    }

    int a = v1.dotpro(v2);
    cout << a;
    return 0;
}
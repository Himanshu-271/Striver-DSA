#include <iostream>
using namespace std;

template <class t1, class t2>

// float avg(int a, int b)
// {
//     return float(a + b) / 2;
// }

// float avg2(int w, float x)
// {
//     return float(w + x) / 2;
// }

float avg(t1 a, t2 b)
{
    return float(a + b) / 2; // T1,T2 decide during compile time its data type
}

int main()
{
    int x;
    float y;
    int z;
    cin >> x >> y >> z;
    // float a = avg(x, y);
    float a = avg(x, z);

    cout << "the avg is: " << a << endl;
    return 0;
}
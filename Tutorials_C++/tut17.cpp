#include <iostream>
using namespace std;
inline int pro(int x, int y)
{ // it inc speed we need incline fxn(req.. to compiler) inc speed so small fxn incline  karo
    int p = x * y;
    return p;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "thr product is:" << pro(a, b);
    return 0;
}

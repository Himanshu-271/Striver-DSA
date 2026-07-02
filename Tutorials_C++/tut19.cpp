#include <iostream>
using namespace std;

int add(int a, int b, int c)
{
    return a + b + c;
}
int add(int a, int b)
{
    return a + b;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = add(a, b);
    int ans2 = add(a, b, c);
    cout << "ans :" << ans << endl
         << "ans2 : "
         << ans2;
    return 0;
}
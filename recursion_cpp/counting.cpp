#include <bits/stdc++.h>
using namespace std;

void counting(int i, int n)
{
    if (i < 1)
        return;

    else
        counting(i - 1, n);

    cout << i << " ";
}
int main()
{

    int n;
    cout << "the val of n:";
    cin >> n;
    // counting(1, n);
    // backtracing-->
    counting(n, n);
    return 0;
}
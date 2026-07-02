#include <bits/stdc++.h>
using namespace std;
void backcount(int i, int n)
{
    if (i > n)
        return;
    else
        backcount(i + 1, n);
    cout << i << " ";
}
int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;
    backcount(1, n);

    return 0;
}
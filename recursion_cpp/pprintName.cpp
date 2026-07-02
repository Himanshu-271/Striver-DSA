#include <bits/stdc++.h>
using namespace std;

void print(int i, int n)
{
    if (i < n)
    {
        cout << "boby" << endl;
    }

    else
        return;
    print(i + 1, n);
}
int main()
{
    int n;
    cout << "the val of :n";
    cin >> n;
    print(0, n);

    return 0;
}
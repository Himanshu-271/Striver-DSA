#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;
    int No = n;
    int cube = 0;
    while (n > 0)
    {
        int rem = n % 10;
        cube = rem * rem * rem + cube;
        n = n / 10;
    }
    if (No == cube)
        cout << "armstrong NO";
    else
        cout << "Not";

    return 0;
}
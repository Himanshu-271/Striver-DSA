#include <bits/stdc++.h>
using namespace std;

int addn(int p, int q)
{
    return (p + q);
}

void printName(string name)
{
    cout << name;
}

int max(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

int main()
{
    int a, b;
    cin >> a >> b;
    // int G = addn(a, b);
    // cout << G;

    // string str;
    // cout << "give string:";
    // cin >> str;
    // printName(str);
    int minimum = max(a, b);

    return 0;
}
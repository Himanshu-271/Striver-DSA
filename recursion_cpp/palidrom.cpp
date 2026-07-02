#include <bits/stdc++.h>
using namespace std;
bool check(string &str, int i, int j)
{
    if (i >= j)
        return true;
    if (str[i] != str[j - 1])
        return false;
    else
        return check(str, i + 1, j - 1);
}
int main()
{
    string str;
    cin >> str;
    cout << check(str, 0, str.size());
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string subS;
    cout << "substring:";
    cin >> subS;

    string s;
    cout << "string:";
    cin >> s;

    while (s.length() != 0 && s.find(subS) < s.length())
    {
        s.erase(s.find(subS), subS.length());
    }

    cout << s;

    return 0;
}
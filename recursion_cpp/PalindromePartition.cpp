#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(int idx, int i, string &s)
{
    while (idx <= i)
    {
        if (s[idx] != s[i])
            return false;

        idx++;
        i--;
    }
    return true;
}

void palindrome(int idx, string &s, vector<vector<string>> &ans, vector<string> &ls)
{

    if (idx == s.size())
    {
        ans.push_back(ls);
        return;
    }

    for (int i = idx; i < s.size(); i++)
    {
        if (ispalindrome(idx, i, s))
        {
            ls.push_back(s.substr(idx, i - idx + 1));
            palindrome(i + 1, s, ans, ls);
            ls.pop_back();
        }
    }
}

int main()
{

    string s;
    cout << "enter string:";
    cin >> s;

    vector<vector<string>> ans;
    vector<string> ls;

    palindrome(0, s, ans, ls);

    for (auto it : ans)
    {
        for (auto x : it)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
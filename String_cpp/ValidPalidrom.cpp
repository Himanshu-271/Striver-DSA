#include <bits/stdc++.h>
using namespace std;

// skip unuseable char-->
bool validChar(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return true;

    else
        return false;
}

// conversion-->
char lowercase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch;
    else if (ch >= 'A' && ch <= 'Z')
        return (ch - 'A' + 'a');
    else
        return ch;
}

bool Palidrome(string s)
{

    // new string store valid char-->
    string temp = "";

    for (int j = 0; j < s.size(); j++)
    {
        if (validChar(s[j]))
            temp.push_back(s[j]);
    }

    int i = 0;
    int j = temp.size() - 1;

    while (i < j)
    {
        if (lowercase(temp[i]) != lowercase(temp[j]))
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{

    string s;
    cout << "string is:";
    getline(cin, s);

    cout << Palidrome(s);

    return 0;
}
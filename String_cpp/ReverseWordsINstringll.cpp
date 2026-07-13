#include <bits/stdc++.h>
using namespace std;

void revWord(vector<char> &v, int x, int y)
{
    while (x < y)
    {
        swap(v[x], v[y]);
        x++;
        y--;
    }
}

int main()
{
    string s;
    cout << "string :";
    getline(cin, s);

    int read = 0;
    int word = 0;

    while (read < s.size())
    {

        if (s[read] != ' ')
        {
            s[word] = s[read];
            word++;
            read++;
            continue;
        }

        while (read < s.size() && s[read] == ' ')
            read++;

        if (word != 0 && read < s.size() && s[read - 1] == ' ')
        {
            s[word] = ' ';
            word++;
        }
    }

    vector<char> v(s.begin(), s.end());

    reverse(v.begin(), v.end());

    int i = 0;
    int j = i + 1;
    while (j < v.size())
    {
        if (v[j] == ' ')
        {
            revWord(v, i, j - 1);
            j++;
            i = j;
            j++;
        }
        else if (j == v.size() - 1)
        {
            revWord(v, i, j);
            j++;
        }
        else
            j++;
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }

    return 0;
}
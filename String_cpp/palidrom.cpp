#include <bits/stdc++.h>
using namespace std;

// uppercase-->lower case convert

char lowercase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch;
    else
        return (ch - 'A' + 'a');
}

int main()
{
    char ch[20];
    cin >> ch;

    int len = 0;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        len++;
    }

    // brute -->

    //  rev string form that equate with real string;
    // than   check it palidrom or not;

    // optimal -->

    // pointers -->
    int i = 0;
    int j = len - 1;
    bool flag = true;

    while (i < j)
    {
        // taken upper case lower case same;
        if (lowercase(ch[i]) != lowercase(ch[j]))
        {
            flag = false;
            break;
        }
        i++;
        j--;
    }
    cout << flag;

    return 0;
}
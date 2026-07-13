#include <bits/stdc++.h>
using namespace std;

bool checkEqual(int arr[], int brr[])
{
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != brr[i])
            return false;
    }
    return true;
}

int main()
{

    string S1;
    cout << "string s1:";
    cin >> S1;

    string S2;
    cout << "string s2:";
    cin >> S2;

    // if s2 contain permu. of s1-->

    bool ans = false;

    // hash array for chars-->
    int hs[26] = {0};

    for (int i = 0; i < S1.size(); i++)
    {
        hs[S1[i] - 'a']++;
    }

    // window in main sting S2 travsel-->

    int i = 0;
    int j = S1.size();

    int hs2[26] = {0};

    // not posible --->

    if (S1.size() > S2.size())
    {
        cout << ans;
        return 0;
    }

    while (i < j)
    {
        hs2[S2[i] - 'a']++;
        i++;
    }

    if (checkEqual(hs, hs2))
    {
        ans = true;
        cout << ans;
        return 0;
    }

    // move further-->

    while (i < S2.size())
    {
        char newChar = S2[i];
        hs2[newChar - 'a']++;

        char oldChar = S2[i - j];
        hs2[oldChar - 'a']--;

        if (checkEqual(hs, hs2))
        {
            ans = true;
            break;
        }
        i++;
    }

    cout << ans;

    return 0;
}
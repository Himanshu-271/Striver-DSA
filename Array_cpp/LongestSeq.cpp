#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int len = 1;

    // brute approch-->
    /*
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        int x = arr[i];
        for (int j = 0; j < n; j++)
        {
            if (x + 1 == arr[j])
            {
                cnt++;
                x = arr[j];
                j = 0;
            }
        }
        len = max(len, 1 + cnt);
    }
    cout << len;
    */

    // Better-->

    /*    sort(arr, arr + n);
        if(n==0) return 0;
        int LS = arr[0];
        int len = 1;
        int i = 0;
        int cnt = 0;
        while (i < n)
        {
            if (arr[i] - LS == 1)
            {
                cnt++;
                LS = arr[i];
                i++;
            }
            else if (arr[i] - LS == 0)
            {
                i++;
            }

            else
            {
                LS = arr[i];
                cnt = 0;
                i++;
            }

            len = max(len, 1 + cnt);
        }
        cout << len;
    */

    // optimal -->

    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                cnt++;
                x = x + 1;
            }
            len = max(len, cnt);
        }
    }
    cout << len;
    return 0;
}
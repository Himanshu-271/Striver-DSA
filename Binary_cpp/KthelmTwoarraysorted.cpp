#include <bits/stdc++.h>
using namespace std;

int main()
{

    int k;
    cout << "the kth elm:";
    cin >> k;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int m;
    cout << "the val of m:";
    cin >> m;

    vector<int> brr(m);

    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
    }

    int flag = 0;

    if (k > (m + n))
    {
        cout << "invalid";
        flag = 1;
    }

    // better -->

    int cnt = 0;
    int p1 = 0;
    int p2 = 0;
    int elm = -1;

    if (flag == 0)
    {
        while (p1 < n && p2 < m)
        {
            if (arr[p1] < brr[p2])
            {
                cnt++;
                if (cnt == k)
                {
                    elm = arr[p1];
                    flag = 1;
                    break;
                }
                p1++;
            }
            else
            {
                cnt++;
                if (cnt == k)
                {
                    elm = brr[p2];
                    flag = 1;
                    break;
                }
                p2++;
            }
        }

        while (p1 < n && flag == 0)
        {
            cnt++;
            if (cnt == k)
            {
                elm = arr[p1];
                flag = 1;
                break;
            }
            p1++;
        }

        while (p2 < m && flag == 0)
        {
            cnt++;
            if (cnt == k)
            {
                elm = brr[p2];
                flag = 1;
                break;
            }

            p2++;
        }
        cout << elm;
    }

    return 0;
}
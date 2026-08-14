#include <bits/stdc++.h>
using namespace std;

/*void SubSeq(int idx, vector<int> &arr, vector<int> &ls, int k, int s)
{

    if (idx >= arr.size())
    {
        if (s == k)
        {
            for (auto it : ls)
                cout << it << " ";

            cout << endl;
        }
        return;
    }

    ls.push_back(arr[idx]);
    s += arr[idx];
    SubSeq(idx + 1, arr, ls, k, s);

    s -= arr[idx];
    ls.pop_back();
    SubSeq(idx + 1, arr, ls, k, s);
}*/

// only one sub seq need->

bool SubSeq(int idx, vector<int> &arr, vector<int> &ls, int k, int s)
{

    if (idx >= arr.size())
    {
        if (s == k)
        {
            for (auto it : ls)
                cout << it << " ";

            cout << endl;

            return true;
        }
        return false;
    }

    ls.push_back(arr[idx]);
    s += arr[idx];
    if (SubSeq(idx + 1, arr, ls, k, s) == true)
        return true;

    s -= arr[idx];
    ls.pop_back();
    if (SubSeq(idx + 1, arr, ls, k, s) == true)
        return true;

    return false;
}

int main()
{

    int k;
    cout << "the val of k:";
    cin >> k;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << endl;
    vector<int> ls;
    int sum = 0;

    SubSeq(0, arr, ls, k, sum);

    return 0;
}
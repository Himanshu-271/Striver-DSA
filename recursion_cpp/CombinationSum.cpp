#include <bits/stdc++.h>
using namespace std;

void Combination(int idx, vector<int> &arr, int k, vector<int> &ls)
{

    if (idx >= arr.size())
    {
        if (k == 0)
        {
            for (auto it : ls)
                cout << it << " ";

            cout << endl;
        }

        return;
    }

    // pick->
    if (arr[idx] <= k)
    {
        ls.push_back(arr[idx]);

        Combination(idx, arr, k - arr[idx], ls);

        ls.pop_back();
    }
    // not pick

    Combination(idx + 1, arr, k, ls);
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

    Combination(0, arr, k, ls);

    return 0;
}
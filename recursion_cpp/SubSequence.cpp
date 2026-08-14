#include <bits/stdc++.h>
using namespace std;

void Subsequense(int idx, vector<int> &arr, vector<int> &ls)
{

    if (idx >= arr.size())
    {
        if (ls.empty())
        {
            cout << "{}";
        }

        else
        {
            for (auto it : ls)
            {
                cout << it << " ";
            }
        }
        cout << endl;

        return;
    }

    // take elm-->
    ls.push_back(arr[idx]);
    Subsequense(idx + 1, arr, ls);

    // not take-->
    ls.pop_back();
    Subsequense(idx + 1, arr, ls);
}

int main()
{
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

    Subsequense(0, arr, ls);
    return 0;
}
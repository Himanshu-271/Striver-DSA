#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "the val of n";
    cin >> n;
    int arr[n];
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mpp[arr[i]]++;
    }
    // mapp iterate kare to sorted ans;
    // for (auto it : mpp)
    // {
    //     cout << it.first << "->" << it.second;
    // }
    int query;
    cin >> query;
    while (query--)
    {
        int no;
        cin >> no;
        cout << mpp[no] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// max no is 12;
int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int hs[13] = {0};
    for (int i = 0; i < n; i++)
    {
        hs[arr[i]]++;
    }
    int query;
    cin >> query;

    while (query--)
    {
        int no;
        cin >> no;
        cout << hs[no] << endl;
    }
    return 0;
}
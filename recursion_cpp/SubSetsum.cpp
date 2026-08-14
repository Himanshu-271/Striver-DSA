#include <bits/stdc++.h>
using namespace std;

void SubSet(int idx, vector<int> &arr, vector<int> &ls, vector<int> &ans)
{

    // brute--->

    /* if (arr.empty())
     {
         ans.push_back(0);
         return;
     }

     if (idx >= arr.size())
     {

         if (ls.empty())
             ans.push_back(0);

         else
         {
             int x = accumulate(ls.begin(), ls.end(), 0);

             ans.push_back(x);
         }

         return;
     }

     ls.push_back(arr[idx]);
     SubSet(idx + 1, arr, ls, ans);

     ls.pop_back();
     SubSet(idx + 1, arr, ls, ans);
     */
}

void subset(int idx, vector<int> &arr, vector<int> &ans, int sum)
{

    if (idx >= arr.size())
    {
        ans.push_back(sum);
        return;
    }

    // pick -->

    subset(idx + 1, arr, ans, sum + arr[idx]);

    // no pick-->

    subset(idx + 1, arr, ans, sum);
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
    vector<int> ans;

    // brute-->

    //  SubSet(0, arr, ls, ans);

    //  optimal-->

    int sum = 0;

    subset(0, arr, ans, sum);

    sort(ans.begin(), ans.end());

    for (auto it : ans)
        cout << it << endl;

    return 0;
}
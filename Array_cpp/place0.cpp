#include <bits/stdc++.h>
using namespace std;
// very brute -->
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
    // vector<int> temp;
    /* for (int i = 0; i < n; i++)
     {
         if (arr[i] != 0)
             temp.push_back(arr[i]);
         else
             temp.insert(temp.begin(), arr[i]);
     }
     for (int i = 0; i < temp.size(); i++)
     {
         arr[i] = temp[temp.size() - 1 - i];
     }
     for (int i = 0; i < temp.size(); i++)
     {
         cout << arr[i] << " ";
     } */
    // brute+better-->

    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] != 0)
    //         temp.push_back(arr[i]);
    // }
    // for (int i = 0; i < temp.size(); i++)
    // {
    //     arr[i] = temp[i];
    // }
    // for (int i = temp.size(); i < n; i++)
    // {
    //     arr[i] = 0;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // optimal soln-->

    int j = -1; // pointer at 0 find first
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }

    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
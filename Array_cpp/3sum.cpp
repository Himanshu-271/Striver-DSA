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

    // brute -->

    /* set<vector<int>> ans;

     for (int i = 0; i < n; i++)
     {
         for (int j = i + 1; j < n; j++)
         {

             for (int k = j + 1; k < n; k++)
             {
                 if (arr[i] + arr[j] + arr[k] == 0)
                 {
                     vector<int> temp = {arr[i], arr[j], arr[k]};
                     sort(temp.begin(), temp.end());
                     ans.insert(temp);
                 }
             }

             //  cout << endl;
         }
     }

     for (auto row : ans)
     {
         for (auto val : row)
         {
             cout << val << " ";
         }
         cout << endl;
     }
         */

    // better -->
    // by hashing

    /*   set<vector<int>> ans;
       set<int> hs;
       for (int i = 0; i < n; i++)
       {
           hs.clear();
           for (int j = i + 1; j < n; j++)
           {
               int third = -(arr[i] + arr[j]);
               if (hs.find(third) != hs.end())
               {
                   vector<int> temp = {arr[i], arr[j], third};
                   sort(temp.begin(), temp.end());
                   ans.insert(temp);
               }
               hs.insert(arr[j]);
           }
       }

       for (auto row : ans)
       {
           for (auto val : row)
           {
               cout << val << " ";
           }
           cout << endl;
       }
   */
    // optimal -->
    sort(arr, arr + n);
    vector<vector<int>> ans;
    // pseudo three pointer-->
    int i = 0, k = 1, j = n - 1;
    while (i < n - 2)
    {
        int sum = arr[i] + arr[k] + arr[j];

        if (sum > 0)
        {
            j--;
        }

        else if (sum < 0)
        {
            k++;
        }

        else
        {
            vector<int> temp = {arr[i], arr[k], arr[j]};
            ans.push_back(temp);
            k++;
            j--;
            // duplicate transverse-->
            while (k < j && arr[k] == arr[k - 1])
                k++;
            while (k < j && arr[j] == arr[j + 1])
                j--;
        }
        if (k >= j) // when cross
        {
            i++; // move
            // duplicate transevrse-->
            while (i < n - 2 && arr[i] == arr[i - 1])
            {
                i++;
            }
            k = i + 1; // again asign
            j = n - 1;
        }
    }

    for (auto row : ans)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

// MY idea--> using set
// if use set no duplicate transverse   tc=O(n2logn);
// striver -->
// after duplicate transverses pointer move no use set tc=O(n2);
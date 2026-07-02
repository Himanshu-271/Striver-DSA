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

    /*  set<vector<int>> ans;

      for (int i = 0; i < n; i++)
      {
          for (int j = i + 1; j < n; j++)
          {

              for (int k = j + 1; k < n; k++)
              {
                  for (int l = k + 1; l < n; l++)
                  {
                      if (arr[i] + arr[j] + arr[k] + arr[l] == 0)
                      {
                          vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                          sort(temp.begin(), temp.end());
                          ans.insert(temp);
                      }
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
      }*/

    // better -->
    // by hashing

    /*  set<vector<int>> ans;
      set<int> hs;
      for (int i = 0; i < n; i++)
      {

          for (int j = i + 1; j < n; j++)
          {
              hs.clear();
              for (int k = j + 1; k < n; k++)
              {
                  int forth = -(arr[i] + arr[j] + arr[k]);
                  if (hs.find(forth) != hs.end())
                  {
                      vector<int> temp = {arr[i], arr[j], arr[k], forth};
                      sort(temp.begin(), temp.end());
                      ans.insert(temp);
                  }
                  hs.insert(arr[k]);
              }
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

    // optimal soln-->

    sort(arr, arr + n);
    // int i = 0, j = n - 1, k = 1, l = n - 2;
    int i = 0, j = 1, k = 2, l = n - 1;
    vector<vector<int>> ans;
    while (i < n - 3)
    {
        int sum = arr[i] + arr[j] + arr[k] + arr[l];
        if (sum > 0)
            l--;
        else if (sum < 0)
            k++;
        else
        {
            ans.push_back({arr[i], arr[j], arr[k], arr[l]});
            k++;
            l--;

            while (k < l && arr[k] == arr[k - 1])
                k++;

            while (k < l && arr[l] == arr[l + 1])
                l--;
        }
        if (k >= l)
        {
            // i++;
            // while (i < n - 3 && arr[i] == arr[i - 1])
            //     i++;

            j++;
            while (j < n - 2 && arr[j] == arr[j - 1])
                j++;

            k = j + 1;
            l = n - 1;

            if (j >= n - 2)
            {
                i++;
                while (i < n - 3 && arr[i] == arr[i - 1])
                    i++;

                j = i + 1;
                k = j + 1;
            }
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
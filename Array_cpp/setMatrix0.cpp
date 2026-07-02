#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "the rows :";
    cin >> n;
    cout << "the colms:";
    cin >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Very brute force>>>>

    // visited array mark 1 where 0;
    /*  int vis[n][m] = {0};

      for (int i = 0; i < n; i++)
      {
          for (int j = 0; j < m; j++)
          {
              if (arr[i][j] == 0)
              {
                  vis[i][j] = 1;
              }
          }
      }

      // where vis= 1  that row or clm full 0 kar de ge
      for (int i = 0; i < n; i++)
      {
          for (int j = 0; j < m; j++)
          {
              if (vis[i][j] == 1)
              {
                  int k = i;
                  int l = j;

                  for (int a = 0; a < m; a++)
                  {
                      arr[k][a] = 0;
                  }
                  for (int b = 0; b < n; b++)
                  {
                      arr[b][l] = 0;
                  }
              }
          }
      }*/

    // better--.

    /*
    int row[n] = {0};
    int clm[m] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                row[i] = 1;
                clm[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 1 || clm[j] == 1)
            {
                arr[i][j] = 0;
            }
        }
    }
        */

    // optimal soln-->

    int clm = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][0] = 0;

                if (j != 0)
                    arr[0][j] = 0;
                else
                    clm = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] != 0)
            {
                if (arr[i][0] == 0 || arr[0][j] == 0)
                {
                    arr[i][j] = 0;
                }
            }
        }
    }

    if (arr[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            arr[0][j] = 0;
        }
    }
    if (clm == 0)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i][0] = 0;
        }
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
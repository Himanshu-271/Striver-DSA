#include <bits/stdc++.h>
using namespace std;

void Path(int r, int c, vector<vector<int>> &arr, vector<string> &ans, string &path, vector<vector<int>> &vis)
{

    if (r >= arr.size() - 1 && c >= arr[0].size() - 1)
    {
        ans.push_back(path);
        return;
    }

    // downards

    if (r < arr.size() - 1 && arr[r + 1][c] == 1 && vis[r + 1][c] != 1)
    {
        vis[r][c] = 1;
        path += 'D';
        Path(r + 1, c, arr, ans, path, vis);
        vis[r][c] = 0;
        path.pop_back();
    }

    // left

    if (c > 0 && arr[r][c - 1] == 1 && vis[r][c - 1] != 1)
    {
        vis[r][c] = 1;
        path += 'L';
        Path(r, c - 1, arr, ans, path, vis);
        vis[r][c] = 0;
        path.pop_back();
    }

    // right

    if (c < arr[0].size() - 1 && arr[r][c + 1] == 1 && vis[r][c + 1] != 1)
    {
        vis[r][c] = 1;
        path += 'R';
        Path(r, c + 1, arr, ans, path, vis);
        vis[r][c] = 0;
        path.pop_back();
    }

    // upwards

    if (r > 0 && arr[r - 1][c] == 1 && vis[r - 1][c] != 1)
    {
        vis[r][c] = 1;
        path += 'U';
        Path(r - 1, c, arr, ans, path, vis);
        vis[r][c] = 0;
        path.pop_back();
    }
}

void Path2(int r, int c, vector<vector<int>> &arr, vector<string> &ans, string &path, vector<vector<int>> &vis, int di[], int dj[])
{
    if (r == arr.size() - 1 && c == arr[0].size() - 1)
    {
        ans.push_back(path);
        return;
    }

    string s = "DLRU";

    for (int idx = 0; idx < 4; idx++)
    {
        int nexti = r + dj[idx];
        int nextj = c + dj[idx];

        if (nexti >= 0 && nextj >= 0 && nexti < arr.size() && nextj < arr[0].size() && !vis[nexti][nextj] && arr[nexti][nextj] == 1)
        {
            vis[r][c] = 1;
            path += s[idx];
            Path2(nexti, nextj, arr, ans, path, vis, di, dj);
            vis[r][c] = 0;
            path.pop_back();
        }
    }
}

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j]; // 0 or 1
        }
    }

    cout << endl;

    vector<vector<int>> vis(n, vector<int>(n, 0));

    vector<string> ans;
    string path = "";

    int row = 0;
    int clm = 0;

    // if (arr[row][clm] != 0)
    // Path(row, clm, arr, ans, path, vis);

    int di[] = {1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};

    Path2(row, clm, arr, ans, path, vis, di, dj);

    if (ans.empty())
        cout << "no such path exist";

    else
    {
        for (auto it : ans)
        {
            for (auto x : it)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
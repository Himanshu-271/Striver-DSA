#include <bits/stdc++.h>
using namespace std;

int fn(int arr[], int l, int h)
{
    int mid = (l + h) / 2;
    int pivot = arr[mid];
    int left = l;
    int right = h;
    swap(arr[l], arr[mid]);
    while (left < right)
    {
        while (left <= h - 1 && arr[left] <= pivot)
        {
            left++;
        }
        while (right >= l + 1 && arr[right] > pivot)
        {
            right--;
        }
        if (left < right)
            swap(arr[left], arr[right]);
    }
    swap(arr[l], arr[right]);
    return right;
}
void QS(int arr[], int l, int h)
{
    if (l < h)
    {
        int Pindex = fn(arr, l, h);
        QS(arr, l, Pindex - 1);
        QS(arr, Pindex + 1, h);
    }
}
int main()
{
    int n, m;
    cout << "the val of n:";
    cin >> n;
    cout << "the val of m:";
    cin >> m;
    int arr1[n] = {0};
    int arr2[m] = {0};
    cout << "arr1:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << "arr2:";
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    // sorting-->
    QS(arr1, 0, n - 1);
    QS(arr2, 0, m - 1);
    // Brute force-->

    vector<int> arr;
    // visited array take on arr2;

    /*
    int vis[m] = {0};
    for (int i = 0; i < n; i++)
    {
        // ponint elm of arr1  check with whole arr2 ;
        for (int j = 0; j < m; j++)
        {
            // if it present add or visted 1 so no count again;
            if (arr1[i] == arr2[j] && vis[j] == 0)
            {
                arr.push_back(arr1[i]);
                vis[j] = 1;
                break;
            }
            // if arr1[i] elm less present arr2 elm no possible found elm ;
            if (arr1[i] < arr2[j])
                break;
        }
    }*/

    // optimal soln---->

    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {

        // if eqaul so add  move both;
        if (arr1[i] == arr2[j])
        {
            arr.push_back(arr1[i]);
            i++;
            j++;
        }
        // if less arr1 than arr2 no pair find mover arr1
        else if (arr1[i] < arr2[j])
            i++;
        // same as for arr2
        else
            j++;
    }

    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}
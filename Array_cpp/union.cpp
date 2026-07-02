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

    /*set<int> un;
     for (int i = 0; i < n; i++)
     {
         un.insert(arr1[i]);
     }
     for (int j = 0; j < m; j++)
     {
         un.insert(arr2[j]);
     }

     for (auto it : un)
     {
         cout << it << " ";
     }
         */
    vector<int> arr;
    int i = 0, j = 0;
    // merging-->
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            if (arr.empty() || arr.back() != arr1[i])
                /// check arr not empty 0r back push elm not equal to current elm add
                arr.push_back(arr1[i]);
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            if (arr.empty() || arr.back() != arr2[i])
                arr.push_back(arr2[j]);
            j++;
        }
        else
        {
            if (arr.empty() || arr.back() != arr1[i])
                arr.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    // remove dulpicate come further left array
    int l = i;
    int r = i + 1;
    while (r <= n - 1)
    {
        while (r <= n - 1 && arr1[l] == arr1[r])
        {
            r++;
        }
        arr.push_back(arr1[l]);
        l = r;
        r = l + 1;
    }
    if (l <= n - 1)
    {
        arr.push_back(arr1[l]);
    }

    int L = j;
    int H = j + 1;
    while (H <= m - 1)
    {
        while (H <= m - 1 && arr2[L] == arr2[H])
        {
            H++;
        }
        arr.push_back(arr2[L]);
        L = H;
        H = L + 1;
    }
    if (L <= m - 1)
    {
        arr.push_back(arr2[L]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
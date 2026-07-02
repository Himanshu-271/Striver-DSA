#include <bits/stdc++.h>
using namespace std;

/* bool check(int arr[], int a, int b, int M)
{
    /* for (int i = a; i <= b; i++)
     {
         for (int j = i + 1; j <= b; j++)
         {
             if (arr[i] + arr[j] == M && i != j)
                 return true;
         }
     }
     return false;
    int i = 0;
    map<int, int> hs;
    for (int i = 0; i <= b; i++)
    {
        if (hs.find(arr[i]) == hs.end())
            hs[arr[i]] = i;
    }
    for (int i = 0; i <= b; i++)
    {
        if (hs.find(M - arr[i]) != hs.end() && hs[M - arr[i]] != i)
        {
            return true;
        }
    }
    return false;
} */

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
    int n;
    cout << "the val of n:";
    cin >> n;
    int M;
    cout << "the val of M:";
    cin >> M;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // brute or better -->
    // cout << check(arr, 0, n - 1, M);

    // optimal-->
    QS(arr, 0, n - 1);
    int i = 0, j = n - 1;
    int sum = 0;
    int flag = 0;
    while (i < j)
    {

        sum = arr[i] + arr[j];
        if (sum < M)
        {
            //  sum = sum - arr[i] + arr[i + 1];
            i++;
        }
        else if (sum > M)
        {
            //  sum = sum - arr[j] + arr[j - 1];
            j--;
        }
        else
        {

            flag = 1;
            return 1;
        }
    }
    if (flag == 0 && i >= j)
        cout << " not exist ";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void duplicate(int arr[], int L, int H)
{
    int left = L;
    int right = L + 1;
    vector<int> temp;
    while (right <= H)
    {

        while (right <= H && arr[left] == arr[right])
        {
            right++;
        }
        temp.push_back(arr[left]);
        left = right;
        right = left + 1;
    } // last elm-->
    if (left <= H)
    {
        temp.push_back(arr[left]);
    }
    int n = temp.size();
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "unique elm are:" << n;
}
int main()
{
    int n;
    cout << ":the val of n:";
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    duplicate(arr, 0, n - 1);

    return 0;
}
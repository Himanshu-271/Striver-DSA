#include <bits/stdc++.h>
using namespace std;

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

    // brute-->

    /*vector<int> leftN;
    int candy = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        if (i == 0)
        {
            leftN.push_back(1);
            candy = 1;
            continue;
        }

        else if (arr[i - 1] < arr[i])
        {
            candy++;

            leftN.push_back(candy);
        }

        else
        {
            candy = 1;
            leftN.push_back(candy);
        }
    }

    candy = 0;

    vector<int> rightN;

    for (int i = arr.size() - 1; i >= 0; i--)
    {

        if (i == arr.size() - 1)
        {
            rightN.push_back(1);
            candy = 1;
            continue;
        }

        else if (arr[i + 1] < arr[i])
        {
            candy++;

            rightN.push_back(candy);
        }

        else
        {
            candy = 1;
            rightN.push_back(candy);
        }
    }

    reverse(rightN.begin(), rightN.end());

    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        ans += max(rightN[i], leftN[i]);
    }

    cout << ans;*/

    // optimal--->

    // peak approch->

    int sum = 1;
    int peak = 1;
    int down = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            sum += 1;
            continue;
        }

        int peak = 1;

        while (i < n && arr[i] > arr[i - 1])
        {
            peak + 1;
            sum += peak;
            i++;
        }

        int down = 1;

        while (i < n && arr[i] < arr[i - 1])
        {

            sum += down;
            i++;
            down += 1;
        }

        if (down > peak)
            sum += (down - peak);
    }

    cout << sum;

    return 0;
}

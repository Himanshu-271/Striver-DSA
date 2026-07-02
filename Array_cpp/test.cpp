#include <bits/stdc++.h>
using namespace std;

int bruteForce(vector<int> nums)
{
    int cnt = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if ((long long)nums[i] > 2LL * nums[j])
                cnt++;
    return cnt;
}

// Tera merge sort code
long long merge(vector<int> &nums, int L, int M, int H)
{
    long long cnt = 0;
    int left = L, right = M + 1;
    vector<int> temp;
    while (left <= M && right <= H)
    {
        if (nums[left] >= nums[right])
        {
            int x = left;
            while (x <= M)
            {
                if ((long long)nums[x] > 2LL * nums[right])
                {
                    cnt += M - x + 1;
                    break;
                }
                x++;
            }
            temp.push_back(nums[right]);
            right++;
        }
        else
        {
            temp.push_back(nums[left]);
            left++;
        }
    }
    while (left <= M)
        temp.push_back(nums[left++]);
    while (right <= H)
        temp.push_back(nums[right++]);
    for (int i = L; i <= H; i++)
        nums[i] = temp[i - L];
    return cnt;
}

long long revPairs(vector<int> &nums, int l, int h)
{
    long long cnt = 0;
    int mid = (l + h) / 2;
    if (l >= h)
        return 0;
    cnt += revPairs(nums, l, mid);
    cnt += revPairs(nums, mid + 1, h);
    cnt += merge(nums, l, mid, h);
    return cnt;
}

int main()
{
    srand(42);
    for (int t = 0; t < 10000; t++)
    {
        vector<int> a, b;
        int n = rand() % 8 + 2;
        for (int i = 0; i < n; i++)
        {
            int x = rand() % 20 - 10;
            a.push_back(x);
            b.push_back(x);
        }
        int bf = bruteForce(a);
        long long ms = revPairs(b, 0, b.size() - 1);
        if (bf != ms)
        {
            cout << "FAIL: ";
            for (int x : a)
                cout << x << " ";
            cout << "\nBrute: " << bf << " Merge: " << ms << "\n";
            return 0;
        }
    }
    cout << "All passed!\n";
}
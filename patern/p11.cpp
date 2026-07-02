#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << " the value of n:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int start = 1;
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;
        for (int j = 0; j <= i; j++)
        {
            if (start == 1)
            {
                if (j % 2 == 0)
                    cout << "1";
                else
                    cout << "0";
            }

            else
            {
                if (j % 2 == 0)
                    cout << "0";
                else
                    cout << "1";
            }
        }
        cout << endl;
    }
    return 0;
}
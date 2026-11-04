#include <bits/stdc++.h>
using namespace std;

bool Lemonade(vector<int> &bills)
{
    int fives = 0;
    int tens = 0;

    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
            fives++;

        else if (bills[i] == 10)
        {
            if (fives)
            {
                fives--;
                tens++;
            }
            else
                return false;
        }

        else
        {
            if (tens > 0 && fives > 0)
            {
                tens--;
                fives--;
            }

            else if (fives > 2)
            {
                fives -= 3;
            }

            else
                return false;
        }
    }

    return true;
}

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> bills(n); // only 5,10,20

    for (int i = 0; i < n; i++)
    {
        cin >> bills[i];
    }

    bool ans = Lemonade(bills);

    cout << ans;
    return 0;
}
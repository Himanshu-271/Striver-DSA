#include <bits/stdc++.h>
using namespace std;

int main()
{
    int age;
    cout << "age is :";
    cin >> age;

    // if (age >= 18)
    // {
    //     cout << "Adult" << endl;
    // }
    // else if (age < 18 && age >= 15)
    //     cout << " teenager";

    // else
    //     cout << "not an adult " << endl;
    if (age < 18)
        cout << " not eligble for job ";

    else if (age <= 57)
    {
        cout << " eligble for job";
        if (age >= 55)
            cout << "retirement soon" << endl;
    }
    else
        cout << "retirement time";
    return 0;
}
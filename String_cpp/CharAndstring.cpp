#include <bits/stdc++.h>
using namespace std;

int main()
{

    // one meory creat of name ch store-- a;
    char ch = 'a';

    // string-->
    // 1-d character array;

    char st[20];
    // input take--
    cin >> st;

    // at end of string '\0' terminator ;  Ascii val = 0;

    // cout << st;

    // points-->

    /*
    --> cin stop excute where gap come or 1st string end;
    eg -- tab,enter,gap;  it create \0 after gap;

    hellow baby ---> it print hellow only;
    */

    // length compute-->

    // use loop (i=0 to st[i]!='\0',i++) ;

    int count = 0;
    for (int i = 0; st[i] != '\0'; i++)
    {
        count++;
    }
    cout << count << endl;

    // reverse string -->

    for (int i = 0; i < count / 2; i++)
    {
        swap(st[i], st[count - 1 - i]);
    }

    cout << st;

    return 0;
}
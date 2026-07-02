#include <iostream>
using namespace std;

class BankDepo
{
    int principal;
    int yr;
    float intrestrate;
    float returnval;

public:
    BankDepo() {}
    BankDepo(int p, int y, float r);
    BankDepo(int p, int y, int r);
    void show();
};

BankDepo ::BankDepo(int p, int y, float r)
{
    principal = p;
    yr = y;
    intrestrate = r;
    returnval = principal;
    for (int i = 0; i < y; i++)
    {
        returnval = returnval * (1 + r);
    }
}

BankDepo ::BankDepo(int p, int y, int r)
{
    principal = p;
    yr = y;
    intrestrate = float(r) / 100;
    returnval = principal;
    for (int i = 0; i < y; i++)
    {
        returnval = returnval * (1 + r);
    }
}
void BankDepo::show()
{
    cout << endl
         << "Principal amount was :" << principal
         << " return vla after " << yr << endl
         << " yr is :" << returnval << endl;
}

int main()
{
    BankDepo bd1, bd2, bd3;
    int p, y;
    float r;
    int R;

    cout << "enter val of p,y and r:" << endl;
    cin >> p >> y >> r;

    bd1 = BankDepo(p, y, r);
    bd1.show();

    cout << "enter val of p,y and R:" << endl;
    cin >> p >> y >> R;

    bd2 = BankDepo(p, y, R);
    bd2.show();

    bd3.show();

    return 0;
}
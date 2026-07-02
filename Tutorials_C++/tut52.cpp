#include <iostream>
using namespace std;

class shop
{
    int id;
    float price;

public:
    void setdata(int a, float b)
    {
        id = a;
        price = b;
    }
    void getdata()
    {
        cout << "code of this item is: " << id << endl;
        cout << "price of this item: " << price << endl
             << endl;
        ;
    }
};
int main()
{
    int n;
    cout << " enter n:";
    cin >> n;
    int size = n;
    shop *p = new shop[size];
    int r;
    float q;
    shop *ptrtemp = p; // so ptrtemp restore add of arr
    for (int i = 0; i < size; i++)
    {
        cout << " Id and price of item " << i + 1 << endl;
        cin >> r >> q;
        p->setdata(r, q);
        p++;
    }

    for (int j = 0; j < size; j++)
    {
        cout << "item no: " << j + 1 << endl;
        ptrtemp->getdata(); // if use ptr++ it point outside of array bcoz
        // in above loop ptr already point last elm;
        ptrtemp++;
    }

    return 0;
}
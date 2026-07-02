#include <iostream>
using namespace std;
class Y;

class X
{
    int data;
    int a;

public:
    void setData(int value)
    {
        data = value;
    }
    void setval(int x)
    {
        a = x;
    }
    friend void add(X, Y);
    friend void swap(X *, Y *);
    void display()
    {
        cout << a << endl;
    }
};
class Y
{
    int num, b;

public:
    void setData(int value)
    {
        num = value;
    }
    void setval(int y)
    {
        b = y;
    }
    friend void add(X, Y);
    friend void swap(X *, Y *);
    void display()
    {
        cout << b << endl;
    }
};
void add(X o1, Y o2)
{
    cout << " sum of data of X And Y give : " << o1.data + o2.num << endl;
}
void swap(X *p1, Y *p2) // synatx here “pointer p(of that class) jis object ko point kar raha hai, uska member a”
{
    int temp = p1->a;
    p1->a = p2->b;
    p2->b = temp;
}
int main()
{
    int p, q, r, s;
    cout << "enter p:";
    cin >> p;
    cout << "enter q:";
    cin >> q;
    cout << "enter r:";
    cin >> r;
    cout << "enter s:";
    cin >> s;
    X a, o1;
    a.setData(p);
    o1.setval(r);

    Y b, o2;
    b.setData(q);
    o2.setval(s);

    add(a, b);
    swap(&o1, &o2);
    cout << "the value of r: " << endl;
    o1.display();
    cout << "the value of s: " << endl;
    o2.display();
    return 0;
}
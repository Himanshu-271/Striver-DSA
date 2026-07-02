#include <iostream>
#include <cmath>
using namespace std;

class point
{
    int x, y, X, Y;

public:
    point(int a, int b, int c, int d)
    {
        x = a;
        y = b;
        X = c;
        Y = d;
    }

    float distance();
};

float point::distance()
{
    float D = sqrt((x - X) * (x - X) + (y - Y) * (y - Y));
    return D;
}

int main()
{
    int h, i, j, k;
    cout << "enter h:";
    cin >> h;
    cout << "enter i:";
    cin >> i;
    cout << "enter j:";
    cin >> j;
    cout << "enter k:";
    cin >> k;

    point p(h, i, j, k);
    float ans = p.distance();
    cout << " the dis. bw two point is:" << ans;

    return 0;
}
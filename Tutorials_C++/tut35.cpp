#include <iostream>
using namespace std;

int count = 0;
// Destructor neve take an argu. nor does it return value
/* -> destructor auto call when any object scope is end from fxn;
-> it clean up the memory


*/

class num
{
public:
    num()
    {
        count++;
        cout << "this is the time when constructor is called for object no :" << count << endl;
    }
    ~num() // destructor
    {
        cout << " this is the time when my destructor is called for obj no : " << count << endl;
        count--;
    }
};

int main()
{
    cout << "we are in main fxn" << endl;
    cout << "creat first first obj n1" << endl;
    num n1;
    {
        cout << "enter this block " << endl;
        cout << "creat two more obj" << endl;
        num n2, n3;
        cout << "exiting this block" << endl;
    }
    cout << " back to main" << endl;
    return 0;
}
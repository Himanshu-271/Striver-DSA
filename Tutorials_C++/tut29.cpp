#include <iostream>
using namespace std;
class complex
{
    int a, b;

public:
    // creating a constructor;
    // constructor is a special member fxn with same name as of class
    // it is auto matic invoked(call karna).
    // it is used to initilise the object of class
    complex(void); // cons. declatration
    void print()
    {
        cout << "your no is: " << a << " + " << b << "i" << endl;
    }
};

complex ::complex(void) // auto matic call // cons. no need return  type
{
    cout << "enter a:";
    cin >> a;
    cout << "enter b:"; // bad practice cin ke liya use nhi karna ;
    // user input always bhar se low main se;
    cin >> b;

    // a = 10;
    // b = 0;               // nothing give value garbage val come'
}

int main()
{
    complex c;
    c.print();

    return 0;
}
/* properties of cons.
1. it should be declare in public sec.
2. they auotmatic invoked whenever the obj created.
3. do not have return type.
4. it can have deafult argument.
5. we can"t refer to their address.

*/
#include<iostream>
using namespace std;

int main() {
        int a=9;
        int *p=&a;
        int* *z =&p;
        cout<<a<<endl;
        cout<<*p<<endl;
        cout<<p<<endl;
        cout<<&a<<endl;
        cout<<&p<<endl;
        cout<<z<<endl;
        cout<<*z<<endl;
        cout<<**z<<endl;

    
    return 0;
}
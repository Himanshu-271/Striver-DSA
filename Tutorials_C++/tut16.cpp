#include<iostream>
using namespace std;
   // void swap(int ,int);
// void swappointer(int *, int *);
void swapref (int &x, int &y){
    int temp =x;
    x=y;
    y=temp;
}

int main() {
    int a,b;
    cin>>a;
    cin>>b;
   // swap(a,b);
   //swappointer(&a,&b);
   swapref(a,b);
    cout<<"the swap value is:"<<endl<<a<<endl<<b;
   

    return 0;
}
// void swap (int x, int y){
//     int temp =x;
//     x=y;
//     y=temp;
// }
// void swappointer (int *x, int *y){
//     int temp =*x;
//     *x=*y;
//     *y=temp;
// }

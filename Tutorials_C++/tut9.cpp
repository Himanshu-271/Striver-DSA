#include<iostream>
using namespace std;
int main (){
    // const float pi=3.14;
    // const float e=2.71;
        int age;
    cout<<"tell me your age:"<<endl;
    cin>>age;
    if(age>=18) cout<<"you are ready to vote";
    else cout<<"not";
    switch(age){
        case 18: cout<<"ready to vote"; break;
        case 10 : cout<<"not" ; break;
        default: cout<<"no special case"; break;

    }

    return 0;
}
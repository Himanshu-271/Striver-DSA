#include<iostream>
using namespace std;
    struct pockemon{
        int hp,attack;
        char name[20];
        char type;
    }pika;
    union money{
    float rice;
    char car;
    float pounds;

    }m1;
int main() {
    
    // pika.hp=100;
    // pika.attack=30;
    // pika.type='A';
    // cout<<"the hp is:"<<pika.hp<<endl;
    // cout<<"the attack is:"<<pika.attack<<endl;
    // cout<<"the type is:"<<pika.type<<endl;
    // m1.rice=10;
    // m1.car='A';
    // cout<<m1.rice<<endl;
    //  cout<<m1.car<<endl;

    enum Meal{breakfast,lunch,dinner};
    cout<<breakfast<<endl;
    cout<<lunch<<endl;
    cout<<dinner<<endl;
    Meal m1=breakfast;
    cout<<m1;
    return 0;
}
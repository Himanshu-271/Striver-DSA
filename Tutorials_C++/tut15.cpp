#include<iostream>
using namespace std;
int sum(int x, int y){
    int c=x+y;
    return c;

}
void greet(void);
// int sum(int, int)
int main() {
    int a,b;
    cin>>a;
    cin>>b;
    int ans=sum(a,b);
    cout<<"the ans is:"<<ans<<endl;
    greet();
    return 0;
}
void greet(){
    cout<<"hello";
}
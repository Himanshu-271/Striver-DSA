#include<iostream>
using namespace std;
int main (){
    // counting
    int n;
    cout<<"enter n:";
    cin>>n;
    // for(int i=1;i<=n;i++){
    //     printf("%d ",i);
    // }

    int i=0;
    // while(i<=n){
    //     cout<<i<<endl;
    //     i++;

    // }
    do { 
        int ans= i*6;
        cout<<ans<<endl;
        i++;
    } while(i<=n);

    return 0;
}
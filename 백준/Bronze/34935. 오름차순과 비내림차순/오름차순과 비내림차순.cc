#include <iostream>
using namespace std;
main(){
    long long n=0, k=-1000000000000000001;
    cin>>n;
    while(n --> 0){
        long long t;
        cin>>t;
        if(k==t){
            cout<<0;
            return 0;
        }
        k=t;
    }
    cout<<1;
}
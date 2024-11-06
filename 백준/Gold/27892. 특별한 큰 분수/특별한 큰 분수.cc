#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    unsigned long long int a,b;
    cin>>a>>b;

    while(b--){
        if(a%2){
            a = (a<<1)^6;
        }
        else{
            a = (a>>1)^6;
        }
        if(a==4)break;
        else if(a==12 || a==0 || a==6 || a==5){
            b%=4;
        }
        else if(a==7 || a==8 || a==2){
            b%=3;
        }
    }
    cout<<a;

    return 0;
}
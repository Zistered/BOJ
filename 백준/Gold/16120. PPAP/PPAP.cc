#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>

using namespace std;

char a[1000009];
int pos;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while(cin>>a[pos]){
        if(pos>=3 && a[pos]=='P'){
            if(a[pos-3]=='P' && a[pos-2]=='P' && a[pos-1]=='A'){
                pos-=3;
            }
            a[pos+1]=a[pos+2]=a[pos+3]='\0';
        }
        pos++;
        // cout<<a<<endl;
    }
    if(pos==1 && a[0]=='P'){
        cout<<"PPAP";
    }
    else cout<<"NP";
    return 0;
}
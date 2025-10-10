#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include <unistd.h>
#include <limits.h>

using namespace std;

int n, mx, mxc;
vector<int> sy;

void prpr(int a, int b){
    for(auto i:sy){
        cout<<i<<' ';
    }cout<<endl;
    cout<<string(a*2,' ')<<"^"<<endl;
    cout<<string(b*2,' ')<<"^"<<endl;
}

// void cutting(int l){
//     int v=l, nc=0;
//     for(int i=l+1; i<n; i++){
//         // cout<<sy[i]<<'('<<i<<") ";
//         // cout<<sy[i]<<"vs"<<sy[v]<<": "<<nc<<endl;
//         prpr(i,v);
//         if(i-v<nc*2){i--;
//             nc=0,v=l;
//             cout<<endl;
//         }
//         if(sy[i]==sy[v]){
//             //cout<<sy[i]<<'('<<i<<')'<<' ';
//             nc++;
//             if(mx<nc){
//                 mxc = 1;
//                 mx = nc;
//             }
//             else if(mx==nc){
//                 mxc++;
//             }
//             v++;
//         }
//         else{
//             if(nc) i--;
//             v=l, nc=0;
//             cout<<endl;
//         }
//     }
// }

void cutting(){
    int v=0;
    vector<int> key(n, 0);
    for(int i=1; i<n; i++){
        //prpr(i,v);
        while(v && sy[i]!=sy[v]){
            v = key[v-1];
        }
        if(sy[i]==sy[v]){
            key[i] = ++v;
            if(mx<v){
                mxc = 1;
                mx = v;
            }
            else if(mx==v){
                mxc++;
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>n;
    stack<int> tmp;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        tmp.push(k);
    }
    while(!tmp.empty()){
        sy.push_back(tmp.top());
        tmp.pop();
    }
    cutting();
    if(mx==0) cout<<-1;
    else cout<<mx<<' '<<mxc;

    return 0;
}
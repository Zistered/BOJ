#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <limits.h>

using namespace std;

int n, k, h[200002], mb=21, bc[29];
bool hb[200002][29];
vector<int> in;

void input(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>h[i];
        in.push_back(i);
    }
}
void split(){
    for(int i=0; i<n; i++){
        int ht = h[i];
        for(int j=21; ht && j>=0; j--){
            hb[i][j] = ht%2;
            mb = (hb[i][j]&&mb>j)?j:mb;
            bc[j] += hb[i][j];
            ht/=2;
        }
    }
}
bool bitCheck(int pos){
    int bitcount=0;
    vector<int> tmpv;
    for(auto i:in){
        if(hb[i][pos]){
            tmpv.push_back(i);
            bitcount++;
        }
    }
    if(bitcount>=k)
        swap(in, tmpv);
    if(bitcount==k)
        return true;
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    input();
    split();
    int i=0;
    while(i<=21 && !bitCheck(i++));
    int b = 2097151;
    if(in.size()==k){
        for(auto j:in){
            b&=h[j];
        }
        cout<<b;
    }
    else if(in.size()<k){
        for(auto i:in){
            cout<<i<<' ';
        }
    }
    else{
        for(int i=0; i<k; i++){
            b&=h[in[i]];
        }
        cout<<b;
    }

    return 0;
}
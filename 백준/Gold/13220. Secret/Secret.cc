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

int n, loop[200009], sec[100009], key[100009];

void mK(){
    int v=0;
    for(int i=1; i<n; i++){
        while(v && sec[i]!=sec[v]){
            v = key[v-1];
        }
        if(sec[i] == sec[v]){
            key[i] = ++v;
        }
    }
}

bool kmp(){
    int v=0;
    for(int i=0; i<n*2; i++){
        while(v && loop[i]!=sec[v]){
            v = key[v-1];
        }
        if(loop[i] == sec[v]){
            v++;
            if(v==n){
                return true;
            }
        }
        // cout<<loop[i]<<' '<<v<<endl;
    }
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);


    cin>>n;
    for(int i=0; i<n; i++){
        cin>>loop[i];
        loop[i+n] = loop[i];
    }
    for(int i=0; i<n; i++){
        cin>>sec[i];
    }
    mK();

    cout<<(kmp()?"YES":"NO");

    return 0;
}
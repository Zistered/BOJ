#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <string.h>

using namespace std;

enum Alp{
    A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z
};

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t;
    cin>>t;
    for(int c=1; c<=t; c++){
        cout<<"Case #"<<c<<": ";
        string s;
        int alp[26]={0}, num[10]={0};
        cin>>s;
        for(auto i:s){
            alp[i-'A']++;
        }
        while(alp[Z])   num[0]++,alp[Z]--,alp[E]--,alp[R]--,alp[O]--;
        while(alp[G])   num[8]++,alp[E]--,alp[I]--,alp[G]--,alp[H]--,alp[T]--;
        while(alp[X])   num[6]++,alp[S]--,alp[I]--,alp[X]--;
        while(alp[W])   num[2]++,alp[T]--,alp[W]--,alp[O]--;
        while(alp[S])   num[7]++,alp[S]--,alp[E]--,alp[V]--,alp[E]--,alp[N]--;
        while(alp[V])   num[5]++,alp[F]--,alp[I]--,alp[V]--,alp[E]--;
        while(alp[U])   num[4]++,alp[F]--,alp[O]--,alp[U]--,alp[R]--;
        while(alp[R])   num[3]++,alp[T]--,alp[H]--,alp[R]--,alp[E]--,alp[E]--;
        while(alp[O])   num[1]++,alp[O]--,alp[N]--,alp[E]--;
        num[9]+=alp[E];
        for(int i=0; i<=9; i++){
            if(num[i]) cout<<string(num[i],'0'+i);
        }
        cout<<'\n';
    }

    return 0;
}
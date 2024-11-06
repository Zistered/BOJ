#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    long long int d,p,q, pc=0, mn, od;
    cin>>d>>p>>q;
    od = d;
    if(p<q) swap(p,q);
    if(p%q==0){
        mn = q*(d/q+!!(d%q));
        goto superexit;
    }
    pc+=d/p+!!(d%p);
    d-=p*pc;
    mn = p*pc;
    while(pc--){
        d+=p;
        int t=p*pc+q*(d/q+!!(d%q));
        if(mn>t) mn = t;
        else if(mn==t) break;
        if(mn==od) break;
    }
superexit:
    cout<<mn;
    return 0;
}
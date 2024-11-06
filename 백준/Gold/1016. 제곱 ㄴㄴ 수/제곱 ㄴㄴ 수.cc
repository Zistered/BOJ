#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <string.h>

using namespace std;

bool che[1001001];

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    long long minn, maxx;
    cin>>minn>>maxx;
    for(long long i=2; i*i<=maxx; i++){
        for(long long j=((i*i)*(minn/(i*i))); j<=maxx; j+=i*i){
            //cout<<i<<' '<<j<<' '<<((i*i)*(minn/(i*i)))<<'\n';
            if(j<minn) continue;
            che[j-minn] = true;
        }
    }
    long long count=0, dif=maxx-minn;
    for(long long i=0; i<=dif; i++){
        if(!che[i]) count++;
    }
    cout<<count;

    return 0;
}
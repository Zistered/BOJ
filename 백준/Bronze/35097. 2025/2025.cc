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

void tc(int n){
    long long k=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            k+=i*j;
        }
    }
    cout<<k<<'\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    while(cin>>n && n){
        tc(n);
    }
}
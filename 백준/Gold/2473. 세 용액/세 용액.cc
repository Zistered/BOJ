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

long long n, 용액[100009], dif=4000000004;
long long dab[3];

void solve(long long k){
    if(k>=2){
        long long mix = 용액[k]+용액[k-1]+용액[k-2];
        long long absmix = mix<0?-mix:mix;
        if(absmix<dif){
            dif = absmix;
            dab[0] = 용액[k-2];
            dab[1] = 용액[k-1];
            dab[2] = 용액[k];
        }
    }
    if(k<n-2){
        long long mix = 용액[k]+용액[k+1]+용액[k+2];
        long long absmix = mix<0?-mix:mix;
        if(absmix<dif){
            dif = absmix;
            dab[0] = 용액[k];
            dab[1] = 용액[k+1];
            dab[2] = 용액[k+2];
        }
    }
    if(k>=1 && k<n-1){
        long long left = k-1, right = k+1;
        while(left>=0 && right<n){
            long long mix = 용액[k]+용액[left]+용액[right];
            long long absmix = mix<0?-mix:mix;
            if(absmix<dif){
                dif = absmix;
                dab[0] = 용액[left];
                dab[1] = 용액[k];
                dab[2] = 용액[right];
            }
            if(mix==0){
                goto zerocutzz;
            }
            if(mix<0){
                right++;
            }
            else{
                left--;
            }
        }
    }
zerocutzz:
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>n;
    for(long long i=0; i<n; i++){
        cin>>용액[i];
    }
    sort(용액, 용액+n);

    for(long long i=0; i<n; i++){
        solve(i);
    }
    for(long long i:dab){
        cout<<i<<' ';
    }
    
    return 0;
}

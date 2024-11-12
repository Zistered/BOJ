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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    long long n, 용액[100009], dif=2000000000;
    int dab[2], zero=0, same=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>용액[i];
        if(용액[i]==0) zero=1;
        if(용액[i]>0) same++;
        if(same==2){
            if(zero){ // -2 -1 0 1 2  -4 -3 -2 -1 0
                if(i>=4){
                    dif = abs(용액[i-4]+용액[i-3]);
                    dab[0] = 용액[i-4];
                    dab[1] = 용액[i-3];
                }
                if(i>=3 && dif>abs(용액[i-3]+용액[i-2])){
                    dif = abs(용액[i-3]+용액[i-2]);
                    dab[0] = 용액[i-3];
                    dab[1] = 용액[i-2];
                }
                if(i>=2 && dif>abs(용액[i-2]+용액[i-1])){
                    dif = abs(용액[i-2]+용액[i-1]);
                    dab[0] = 용액[i-2];
                    dab[1] = 용액[i-1];
                }
                if(i>=1 && dif>abs(용액[i-1]+용액[i])){
                    dif = abs(용액[i-1]+용액[i]);
                    dab[0] = 용액[i-1];
                    dab[1] = 용액[i-0];
                }
            }
            else{
                if(i>=3 && dif>abs(용액[i-3]+용액[i-2])){
                    dif = abs(용액[i-3]+용액[i-2]);
                    dab[0] = 용액[i-3];
                    dab[1] = 용액[i-2];
                }
                if(i>=1 && dif>abs(용액[i-1]+용액[i])){
                    dif = abs(용액[i-1]+용액[i]);
                    dab[0] = 용액[i-1];
                    dab[1] = 용액[i-0];
                }
            }
        }
    }
    int left = 0, right = n-1;
    while(left<right){
        long long mix = 용액[left]+용액[right];
        long long absmix = abs(mix);
        if(absmix<dif){
            dif = absmix;
            dab[0] = 용액[left];
            dab[1] = 용액[right];
        }
        if(mix<0) left++;
        else right--;
    }
    cout<<dab[0]<<' '<<dab[1];
    return 0;
}

// -9 -8 -7 -6 -5 -4 -3 -2 -1 99
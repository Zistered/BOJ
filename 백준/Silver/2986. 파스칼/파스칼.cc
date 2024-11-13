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

    int n;
    cin>>n;
    for(int i=2; i<44444 && i<n; i++){
        if(n%i==0){
            cout<<n-n/i;
            return 0;
        }
    }
    cout<<n-1;
    return 0;
}
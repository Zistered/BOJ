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
    int a[1000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int k;
    cin>>k>>k;
    int v;
    cin>>v;
    for(int i=0; i<v; i++){
        int vv;
        cin>>vv;
        while(vv--){
            int n;
            cin>>n;
            a[n]++;
        }
    }
    if(a[k]==v){
        cout<<"YES";
    }else cout<<"NO";
    
    return 0;
}
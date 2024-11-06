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

    int n, h, m, x=0;
    cin>>n;
    int t[1440]={0};
    char _;
    while(cin>>h>>_>>m){
        t[h*60+m]++;
    }
    for(int i=0; i<1440; i++){
        if(t[i]){
            x++;
            i+=20;
        }
    }
    cout<<x;

    return 0;
}
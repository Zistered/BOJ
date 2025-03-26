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

int x[55], y[55], q, w;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n,m;
    cin>>n>>m;
    char c;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>c;
            if(c=='X'){
                x[j] = 1;
                y[i] = 1;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(y[i]) q++;
    }
    for(int j=0; j<m; j++){
        if(x[j]) w++;
    }
    cout<<(((n-q)>(m-w))?(n-q):(m-w));

    return 0;
}
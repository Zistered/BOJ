#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <string.h>

using namespace std;

long long 그거[100001], mx, cnt, db;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        if(그거[m] && (!db || db>m)){
            db=m;
        }
        그거[m]++;
        m>mx?mx=m:0;
    }
    for(int i=1; i<mx; i++){
        for(;그거[db]<2||db<=i;db++);
        if(!그거[i]){
            for(int j=db; j<=mx; j++){
                if(그거[j]>=2){
                    그거[j]--;
                    그거[i]++;
                    for(;그거[db]<2&&db<=mx;db++);
                    cnt+=j-i;
                    break;
                }
            }
            if(!그거[i]){
                그거[mx]--;
                그거[i]++;
                cnt+=mx-i;
                for(;!그거[mx];mx--);
            }
        }
    }
    cout<<cnt;

    return 0;
}
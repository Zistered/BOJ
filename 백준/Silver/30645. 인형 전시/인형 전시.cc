#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include <unistd.h>
#include <limits.h>

using namespace std;



int main(){
    cin.tie(0)->sync_with_stdio(0);

    int r, c, n, k, view[1001] = {0}, cur = 0, look = 0;
    cin>>r>>c;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(cin>>k) pq.push(k);

    while(!pq.empty()){
        int t = pq.top();
        pq.pop();
        if(view[cur]<t){
            look++;
            view[cur++] = t;
            if(cur>=c){
                cur = 0;
                r--;
                if(r==0){
                    break;
                }
            }
        }
    }
    cout<<look;

    return 0;
}
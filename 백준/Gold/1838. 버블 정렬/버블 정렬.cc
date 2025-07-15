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

    int n;
    cin>>n;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        pq.push({k, i});
    }
    int x=0;
    for(int i=0; i<n; i++){
        if(pq.top().second-i>0)
            x = max(x, pq.top().second-i);
        pq.pop();
    }
    cout<<x;

    return 0;
}
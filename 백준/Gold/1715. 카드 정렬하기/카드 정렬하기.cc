#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <string.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    priority_queue<int,vector<int>,greater<int>>pq;
    int n, cnt=0;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    while(cin>>n){
        pq.push(n);
    }
    while(pq.size()>2){
        int a=pq.top();
        pq.pop();
        a+=pq.top();
        cnt+=a;
        pq.pop();
        pq.push(a);
    }
    int a=pq.top();
    pq.pop();
    cout<<cnt+a+pq.top();
    return 0;
}
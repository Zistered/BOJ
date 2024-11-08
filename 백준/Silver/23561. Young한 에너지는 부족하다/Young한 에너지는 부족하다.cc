#include <queue>
#include <math.h>
#include <iostream>

using namespace std;

int main(){
    priority_queue<int, vector<int>, less<int>> pq;
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        pq.push(k);
    }
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        pq.push(k);
    }
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        pq.push(k);
    }
    for(int i=0; i<n; i++){
        pq.pop();
    }
    int a=pq.top();
    for(int i=0; i<n-1; i++){
        pq.pop();
    }
    int b = pq.top();
    cout<<abs(a-b);
}
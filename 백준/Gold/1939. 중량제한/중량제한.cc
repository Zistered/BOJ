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

vector<pair<int,int>> zelda[10002];
int dp[10002];
int n, m;
bool comp[10002];
int s, e;

priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq; //first==값, second==노드

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        zelda[a].push_back({c, b});
        zelda[b].push_back({c, a});
    }
    cin>>s>>e;
    for(auto i:zelda[s]){
        pq.push(i);
        dp[i.second] = max(i.first, dp[i.second]);
    }
    comp[s] = true;
    while(!pq.empty()){
        int val = pq.top().first, now = pq.top().second;
        pq.pop();
        if(comp[now]){
            continue;
        }
        comp[now] = true;

        if(now==e) break;

        for(auto i:zelda[now]){
            if(dp[i.second] < min(dp[now],i.first)){
                dp[i.second] = min(dp[now],i.first);
                pq.push(i);
            }
        }
    }
    cout<<dp[e]<<endl;


    return 0;
}
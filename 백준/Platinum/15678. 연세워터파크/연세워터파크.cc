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

int n, d;
long long mx=-1111111111, dari;
priority_queue<pair<long long,long long>, vector<pair<long long,long long>>> pq;

void test(){ //우선순위큐 쓰는거 되게헷갈리네 ㅋㅋ
    pq.push({1,3});
    pq.push({3,2});
    pq.push({2,1});
    pair<long long,long long> pp = pq.top();
    cout<<pp.first<<' '<<pp.second;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>d;
    for(int i=0; i<n; i++){
        cin>>dari;
        while(!pq.empty() && pq.top().second < i-d){
            pq.pop();
        }
        if(!pq.empty() && pq.top().first > 0){
            dari += pq.top().first;
        }
        pq.push({dari, i});
        mx = max(mx, pq.top().first);
    }
    cout<<mx;
    //test();

}
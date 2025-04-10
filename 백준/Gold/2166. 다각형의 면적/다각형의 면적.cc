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

struct pos{
    long long x;
    long long y;
};

queue<pos> q;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    while(n--){
        pos p;
        cin>>p.x>>p.y;
        q.push(p);
    }
    q.push(q.front());
    pos now=q.front();
    q.pop();
    long double mj=0;
    while(!q.empty()){
        mj+=now.x*q.front().y;
        mj-=now.y*q.front().x;
        now=q.front();
        q.pop();
    }
    printf("%.1Lf", abs(mj/2.0));

    return 0;
}
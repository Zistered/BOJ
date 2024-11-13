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

    int n;
    cin>>n;
    queue<int> q,w;
    int i=0;
    for(; i<n/2; i++){
        q.push(i+1);
    }
    for(; i<n; i++){
        w.push(i+1);
    }
    while(!q.empty() || !w.empty()){
        if(!w.empty()){
            cout<<w.front()<<' ';
            w.pop();
        }
        if(!q.empty()){
            cout<<q.front()<<' ';
            q.pop();
        }
    }

    return 0;
}
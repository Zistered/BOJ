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

int n;
vector<int> 수열;
bool used[9];

void run(int level){
    if(level==n){
        for(auto i:수열){
            cout<<i<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0; i<n; i++){
        if(!used[i]){
            수열.push_back(i+1);
            used[i] = true;
            run(level+1);
            수열.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>n;
    run(0);

    return 0;
}
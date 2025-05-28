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

long long m, n;
long long shortest[505];
long long shortest2[505];
long long gansun[505][505];
vector<long long> gan[505];

void ford(long long st){
    //cout<<"ford"<<st<<endl;
    for(auto i:gan[st]){
        //cout<<st<<" to "<<i<<", ";
        if(shortest[i]>shortest[st]+gansun[st][i]){
            shortest[i] = shortest[st]+gansun[st][i];
        }
    }
    //cout<<endl;
}

void bellman(){
    for(long long i=1; i<=n; i++){
        if(shortest[i]<LLONG_MAX){
            ford(i);
        }
    }
}

void lastbellmanford(){
    for(long long i=1; i<=n; i++){
        for(auto j:gan[i]){
            if(shortest[i] != LLONG_MAX)
                shortest2[j] = min(shortest[j], shortest[i]+gansun[i][j]);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    fill(&shortest[0], &shortest[0]+505, LLONG_MAX);
    fill(&shortest2[0], &shortest2[0]+505, LLONG_MAX);
    fill(&gansun[0][0], &gansun[0][0]+505*505, LLONG_MAX);
    shortest[1] = 0;

    cin>>n>>m;

    for(long long i=0; i<m; i++){
        long long a,b,c;
        cin>>a>>b>>c;
        gansun[a][b] = min(gansun[a][b], c);
        gan[a].emplace_back(b);
    }

    for(long long i=0; i<=n; i++){
        bellman();
    }
    for(long long i=1; i<=n; i++){
        shortest2[i] = shortest[i];
    }
    bellman();
    bool isInfLoop = false;
    for(long long i=1; i<=n; i++){
        //cout<<shortest[i]<<", "<<shortest2[i]<<endl;
        if(shortest2[i]>shortest[i]){
            isInfLoop = true;
            break;
        }
    }

    if(isInfLoop){
        cout<<-1;
        return 0;
    }

    for(long long i=2; i<=n; i++){
        cout<<(shortest[i]==LLONG_MAX?-1:shortest[i])<<"\n";
    }
}
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

#define intt long long

using namespace std;

void CasE(int TC){
    cout<<"Test case "<<TC<<": ";
    intt n,m,k,cnt=0;
    cin>>n>>m>>k;
    intt city[n+2][m+2]={0};
    intt city2[n+2][m+2]={0};
    for(intt i=0; i<k; i++){
        intt a,b;
        cin>>a>>b;
        city[a][b]++;
        city2[a][b]++;
    }
    // for(int i=1; i<=n; i++){cout<<endl;     // 그냥 다 센거 ㅋㅋ
    //     for(int j=1; j<=m; j++){
    //         cout<<city[i][j]<<" ";
    //         if(city[i][j]){
    //             for(int ii=i+1; ii<=n; ii++){
    //                 for(int jj=1; jj<j; jj++){
    //                     cnt+=city[ii][jj];
    //                 }
    //             }
    //         }
    //     }
    // }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            city[i][j+1] += city[i][j];
        }
    }
    for(int i=1; i<=n; i++){ //cout<<endl;
        for(int j=1; j<=m; j++){ //cout<<city[i][j]<<' ';
            if(city2[i][j]){ //cout<<i<<' '<<j<<endl;
                for(int ii=i+1; ii<=n; ii++){
                    cnt+=city[ii][j-1];
                }
            }
        }
    }
    cout<<cnt<<'\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int I;
    cin>>I;
    for(int i=1; i<=I; i++){
        CasE(i);
    }
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>

using namespace std;

int x, y, dsnb, pos, hap;

int cdgr(int d, int p){
    if(d==dsnb){
        int gr = pos-p;
        return gr<0?-gr:gr;
    }
    else if(d+dsnb==3){ //북->남이거나 남->북일때
        int bsg = y+pos+p;
        int sg = y+(x-pos)+(x-p);
        return min(sg, bsg);
    }
    else if(d+dsnb==7){ //동->서거나 서->동일때
        int bsg = x+pos+p;
        int sg = x+(y-pos)+(y-p);
        return min(sg, bsg);
    }
    switch(dsnb){
    case 1: //동근이가 북쪽 동==pos
        switch(d){
            case 3: //북->서
                return pos+p;
            case 4: //북->동
                return x-pos+p;
        }
        break;
    case 2: //동근이가 남쪽
        switch(d){
            case 3: //남->서
                return pos+y-p;
            case 4: //남->동
                return x-pos+y-p;
        }
        break;
    case 3: //동근이가 서쪽
        switch(d){
            case 1: //서->북
                return pos+p;
            case 2: //서->남
                return y-pos+p;
        }
        break;
    case 4: //동근이가 동쪽
        switch(d){
            case 1: //동->북
                return pos+x-p;
            case 2: //동->남
                return y-pos+x-p;
        }
        break;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>x>>y;
    int shop;
    cin>>shop;
    vector<pair<int, int>> v;
    while(shop--){
        int d, p;
        cin>>d>>p;
        v.push_back({d, p});
    }
    cin>>dsnb>>pos;
    for(auto i:v){
        hap+=cdgr(i.first, i.second);
    }
    cout<<hap;

    return 0;
}
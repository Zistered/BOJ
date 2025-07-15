#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include <unistd.h>
#include <limits.h>

using namespace std;

vector<int> KEY(string s){
    int l = s.length();
    vector<int> key(l, 0);
    for(int i=1, j=0; i<l; i++){
        while(j>0 && s[i]!=s[j]) j = key[j-1];
        if(s[i]==s[j]){
            key[i] = ++j;
        }
    }
    return key;
}

int FIND(string s, string p){
    int sl = s.length()-1, pl = p.length();
    int cnt=0;
    auto key = KEY(p);
    for(int i=0, j=0; i<sl; i++){
        while(j>0 && s[i]!=p[j]) j = key[j-1];
        if(s[i]==p[j]){
            j++;
            if(pl==j){
                cnt++;
                j = key[j-1];
            }
        }
    }
    return cnt;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    // for(auto i:KEY("ABAABA")) cout<<i<<' '; return 0;

    string a,b,a_;
    cin>>a>>b;
    b+=b;
    //b에서a찾기
    cout<<FIND(b, a);

    return 0;
}
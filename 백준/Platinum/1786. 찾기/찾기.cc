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

vector<int> v;

vector<int> KEY(string s){
    vector<int> key(s.length(), 0);

    for(int i=1, j=0; i<s.length(); i++){
        while(j>0 && s[i]!=s[j]) j = key[j-1];
        if(s[i]==s[j]){
            j++;
            key[i] = j;
        }
    }

    return key;
}

int FIND(string s, string p){
    int cnt=0;
    auto key = KEY(p);

    for(int i=0, j=0; i<s.length(); i++){
        while(j>0 && s[i]!=p[j]) j = key[j-1];
        if(s[i]==p[j]){
            j++;
            if(j==p.length()){
                cnt++;
                v.emplace_back(i-j+2);
                j = key[j-1];
            }
        }
    }

    return cnt;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    string a, b;
    getline(cin, a);
    getline(cin, b);

    cout<<FIND(a, b)<<'\n';
    for(auto i:v) cout<<i<<' ';

    return 0;
}
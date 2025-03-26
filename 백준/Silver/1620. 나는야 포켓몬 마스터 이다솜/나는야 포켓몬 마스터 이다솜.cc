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

    vector<string> dict;
    vector<pair<string, int>> v[1000];
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        dict.emplace_back(s);
        int c=0;
        for(auto j:s){
            c+=j;
        }
        v[c%1000].push_back({s, i});
        //cout<<s<<endl;
    }
    while(m--){
        string s;
        cin>>s;
        if(s[0]<='9' && s[0]>='0'){
            int k = atoi(s.c_str());
            cout<<dict[k-1]<<'\n';
        }
        else{
            int c=0;
            for(auto j:s){
                c+=j;
            }
            for(auto i:v[c%1000]){
                if(i.first==s){
                    cout<<i.second<<'\n';
                    break;
                }
            }
        }
    }

    return 0;
}
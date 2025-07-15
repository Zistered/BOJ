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

vector<int> MakeKey(string s){
    vector<int> v(s.length(), 0);
    for(int i=1, j=0; i<s.length(); i++){
        while(j>0 && s[i]!=s[j]) j = v[j-1];
        if(s[i]==s[j]){
            v[i] = ++j;
        }
    }
    return v;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin>>s;
    vector<int> mv;
    for(int i=0; i<s.length()-2; i++){
        auto v = MakeKey(&s[i]);
        mv.emplace_back(*max_element(v.begin(), v.end()));
    }
    cout<<*max_element(mv.begin(), mv.end());

    return 0;
}
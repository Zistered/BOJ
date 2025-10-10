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

unsigned long long km(string s){
    unsigned long long n=0, l=s.length(), c=0;
    vector<int> v(l,0);
    if(l==1) return 0;
    for(int i=1; i<l; i++){
        // cout<<s[i]<<" vs "<<s[c]<<": "<<i<<endl;
        while(c && s[i]!=s[c]){
            c = v[c-1];
        }
        if(s[i]==s[c]){
            v[i] = ++c;
        }
    }
    return c;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    string s;
    unsigned long long k;
    cin>>s>>k;
    unsigned long long ruq=km(s), l=s.length();
    cout<<(l-ruq)*(k-1)+l;
}
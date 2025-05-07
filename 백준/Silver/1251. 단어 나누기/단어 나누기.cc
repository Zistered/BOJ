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

priority_queue<string, vector<string>,greater<string>> pq;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin>>s;

    int sl=s.length();
    for(int i=0; i<sl-2; i++){
        for(int j=i+1; j<sl-1; j++){
            string a,b,c;
            int k=0;
            for(;k<=i;k++){
                a+=s[k];
            }
            for(;k<=j;k++){
                b+=s[k];
            }
            for(;k<sl;k++){
                c+=s[k];
            }
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());
            reverse(c.begin(),c.end());
            pq.push(a+b+c);
        }
    }
    cout<<pq.top();

    return 0;
}
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

    int n;
    cin>>n;
    while(n--){
        string s;
        int a, b;
        cin>>s>>a>>b;
        b--;
        for(int i=0; i<s.length(); i++){
            if(i>=a && i<=b) continue;
            else cout<<s[i];
        }
        cout<<'\n';
    }

    return 0;
}
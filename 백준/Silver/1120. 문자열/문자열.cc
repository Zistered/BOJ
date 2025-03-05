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

    string sh, lo;
    cin>>sh>>lo;
    if(sh.length() > lo.length()) swap(sh, lo);

    int k=lo.length()-sh.length(), gdif=9999;
    for(int i=0; i<=k; i++){
        int j=0, dif=0;
        for(auto s:sh){
            if(s!=lo[j+i]) dif++;
            //cout<<s<<'&'<<lo[j+i]<<'\n';
            j++;
        }
        gdif = min(dif, gdif);
        //cout<<dif<<' ';
    }
    cout<<gdif;

    return 0;
}
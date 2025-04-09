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
int num[103]={0,1,1,1,1,1,1,1,1,1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for(int i=2; i<=9; i++){
        for(int j=1; j<=9; j++){
            num[i*j]=1;
        }
    }
    int n;
    cin>>n;
    cout<<num[n];

    return 0;
}
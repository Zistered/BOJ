#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <string.h>

using namespace std;

int 풍[1001001], 수;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        if(풍[m]){
            풍[m]--;
            풍[m-1]++;
        }
        else{
            풍[m-1]++;
            수++;
        }
    }
    cout<<수;

    return 0;
}
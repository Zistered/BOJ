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
// 00 01 02 03 04 12 13 14 23 24 34
//  0  1  2  3  4  5  6  7  8  9 10

int dp[100009][32];
int looplist[] = {0b00000, 0b00001, 0b00010, 0b00100, 0b01000, 0b00011, 0b00101, 0b01001, 0b00110, 0b01010, 0b01100};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int k, n=0;
    //cout<<(0b10101|0b01010); //01234
    while(cin>>k){
        if(k==0){
            int mini = 99999999;
            for(int i=1; i<0b11001; i++){
                if(dp[n][i]) mini = mini<dp[n][i]?mini:dp[n][i];
            }
            cout<<mini;
            // for(int i=0; i<=n; i++){
            //     for(int j:looplist){
            //         cout<<j<<":"<<dp[i][j]<<" / ";
            //     }cout<<endl;
            // }
            break;
        }
        switch(k){
        case 1:
            k = 0b01000;
            break;
        case 2:
            k = 0b00100;
            break;
        case 3:
            k = 0b00010;
            break;
        case 4:
            k = 0b00001;
            break;
        }
        if(n++==0){
            dp[n][k] = 2;
            continue;
        }
        for(int i=1; i<0b11001; i++){
            if(!dp[n-1][i]) continue;
            int left, right; //left가 작은거
            for(int j=1; j<0b10001; j*=2){
                if(i&j){
                    right = i-j;
                    left = j;
                    break;
                }
            }
            if(k==left || k==right){
                if(!dp[n][i]) dp[n][i] = 99999999;
                dp[n][i] = min(dp[n-1][i]+1, dp[n][i]);
                continue;
            }
            {//move left
                int sm = min(k,left);
                int bg = max(k,left);
                if(!dp[n][i-left+k]) dp[n][i-left+k] = 99999999;
                if(sm*4==bg){
                    dp[n][i-left+k] = min(dp[n-1][i]+4, dp[n][i-left+k]);
                }
                else{
                    dp[n][i-left+k] = min(dp[n-1][i]+3, dp[n][i-left+k]);
                }
            }
            {//move right
                int sm = min(k,right);
                int bg = max(k,right);
                if(!dp[n][i-right+k]) dp[n][i-right+k] = 99999999;
                if(right==0){
                    dp[n][i-right+k] = min(dp[n-1][i]+2, dp[n][i-right+k]);
                }
                else if(sm*4==bg){
                    dp[n][i-right+k] = min(dp[n-1][i]+4, dp[n][i-right+k]);
                }
                else{
                    dp[n][i-right+k] = min(dp[n-1][i]+3, dp[n][i-right+k]);
                }
            }
        }
    }

    return 0;
}
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

#define idk 4

using namespace std;

char bd[9999][9999]={0};
int cnt, xx, yy;

void LU(int x, int y){
    if(x<3 || y<3) return;
    if(bd[y][x]=='w' && bd[y-1][x-1]=='o' && bd[y-2][x-2]=='r' && bd[y-3][x-3]=='d') cnt++;
}

void L(int x, int y){
    if(x<3) return;
    if(bd[y][x]=='w' && bd[y][x-1]=='o' && bd[y][x-2]=='r' && bd[y][x-3]=='d') cnt++;
}

void LD(int x, int y){
    if(x<3 || y>yy-idk) return;
    if(bd[y][x]=='w' && bd[y+1][x-1]=='o' && bd[y+2][x-2]=='r' && bd[y+3][x-3]=='d') cnt++;
}

void D(int x, int y){
    if(y>yy-idk) return;
    if(bd[y][x]=='w' && bd[y+1][x]=='o' && bd[y+2][x]=='r' && bd[y+3][x]=='d') cnt++;
}

void RD(int x, int y){
    if(x>xx-idk || y>yy-idk) return;
    if(bd[y][x]=='w' && bd[y+1][x+1]=='o' && bd[y+2][x+2]=='r' && bd[y+3][x+3]=='d') cnt++;
}

void R(int x, int y){
    if(x>xx-idk) return;
    if(bd[y][x]=='w' && bd[y][x+1]=='o' && bd[y][x+2]=='r' && bd[y][x+3]=='d') cnt++;
}

void RU(int x, int y){
    if(x>xx-idk || y<3) return;
    if(bd[y][x]=='w' && bd[y-1][x+1]=='o' && bd[y-2][x+2]=='r' && bd[y-3][x+3]=='d') cnt++;
}

void U(int x, int y){
    if(y<3) return;
    if(bd[y][x]=='w' && bd[y-1][x]=='o' && bd[y-2][x]=='r' && bd[y-3][x]=='d') cnt++;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    while(n--){
        cnt=0;
        cin>>xx>>yy;
        for(int i=0; i<yy; i++){
            for(int j=0; j<xx; j++){
                cin>>bd[j][i];
            }
        }

        for(int i=0; i<yy; i++){
            for(int j=0; j<xx; j++){
                LU(j, i);
                L(j, i);
                LD(j, i);
                D(j, i);
                RD(j, i);
                R(j, i);
                RU(j, i);
                U(j, i);
            }
        }
        cout<<cnt<<'\n';
    }

    return 0;
}
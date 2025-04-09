#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct pos{
    int x;
    int y;
};

int 가, 세, 상자[2001][1221], 남은=0, 단계=0;
queue<pos> 토마토;

void 익어(pos);

void pm(){
    printf("\n==========\n");
    for(int i=0; i<세; i++){
        for(int j=0; j<가; j++){
            printf("%2d", 상자[i][j]);
        }
        printf("\n");
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin>>가>>세;
    for(int i=0; i<세; i++){
        for(int j=0; j<가; j++){
            cin>>상자[i][j];
            if(상자[i][j]==1){
                토마토.push({j,i});
            }
            else if(상자[i][j]==0){
                남은++;
            }
        }
    }
    while(!토마토.empty() && 남은){
        int 토수 = 토마토.size();
        while(토수--){
            익어(토마토.front());
            토마토.pop();
        }
        단계++;
        //pm();
    }
    if(남은){
        cout<<-1;
    }
    else{
        cout<<단계;
    }
    return 0;
}

void 익어(pos now){
    int xx[] = { 1,-1, 0, 0};
    int yy[] = { 0, 0, 1,-1};
    for(int i=0; i<4; i++){
        int nx = now.x+xx[i], ny = now.y+yy[i];
        if(nx>=0 && nx<가 && ny>=0 && ny<세 && 상자[ny][nx]==0){
            상자[ny][nx]++;
            남은--;
            토마토.push({nx,ny});
        }
    }
}
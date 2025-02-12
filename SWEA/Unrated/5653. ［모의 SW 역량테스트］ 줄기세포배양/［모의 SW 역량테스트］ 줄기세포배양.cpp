#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>

using namespace std;

enum State {CELL_EMPTY, CELL_INACTIVE, CELL_ACTIVE, CELL_DEAD};

struct Cell{
    State state = CELL_EMPTY;
    int maxhp;
    int hp;
};

struct Pos{
    int x;
    int y;
};

Cell paper[1000][1000];

void paperClear(){
    memset(&paper[0][0], 0, sizeof(paper));
}

int testCase();

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    for(int i=1; i<=T; i++){
        cout<<'#'<<i<<' '<<testCase()<<'\n';
    }
    return 0;
}

void testPrint(){
    for(int i=494; i<508; i++){
        for(int j=494; j<508; j++){
            switch(paper[i][j].state){
            case CELL_EMPTY:
                cout<<"  ";
                break;
            case CELL_ACTIVE:
                cout<<"Q ";
                break;
            case CELL_INACTIVE:
                //cout<<"O ";
                cout<<paper[i][j].maxhp<<' ';
                break;
            case CELL_DEAD:
                cout<<"- ";
                break;
            }
        }
        cout<<endl;
    }
    cout<<"------------------------\n";
}

int testCase(){
    paperClear();
    int x, y, time;
    cin>>y>>x>>time;
    queue<Pos> inac, ac;
    for(int i=0; i<y; i++){ // 처음 세포 위치 입력받기
        for(int j=0; j<x; j++){
            int n;
            cin>>n;
            if(n){
                paper[i+500][j+500].state = CELL_INACTIVE;
                paper[i+500][j+500].maxhp = paper[i+500][j+500].hp = n;
                inac.push({j+500, i+500});
            }
        }
    }
    while(time--){ // 시간 지나는거
        queue<Pos> inac2, ac2;
        while(!inac.empty()){   // 비활성 피(카운트)깎기
            Pos now = inac.front();
            inac.pop();
            paper[now.y][now.x].hp--;
            if(paper[now.y][now.x].hp<=0){ // 카운트 완료됐으면 활성화
                paper[now.y][now.x].state = CELL_ACTIVE;
                paper[now.y][now.x].hp = paper[now.y][now.x].maxhp;
                ac2.push(now);
            }
            else{
                inac2.push(now);  // 카운트 완료 안됐으면 2번에 저장
            }
        }
        swap(inac, inac2);

        while(!ac.empty()){ // 활성화(살아있는거) 피 깎기
            Pos now = ac.front();
            ac.pop();
            paper[now.y][now.x].hp--;
            int xx[4]={-1,1,0,0}, yy[4]={0,0,-1,1};
            for(int i=0; i<4; i++){
                if(paper[now.y+yy[i]][now.x+xx[i]].state == CELL_EMPTY){
                    // 빈 칸인 경우 
                    paper[now.y+yy[i]][now.x+xx[i]].state = CELL_INACTIVE;
                    inac.push({now.x+xx[i], now.y+yy[i]});
                    paper[now.y+yy[i]][now.x+xx[i]].maxhp = paper[now.y+yy[i]][now.x+xx[i]].hp = paper[now.y][now.x].maxhp;
                }
                else if(paper[now.y+yy[i]][now.x+xx[i]].state==CELL_INACTIVE && paper[now.y+yy[i]][now.x+xx[i]].hp==paper[now.y+yy[i]][now.x+xx[i]].maxhp && paper[now.y+yy[i]][now.x+xx[i]].maxhp<paper[now.y][now.x].maxhp){
                    // 비활성화인데 풀피(방금생김)이고 숫자가 작은 칸인 경우 숫자만 갱신
                    paper[now.y+yy[i]][now.x+xx[i]].maxhp = paper[now.y+yy[i]][now.x+xx[i]].hp = paper[now.y][now.x].maxhp;
                }
            }
            if(paper[now.y][now.x].hp<=0){
                paper[now.y][now.x].state = CELL_DEAD;
            }
            else{
                ac2.push(now);  // 아직도 살아있으면 2번에 저장: 1번은 다 비울때까지 돌아야되니까~
            }
        }
        swap(ac,ac2);   // 아직도 살아있는것들 다시 active에 넣어주기

        //testPrint();
    }
    return inac.size()+ac.size();
}
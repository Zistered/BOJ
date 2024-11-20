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

#define LIM 11
#define TEST false

struct pos{
    int x;
    int y;
};

struct beads{ // 비즈 스펠링이 bead였음ㅋㅋㅋㅋ biz인줄
    pos r;//ed
    pos b;//lue
};

void printbeads(pos r, pos b){
    cout<<"Red: "<<r.x<<','<<r.y<<" & Blue: "<<b.x<<','<<b.y<<endl;
}

int n, m, escape=LIM;
char 보드[12][12];
vector<beads> vstd;
vector<char> road;

void up(pos, pos, int);
void down(pos, pos, int);
void left(pos, pos, int);
void right(pos, pos, int);

void printroad(){
    if(!TEST) return;
    for(auto i:road){
        cout<<i;
    }
    cout<<endl;
}

bool sameBeads(beads log, pos r, pos b){
    if(log.r.x == r.x && log.r.y == r.y && log.b.x == b.x && log.b.y == b.y){
        return true;
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    pos r, b;
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>보드[i][j];
            if(보드[i][j]=='R'){
                보드[i][j] = '.';
                r = {j, i};
            }
            if(보드[i][j]=='B'){
                보드[i][j] = '.';
                b = {j, i};
            }
        }
    }
    up(r, b, 1);
    left(r, b, 1);
    down(r, b, 1);
    right(r, b, 1);

    cout<<(escape==LIM?0:1);

    return 0;
}

void up(pos r, pos b, int attempt){
    if(attempt>=escape) return;
    // for(beads i:vstd){
    //     if(sameBeads(i, r, b)){
    //         return;
    //     }
    // }
    // vstd.push_back({r, b});
    bool rout = false;
    road.push_back('U');
    printroad();
    if(r.y>b.y){
        //bmove
        while(b.y>0 && 보드[b.y-1][b.x]=='.'){
            b.y--;
        }
        if(보드[b.y-1][b.x]=='O'){
            road.pop_back();
            if(TEST) cout<<"CUT 1\n";
            return;
        }
        //rmove
        while(r.y>0 && 보드[r.y-1][r.x]=='.' && !(r.x==b.x && r.y-1==b.y)){
            r.y--;
        }
        if(보드[r.y-1][r.x]=='O'){
            rout = true;
        }
    }
    else{
        //rmove
        while(r.y>0 && 보드[r.y-1][r.x]=='.'){
            r.y--;
        }
        if(보드[r.y-1][r.x]=='O'){
            r.x = r.y = 0;
            rout = true;
        }
        //bmove
        while(b.y>0 && 보드[b.y-1][b.x]=='.' && !(r.x==b.x && r.y==b.y-1)){
            b.y--;
        }
        if(보드[b.y-1][b.x]=='O'){
            road.pop_back();
            if(TEST) cout<<"CUT 2\n";
            return;
        }
    }

    if(rout){
        escape = escape<attempt?escape:attempt;
        printroad();
        road.pop_back();
        if(TEST) cout<<"CUT 3\n";
        return;
    }
    left(r, b, attempt+1);
    right(r, b, attempt+1);
    //down(r, b, attempt+1);
    road.pop_back();
}

void down(pos r, pos b, int attempt){
    if(attempt>=escape) return;
    bool rout = false;
    road.push_back('D');
    printroad();
    if(r.y<b.y){
        //bmove
        while(b.y+1<n && 보드[b.y+1][b.x]=='.'){
            b.y++;
        }
        if(보드[b.y+1][b.x]=='O'){
            road.pop_back();
            if(TEST) cout<<"CUT 4\n";
            return;
        }
        //rmove
        while(r.y+1<n && 보드[r.y+1][r.x]=='.' && !(r.x==b.x && r.y+1==b.y)){
            r.y++;
        }
        if(보드[r.y+1][r.x]=='O'){
            rout = true;
        }
    }
    else{
        //rmove
        while(r.y+1<n && 보드[r.y+1][r.x]=='.'){
            r.y++;
        }
        if(보드[r.y+1][r.x]=='O'){
            r.x = r.y = 0;
            rout = true;
        }
        //bmove
        while(b.y+1<n && 보드[b.y+1][b.x]=='.' && !(r.x==b.x && r.y==b.y+1)){
            b.y++;
        }
        if(보드[b.y+1][b.x]=='O'){
            road.pop_back();
            if(TEST) cout<<"CUT 5\n";
            return;
        }
    }

    if(rout){
        escape = escape<attempt?escape:attempt;
        printroad();
        road.pop_back();
        if(TEST) cout<<"CUT 6\n";
        return;
    }
    left(r, b, attempt+1);
    right(r, b, attempt+1);
    //up(r, b, attempt+1);
    road.pop_back();
}

void left(pos r, pos b, int attempt){
    if(attempt>=escape) return;
    bool rout = false;
    road.push_back('L');
    printroad();
    if(r.x>b.x){
        //bmove
        while(b.x>0 && 보드[b.y][b.x-1]=='.'){
            b.x--;
        }
        if(보드[b.y][b.x-1]=='O'){
            road.pop_back();
            if(TEST) cout<<"CUT 7\n";
            return;
        }
        //rmove
        while(r.x>0 && 보드[r.y][r.x-1]=='.' && !(r.x-1==b.x && r.y==b.y)){
            r.x--;
        }
        if(보드[r.y][r.x-1]=='O'){
            rout = true;
        }
    }
    else{
        //rmove
        while(r.x>0 && 보드[r.y][r.x-1]=='.'){
            r.x--;
        }
        if(보드[r.y][r.x-1]=='O'){
            r.x = r.y = 0;
            rout = true;
        }
        //bmove
        while(b.x>0 && 보드[b.y][b.x-1]=='.' && !(r.x==b.x-1 && r.y==b.y)){
            b.x--;
        }
        if(보드[b.y][b.x-1]=='O'){
            road.pop_back();
            if(TEST) cout<<"CUT 8\n";
            return;
        }
    }

    if(rout){
        escape = escape<attempt?escape:attempt;
        printroad();
        road.pop_back();
        if(TEST) cout<<"CUT 9\n";
        return;
    }
    up(r, b, attempt+1);
    down(r, b, attempt+1);
    //right(r, b, attempt+1);
    road.pop_back();
}

void right(pos r, pos b, int attempt){
    if(attempt>=escape) return;
    bool rout = false;
    road.push_back('R');
    printroad();
    if(r.x<b.x){
        //bmove
        while(b.x+1<m && 보드[b.y][b.x+1]=='.'){
            b.x++;
        }
        if(보드[b.y][b.x+1]=='O'){
            road.pop_back();
            if(TEST) cout<<"CUT 10\n";
            return;
        }
        //rmove
        while(r.x+1<m && 보드[r.y][r.x+1]=='.' && !(r.x+1==b.x && r.y==b.y)){
            r.x++;
        }
        if(보드[r.y][r.x+1]=='O'){
            rout = true;
        }
    }
    else{
        //rmove
        while(r.x+1<m && 보드[r.y][r.x+1]=='.'){
            r.x++;
        }
        if(보드[r.y][r.x+1]=='O'){
            r.x = r.y = 0;
            rout = true;
        }
        //bmove
        while(b.x+1<m && 보드[b.y][b.x+1]=='.' && !(r.x==b.x+1 && r.y==b.y)){
            b.x++;
        }
        if(보드[b.y][b.x+1]=='O'){
            road.pop_back();
            if(TEST) cout<<"CUT 11\n";
            return;
        }
    }

    if(rout){
        escape = escape<attempt?escape:attempt;
        printroad();
        road.pop_back();
        if(TEST) cout<<"CUT 12\n";
        return;
    }
    up(r, b, attempt+1);
    down(r, b, attempt+1);
    //left(r, b, attempt+1);
    road.pop_back();
}
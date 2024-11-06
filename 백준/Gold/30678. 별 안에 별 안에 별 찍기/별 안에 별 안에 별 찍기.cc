#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

string star[6666];

void makestar(int,int,int);

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin>>n;
    int nn = pow(5,n);
    
    for(int i=0; i<nn; i++){
        star[i] = string(nn, ' ');
    }

    if(n==0) cout<<'*';
    else{
        makestar(n,0,0);
    }

    for(int i=0; i<nn; i++){
        cout<<star[i]<<'\n';
    }
    
    return 0;
}

void makestar(int n, int x, int y){
    if(n==1){
        star[y  ][x+2] = '*';
        star[y+1][x+2] = '*';
        star[y+2][x  ] = '*';
        star[y+2][x+1] = '*';
        star[y+2][x+2] = '*';
        star[y+2][x+3] = '*';
        star[y+2][x+4] = '*';
        star[y+3][x+1] = '*';
        star[y+3][x+2] = '*';
        star[y+3][x+3] = '*';
        star[y+4][x+1] = '*';
        star[y+4][x+3] = '*';
    }
    else{
        int nn = pow(5,n-1);
        makestar(n-1,x+nn*2,y     );
        makestar(n-1,x+nn*2,y+nn  );
        makestar(n-1,x,     y+nn*2);
        makestar(n-1,x+nn,  y+nn*2);
        makestar(n-1,x+nn*2,y+nn*2);
        makestar(n-1,x+nn*3,y+nn*2);
        makestar(n-1,x+nn*4,y+nn*2);
        makestar(n-1,x+nn,  y+nn*3);
        makestar(n-1,x+nn*2,y+nn*3);
        makestar(n-1,x+nn*3,y+nn*3);
        makestar(n-1,x+nn,  y+nn*4);
        makestar(n-1,x+nn*3,y+nn*4);
    }
}
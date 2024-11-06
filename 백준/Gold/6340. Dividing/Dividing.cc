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

    int a,b,c,d,e,f,i=0;
    while(cin>>a>>b>>c>>d>>e>>f){
        if(!(a||b||c||d||e||f)) break;
        cout<<"Collection #"<<++i<<":\nCan";
        int value = a+b*2+c*3+d*4+e*5+f*6, big=0;
        bool bag[123456]={0};
        if(value%2) goto no;
        while(a--){
            int mov=1;
            if(!big){
                bag[mov]=true;
                big=mov;
                continue;
            }
            for(int j=big; j>=1; j--){
                if(bag[j] && j+mov<=value/2){
                    bag[j+mov] = true;
                    big=j+mov>big?j+mov:big;
                }
            }
        }
        while(b--){
            int mov=2;
            if(!big){
                bag[mov]=true;
                big=mov;
                continue;
            }
            for(int j=big; j>=1; j--){
                if(bag[j] && j+mov<=value/2){
                    bag[j+mov] = true;
                    big=j+mov>big?j+mov:big;
                }
            }
        }
        while(c--){
            int mov=3;
            if(!big){
                bag[mov]=true;
                big=mov;
                continue;
            }
            for(int j=big; j>=1; j--){
                if(bag[j] && j+mov<=value/2){
                    bag[j+mov] = true;
                    big=j+mov>big?j+mov:big;
                }
            }
        }
        while(d--){
            int mov=4;
            if(!big){
                bag[mov]=true;
                big=mov;
                continue;
            }
            for(int j=big; j>=1; j--){
                if(bag[j] && j+mov<=value/2){
                    bag[j+mov] = true;
                    big=j+mov>big?j+mov:big;
                }
            }
        }
        while(e--){
            int mov=5;
            if(!big){
                bag[mov]=true;
                big=mov;
                continue;
            }
            for(int j=big; j>=1; j--){
                if(bag[j] && j+mov<=value/2){
                    bag[j+mov] = true;
                    big=j+mov>big?j+mov:big;
                }
            }
        }
        while(f--){
            int mov=6;
            if(!big){
                bag[mov]=true;
                big=mov;
                continue;
            }
            for(int j=big; j>=1; j--){
                if(bag[j] && j+mov<=value/2){
                    bag[j+mov] = true;
                    big=j+mov>big?j+mov:big;
                }
            }
        }
        if(bag[value/2]){
            goto yes;
        }
    no:
        cout<<"'t";
    yes:
        cout<<" be divided.\n\n";
    }

    return 0;
}
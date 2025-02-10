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

stack<int> s;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    char c;
    int res=0;
    while(cin>>c){
        int now=0;
        switch(c){
        case '(':
            s.push(-2);
            break;
        case '[':
            s.push(-3);
            break;
        case ')':
            while(!s.empty() && s.top()>0){
                now += s.top();
                s.pop();
            }
            if(s.empty() || s.top()!=-2){
                cout<<0;
                goto superbreak;
            }
            s.pop();
            s.push(now==0?2:now*2);
            break;
        case ']':
            while(!s.empty() && s.top()>0){
                now += s.top();
                s.pop();
            }
            if(s.empty() || s.top()!=-3){
                cout<<0;
                goto superbreak;
            }
            s.pop();
            s.push(now==0?3:now*3);
            break;
        }
    }
    while(!s.empty()){
        //cout<<s.top()<<endl;
        res+=s.top();
        if(s.top()<0){
            cout<<0;
            goto superbreak;
        }
        s.pop();
    }
    cout<<res;
superbreak:
    return 0;
}
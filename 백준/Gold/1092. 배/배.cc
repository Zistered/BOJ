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

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; // 크레인의 수<=50
    int m; // 박스의 수<=10000
    int boxes[55]={0};
    priority_queue<int, vector<int>, greater<int>> crain;
    cin>>n;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        crain.push(k);
    }
    priority_queue<int, vector<int>, greater<int>> box;
    cin>>m;
    for(int i=0; i<m; i++){
        int k;
        cin>>k;
        box.push(k);
    }
    for(int i=0; !crain.empty(); i++){
        //cout<<crain.top()<<": ";
        while(!box.empty() && box.top()<=crain.top()){
            boxes[i]++;
            //cout<<box.top()<<", ";
            box.pop();
        }
        //cout<<endl;
        crain.pop();
    }
    if(!box.empty()){
        cout<<-1;
        return 0;
    }
    // for(int i=0; i<n; i++){
    //     cout<<boxes[i]<<' ';
    // }cout<<endl;
    for(int i=n-1; i>=0; i--){
        while(true){
            int minpos = i;
            for(int j=i+1; j<n; j++){
                if(boxes[j]<boxes[minpos]){
                    minpos = j;
                }
            }
            if(minpos==i) break;
            boxes[i]--;
            boxes[minpos]++;
        }
    }
    int higher = 0;
    for(int i=0; i<n; i++){
        //cout<<boxes[i]<<' ';
        higher = max(higher, boxes[i]);
    }
    cout<<higher;
    return 0;
}

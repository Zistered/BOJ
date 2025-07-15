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

#define test 1

using namespace std;

int n, k, magic;
string s[8];
vector<string> v;
bool vis[8];

void comb();
void chkMagic(string);
int kmp(string);
vector<int> MakeKey(string);

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int i;

    // for(auto i:MakeKey("ABAABA")){
    //     cout<<i<<' ';
    // }return 0;

    cin>>n;
    i = n;
    while(i --> 0){
        cin>>s[i];
        //cout<<"s["<<i<<"] = "<<s[i]<<endl;
    }
    cin>>k;
    comb();
    cout<<magic;
    return 0;
}

void comb(){
    if(v.size()==n){
        string tmp;
        for(int i=0; i<n; i++){
            // cout<<v[i]<<" / ";
            tmp += v[i];
        }
        // cout<<tmp<<endl;
        //chkMagic(tmp);
        if(kmp(tmp)==k){
            magic++;
        }
        return;
    }
    for(int i=0; i<n; i++){
        if(!vis[i]){
            v.emplace_back(s[i]);
            vis[i] = true;
            comb();
            v.pop_back();
            vis[i] = false;
        }
    }
}

int kmp(string now){
    int l = now.length();
    string all = now+now;
    int ll = l*2-1;
    int cnt=0;

    auto key = MakeKey(now);

    int j=0;
    for(int i=0; i<ll; i++){
        while(j>0 && all[i]!=now[j]) j = key[j-1];
        if(all[i]==now[j]){
            j++;
            if(j==l){
                j = key[j-1];
                cnt++;
            }
        }
    }
    return cnt;
}

vector<int> MakeKey(string all){
    int l = all.length();
    vector<int> key(l, 0);

    int j=0;
    for(int i=1; i<l; i++){
        while(j>0 && all[i]!=all[j]) j = key[j-1];
        if(all[i]==all[j]){
            j++;
            key[i] = j;
        }
    }
    return key;
}

void chkMagic(string now){ //kmp안쓴거. 시간초과빡세네
    //cout<<now<<" : ";
    int len = now.length();
    now += now;
    int cnt[202]={0};
    queue<int> reading;
    for(int i=0; i<len; i++){
        reading.push(i);
    } //여기까지 init

    for(int i=0; i<len; i++){
        queue<int> r2;
        while(!reading.empty()){
            int fr = reading.front();
            reading.pop();
            if(now[i]==now[fr+i]){
                r2.push(fr);
            }
        }
        swap(r2, reading);
        if(reading.empty()){
            break;
        }
    }
    if(reading.size()==k) magic++;
    //cout<<reading.size()<<endl;
}
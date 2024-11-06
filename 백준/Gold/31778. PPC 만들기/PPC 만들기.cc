#include <iostream>
#include <algorithm>
#include <vector>

// #define int long long

using namespace std;

string s;
long long n, k, p[200002];
pair<int,int> pc[200002];

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin>>n>>k>>s;

    long long cp=0,pp=s.length()-1;

    while('C'){
        if(s[cp]=='\0'){
            cp=222222;
            break;
        }
        else if(s[cp]=='C'){
            break;
        }
        cp++;
    }
    while('P'){
        if(pp<0 || s[pp]==-1){
            pp=-1;
            break;
        }
        else if(s[pp]=='P'){
            break;
        }
        pp--;
    }
    // cout<<cp<<' '<<pp<<' '<<endl;
    while(k-- && cp<pp){
        swap(s[cp],s[pp]);
        while('C'){
            cp++;
            if(s[cp]=='\0'){
                cp=222222;
                break;
            }
            else if(s[cp]=='C'){
                break;
            }
        }
        while('P'){
            pp--;
            if(pp<0 || s[pp]==-1){
                pp=-1;
                break;
            }
            else if(s[pp]=='P'){
                break;
            }
        }
        // cout<<k<<' '<<cp<<' '<<pp<<'\n';
    }
    // cout<<s;

    long long ccn=0, pcn=0;
    for(long long i=0; i<n; i++){
        if(s[i]=='P'){
            pcn++;
        }
        pc[i].first = pcn;
    }
    for(long long i=n-1; i>=0; i--){
        if(s[i]=='C'){
            ccn++;
        }
        pc[i].second = ccn;
    }

    long long cnt = 0;
    for(long long i=0; i<n; i++){
        // cout<<'{'<<pc[i].first<<' '<<pc[i].second<<"} ";
        if(pc[i].first>=2 && s[i]=='P'){
            cnt+=(long long)pc[i].second*(pc[i].first-1);
        }
    }

    cout<<cnt<<endl;
    return 0;
}
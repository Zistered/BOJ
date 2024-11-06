#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int d[5000005], n, l, ten[500005], hund[50005], thou[5005], tthou[505], hthou[55];
vector<int> v;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n>>l;
    for(int i=0; i<n/10+1; i++){
        ten[i] = 2111111111;
    }
    for(int i=0; i<n/100+1; i++){
        hund[i] = 2111111111;
    }
    for(int i=0; i<n/1000+1; i++){
        thou[i] = 2111111111;
    }
    for(int i=0; i<n/10000+1; i++){
        tthou[i] = 2111111111;
    }
    for(int i=0; i<n/100000+1; i++){
        hthou[i] = 2111111111;
    }
    for(int i=0; i<n; i++){
        cin>>d[i];
        if(ten[i/10]>d[i]) ten[i/10] = d[i];
    }
    for(int i=0; i<n/10; i++){
        if(hund[i/10]>ten[i]) hund[i/10] = ten[i];
    }
    for(int i=0; i<n/100; i++){
        if(thou[i/10]>hund[i]) thou[i/10] = hund[i];
    }
    for(int i=0; i<n/1000; i++){
        if(tthou[i/10]>thou[i]) tthou[i/10] = thou[i];
    }
    for(int i=0; i<n/10000; i++){
        if(hthou[i/10]>tthou[i]) hthou[i/10] = tthou[i];
    }

    for(int i=0; i<n; i++){
        int mn = 2000000000;
        for(int j=(i-l+1>=0?i-l+1:0); j<=i; j++){
            if(j%100000==0 && j+100000<=i){
                if(mn>hthou[j/100000]) mn = hthou[j/100000];
                j+=99999;
            }
            else if(j%10000==0 && j+10000<=i){
                if(mn>tthou[j/10000]) mn = tthou[j/10000];
                j+=9999;
            }
            else if(j%1000==0 && j+1000<=i){
                if(mn>thou[j/1000]) mn = thou[j/1000];
                j+=999;
            }
            else if(j%100==0 && j+100<=i){
                if(mn>hund[j/100]) mn = hund[j/100];
                j+=99;
            }
            else if(j%10==0 && j+10<=i){
                if(mn>ten[j/10]) mn = ten[j/10];
                j+=9;
            }
            else if(mn>d[j]) mn = d[j];
        }
        cout<<mn<<' ';
    }
    return 0;
}
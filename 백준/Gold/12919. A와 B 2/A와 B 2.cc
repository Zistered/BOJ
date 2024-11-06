#include <cstdio>
#include <cstring>

char s[55], t[55];
int sl,tl;

int split(int h, int e, bool rev);

int main() {
    scanf("%s", s);
    scanf("%s", t);
    sl = strlen(s);
    tl = strlen(t);
    printf("%d", split(0, tl-1, false));
    return 0;
}

int split(int h, int e, bool rev)
{
    if(e-h+1<=sl){
        for(int i=0; i<sl; i++){
            if(rev){
                if(t[e-i]!=s[i]){
                    return 0;
                }
            }
            else{
                if(t[i+h]!=s[i]){
                    return 0;
                }
            }
        }
        return 1;
    }
    else{
        if(rev){
            if(t[h]=='A' && t[e]=='B')
                return split(h+1,e,rev)||split(h,e-1,!rev);
            else if(t[h]=='A')
                return split(h+1,e,rev);
            else if(t[e]=='B')
                return split(h,e-1,!rev);
            else return 0;
        }
        else{
            if(t[e]=='A' && t[h]=='B')
                return split(h,e-1,rev)||split(h+1,e,!rev);
            else if(t[e]=='A')
                return split(h,e-1,rev);
            else if(t[h]=='B')
                return split(h+1,e,!rev);
            else return 0;
        }
    }
}
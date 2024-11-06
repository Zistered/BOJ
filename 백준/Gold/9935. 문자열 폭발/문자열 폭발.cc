#include <stdio.h>
#include <cstring>

int main() {
    char s[1000101], t[40], s2[1000101];
    int tl, sl;
    scanf("%s", s);
    scanf("%s", t);
    tl = strlen(t);
    sl = strlen(s);
    int k=0;
    for(int i=0; i<sl; i++){
        s2[i-k]=s[i];
        s2[i-k+1]='\0';
        if(i-k+1>=tl)
        {
            bool yes=!strncmp(&s2[i-k-tl+1], t, tl);
            if(yes)
            {
                k+=tl;
                s2[i-k+1]='\0';
            }
        }
    }
    if (s2[0] == '\0')
        printf("FRULA");
    else
    {
        printf("%s", s2);
    }
    return 0;
}
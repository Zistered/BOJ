#include<cstdio>
#include<cstring>
int k(char *c,int l){for(int i=0;i<l/2;i++)if(c[i]!=c[l-i-1])return 0;return 1;}main(){char s[500001];int l,n;scanf("%s",s);l=strlen(s);int v=1;for(int i=1;i<l;i++)if(s[0]!=s[i]){v=0;break;}v?printf("-1"):k(s,l)?printf("%d",l-1):printf("%d",l);}
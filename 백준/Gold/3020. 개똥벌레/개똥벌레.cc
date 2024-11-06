#include <cstdio>

int main() {
  int n, h, d[500005]={0}, u[500005]={0}, l, jb = 1;
  scanf("%d%d", &n, &h);
  for (int i = 0; i < n/2; i++) {
    scanf("%d", &l);
    d[l]++;
    scanf("%d", &l);
    u[l]++;
  }
  for(int i=h; i>1; i--)
  {
    d[i-1] += d[i];
    u[i-1] += u[i];
  }
  l = 222222;
  for (int i = 1; i <= h; i++) {
    if(d[i] + u[h-i+1] < l)
    {
      l = d[i] + u[h-i+1];
      jb = 1;
    }
    else if(d[i] + u[h-i+1] == l)
      jb++;
  }
  printf("%d %d", l, jb);
}
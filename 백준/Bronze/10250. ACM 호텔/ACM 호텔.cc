#import<ios>
main(){int x,y;scanf("%d",&y);while(~scanf("%d%d%d",&x,&y,&y))y--,printf("%d%02d\n",y%x+1,y/x+1);}
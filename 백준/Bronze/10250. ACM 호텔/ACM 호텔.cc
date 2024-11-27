#import<ios>
main(){int x,y;for(scanf("%d",&y);~scanf("%d%d%d",&x,&y,&y);)y--,printf("%d%02d ",y%x+1,y/x+1);}
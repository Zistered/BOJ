a,b,c,d,e,f;main(){scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);a<0?f+=-a*c,a=0:0;f+=a?0:d;a<b?f+=e*(b-a):0;printf("%d",f);}
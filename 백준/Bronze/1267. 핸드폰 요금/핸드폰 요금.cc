#import<ios>
int Y(int k){
    return ((k+30)/30)*10;
}
int M(int k){
    return ((k+60)/60)*15;
}
main(){
    int n,y=0,m=0;
    scanf("%d",&n);
    while(n--){
        int k;
        scanf("%d", &k);
        y+=Y(k);
        m+=M(k);
    }
    if(y<=m) printf("Y ");
    if(y>=m) printf("M ");
    printf("%d", y<m?y:m);
}
int e[1000099],n,i=2,j;
main(){scanf("%d",&n);for(;i<n;i++)if(!e[i])for(j=i*2;j<=n;j+=i)e[j]=1;
        
    
    if(n<8)puts("-1");
    else{
    puts(n%2?"2 3 ":"2 2 "),n-=4+n%2;
    for (i=2;i<n;i++)
        for(j=n;!e[i]&&j>=2;j--)
            if(!e[j]&&i+j==n)
                printf("%d %d",i,j),exit(0);
        
    }
}
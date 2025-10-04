x,i=map(int,input().split())
for _ in input().split():
    k=int(_)
    if(k-1)>(x-k):
        print(x,end=' ')
    else:
        print(1,end=' ')
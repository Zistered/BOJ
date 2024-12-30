while True:
    a=int(input())
    if a==0:
        break
    a-=2
    b=[*map(int,input().split())]
    mx=0
    for i in range(a):
        mx=max(mx, b[i]+b[i+1]+b[i+2])
    print(mx)
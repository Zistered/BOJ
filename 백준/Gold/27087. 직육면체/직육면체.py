for i in range(int(input())):
    a,b,c,d=map(int,input().split())
    if a%d==0 and b%d==0:
        print(1)
    elif a%d==0 and c%d==0:
        print(1)
    elif b%d==0 and c%d==0:
        print(1)
    else:
        print(0)
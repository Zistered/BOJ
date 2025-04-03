x,y=0,9999
for _ in range(int(input())):
    a,b=map(int,input().split())
    if b<y:
        x,y=a,b
print(x,y)
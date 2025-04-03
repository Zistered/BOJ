_=int(input())
b=[*map(int,input().split())]
m=0
for i in range(_):
    f,t=map(int,input().split())
    if t-f>0 and b[i]:
        m+=t-f
print(m)
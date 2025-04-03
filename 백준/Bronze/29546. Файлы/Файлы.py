f=[]
for i in range(int(input())):
    f.append(input())
for i in range(int(input())):
    a,b=map(int,input().split())
    for j in range(a-1, b):
        print(f[j])
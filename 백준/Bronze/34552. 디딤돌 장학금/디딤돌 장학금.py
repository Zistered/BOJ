m=[*map(int,input().split())]
v=0
for _ in range(int(input())):
    a=input().split()
    if float(a[1])>=2.0 and int(a[2])>=17:
        v += m[int(a[0])]
print(v)
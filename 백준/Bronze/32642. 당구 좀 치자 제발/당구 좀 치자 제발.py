r=0
rr=0
input()
for i in map(int,input().split()):
    if i:
        r+=1
    else:
        r-=1
    rr+=r
print(rr)
n,a,b=map(int,input().split())
f=0
z=0
fz=0
for i in range(1, n+1):
    if i%a==0 and i%b==0:
        fz+=1
    elif i%a==0:
        f+=1
    elif i%b==0:
        z+=1
print(f,z,fz)
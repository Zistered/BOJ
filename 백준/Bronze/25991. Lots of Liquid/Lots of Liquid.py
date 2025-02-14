f=input()
k=0
for i in map(float,input().split()):
    k+=i*i*i
print(k**(1/3))
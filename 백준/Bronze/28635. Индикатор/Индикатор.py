m=int(input())
a=int(input())
b=int(input())
v=0
while a!=b:
    v+=1
    a+=1
    if a>m:
        a=1
print(v)
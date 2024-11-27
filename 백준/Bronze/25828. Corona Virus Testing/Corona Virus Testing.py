a,b,c=map(int,input().split())
d=a*b
e=a+b*c
if d<e:print(1)
else:print(2 if d>e else 0)
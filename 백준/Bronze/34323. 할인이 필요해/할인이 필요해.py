import math
n,m,s=map(int,input().split())
l=s*(m+1)*(100-n)/100
r=m*s
print(math.floor(min(l,r)))
p,q=map(int,input().split())
a,b=map(int,input().split())
print((q-p)*b+p*a if q>=p else q*a)
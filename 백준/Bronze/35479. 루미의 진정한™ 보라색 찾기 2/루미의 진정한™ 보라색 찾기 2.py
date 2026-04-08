r,g,b=map(int,input().split())
r/=255.0
g/=255.0
b/=255.0
k = 1-max(r,g,b)
if(k==1):
    c=m=y=0
else:    
    c = (1-r-k)/(1-k)
    m = (1-g-k)/(1-k)
    y = (1-b-k)/(1-k)
print(c,m,y,k)
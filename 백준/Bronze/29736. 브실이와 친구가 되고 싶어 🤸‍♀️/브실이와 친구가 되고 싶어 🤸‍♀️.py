a,b=map(int,input().split())
k,x=map(int,input().split())
if(k+x<a or k-x>b):
    print("IMPOSSIBLE")
else:
    print(min(k+x,b)-max(k-x,a)+1)
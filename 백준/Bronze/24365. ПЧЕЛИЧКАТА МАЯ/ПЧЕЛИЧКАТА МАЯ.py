a,b,c=map(int,input().split())
p=(a+b+c)//3
if(b==p):
    print(min((c-p)*2,(p-a)*2))
elif b<p:
    print(p-b+(p-a)*2)
else:
    print(b-p+(c-p)*2)
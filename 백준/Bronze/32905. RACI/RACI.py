a,b=map(int,input().split())
k=False
for i in range(a):
    k = k or (input().count("A") is not 1)
print("No" if k else "Yes")
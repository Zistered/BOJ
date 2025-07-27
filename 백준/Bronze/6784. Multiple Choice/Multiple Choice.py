n=0
p=[]
for _ in range(int(input())):
    p.append(input())
for _ in p:
    if _==input():
        n+=1
print(n)
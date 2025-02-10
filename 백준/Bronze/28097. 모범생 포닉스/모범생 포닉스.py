n=int(input())-1
k=0
for i in input().split():
    k+=int(i)
k+=n*8
print(k//24, k%24)
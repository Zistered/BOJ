a,c,b=map(int,input().split())
C,B=1,1
for i in range(a):
    C+=c
    B+=b
    if(B>C):
        B,C=C,B
    if B==C:
        B-=1
print(C,B)
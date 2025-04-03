a=input()
k=0
while k<len(a):
    print(a[k],end="")
    k+=ord(a[k])-ord('A')+1
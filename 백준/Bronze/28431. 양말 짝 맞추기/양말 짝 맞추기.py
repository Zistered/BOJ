a=[0,0,0,0,0,0,0,0,0,0,0,0,0]
for i in range(5):
    b=int(input())
    a[b]+=1
    a[b]=a[b]%2
for i in range(0,10):
    if a[i]==1:
        print(i)
    
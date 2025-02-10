cm=0
for i in [0,0,0,0]:
    a=input().split()
    if a[0]=="Es":
        cm+=int(a[1])*21
    else:
        cm+=int(a[1])*17
print(cm)
d=0
for i in range(int(input())):
    a=int(input().split()[0])
    if a==136:d+=1000
    if a==142:d+=5000
    if a==148:d+=10000
    if a==154:d+=50000
print(d)
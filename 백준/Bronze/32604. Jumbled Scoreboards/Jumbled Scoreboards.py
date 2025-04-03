pa,pb=0,0
for i in range(int(input())):
    a,b=map(int,input().split())
    if a<pa or b<pb:
        print("no")
        exit(0)
    pa,pb=a,b
print("yes")
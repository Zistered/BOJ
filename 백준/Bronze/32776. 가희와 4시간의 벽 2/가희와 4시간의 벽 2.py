a=int(input())
if a<=240:
    print("high speed rail")
elif a<=sum(map(int,input().split())):
    print("high speed rail")
else:
    print("flight")
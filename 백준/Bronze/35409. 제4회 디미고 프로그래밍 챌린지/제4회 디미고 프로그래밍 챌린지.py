a,b=map(int,input().split())
b+=a*60
if (b>=390 and b<=540) or (b>=590 and b<=600) or (b>=650 and b<=660) or (b>=710 and b<=720) or (b>=770 and b<=830) or (b>=880 and b<=890) or (b>=940 and b<=950) or (b>=1000 and b<=1370):
    print("Yes")
else:
    print("No")
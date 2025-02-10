n,a,b=map(int,input().split())
s,t=map(int,input().split())
if(t<s):
    t,s=s,t
if s>a and t<b:
    print("City")
elif (s<=a and t<=a) or (s>=b and t>=b):
    print("Outside")
else:
    print("Full")
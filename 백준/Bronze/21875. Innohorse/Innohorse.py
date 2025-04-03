a,b=input(),input()
c,d=abs(int(a[1:])-int(b[1:])),abs(ord(a[0])-ord(b[0]))
print(min(c,d), max(c,d))
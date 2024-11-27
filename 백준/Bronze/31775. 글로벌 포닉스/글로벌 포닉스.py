l=k=p=0
for i in range(3):
 a=input()[0]
 if a=='l':l=1
 if a=='k':k=1
 if a=='p':p=1
print("GLOBAL" if l*k*p else "PONIX")
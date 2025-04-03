a,b,c=0,0,0
for i in input():
    if c=='A':
        c=0
        a+=int(i)
    elif c=='B':
        c=0
        b+=int(i)
    else:
        c=i;
print('A' if a>b else 'B')
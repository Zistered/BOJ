for _ in range(int(input())):
    d,a,b,c=map(int,input().split())
    g="PASS"
    if a<11:
        g="FAIL"
    if b<8:
        g="FAIL"
    if c<12:
        g="FAIL"
    if a+b+c<55:
        g="FAIL"
    print(d, a+b+c, g)
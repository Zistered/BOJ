for _ in range(int(input())):
    s=input()
    for i in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
        b=i+i
        while s.count(b):
            s = s.replace(b,i)
    print(s)
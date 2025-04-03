for _ in range(int(input())):
    k=0
    for __ in range(int(input())):
        a=input().split()
        k+=int(a[1])*float("0"+a[2])
    print(f'${round(k, 2):.2f}')
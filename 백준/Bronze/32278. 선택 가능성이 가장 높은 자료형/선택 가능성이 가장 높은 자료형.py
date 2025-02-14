k=int(input())
if k<32768 and k>-32769:print("short")
elif k<2147483648 and k>-2147483649:print("int")
else:print("long long")
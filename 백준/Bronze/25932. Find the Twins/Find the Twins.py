for i in range(int(input())):
    a=input()
    print(a)
    if(a.count("17") and a.count("18")):print("both\n")
    elif a.count("17"):print("zack\n")
    elif a.count("18"):print("mack\n")
    else:print("none\n")
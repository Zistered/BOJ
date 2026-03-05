for i in range(int(input())):
    a=input()
    b=a.count("a")+a.count("e")+a.count("i")+a.count("o")+a.count("u")
    print("The number of vowels in ", a, " is ", b, ".", sep="")
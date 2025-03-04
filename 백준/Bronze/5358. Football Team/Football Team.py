import string
while True:
    try:
        a=input().replace("i","&").replace("e","i").replace("&","e").replace("I","&").replace("E","I").replace("&","E")
        print(a)
    except:
        break
t,l=0,0
while True:
    try:
        if input()=="Tiger":
            t+=1
        else:
            l+=1
    except:
        break
print("Tiger" if t>l else "Lion")
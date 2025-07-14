while True:
    sweet, sour = map(int,input().split())
    if sweet+sour==0:
        break
    elif sweet+sour == 13:
        print("Never speak again.")
    elif sweet>sour:
        print("To the convention.")
    elif sweet<sour:
        print("Left beehind.")
    else:
        print("Undecided.")
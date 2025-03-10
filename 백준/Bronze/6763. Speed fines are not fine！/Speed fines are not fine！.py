ㅁ=int(input())
ㅠ=int(input())
ㅊ=ㅠ-ㅁ
if ㅊ>=31:
    print("You are speeding and your fine is $500.")
elif ㅊ>=21:
    print("You are speeding and your fine is $270.")
elif ㅊ>=1:
    print("You are speeding and your fine is $100.")
else:
    print("Congratulations, you are within the speed limit!")
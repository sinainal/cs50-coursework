n = 0
while n == 0:
    try:
        number = int(input("Change: "))
        n = 1
    except:
        print("err")

sum = 0
number = str(number)
l = len(number)
for i in range(l-1,-1,-1):
    if ((i % 2 == 0 and l % 2 == 0 ) or (i % 2 == 1 and l % 2 == 1)):
        if int(number[i]) * 2 < 10:
            sum = sum + int(number[i]) * 2
        else:
            sum = sum + int(1 + (int(number[i]) * 2) % 10)
    else:
        sum = sum + int(number[i])
print(sum)
if sum % 10 != 0:
    print("INVALID")
else:
    number = str(number)
    if l == 15 and number[0] == "3" and (number[1] == "3" or number[1] == "7"):
        print("AMEX")
    elif l == 16 and number[0] == "5" and (number[1] in "12345"):
        print("MASTERCARD")
    elif (l == 16 or l == 13) and number[0] == "4":
        print("VISA")
    else:
        print("INVALID")

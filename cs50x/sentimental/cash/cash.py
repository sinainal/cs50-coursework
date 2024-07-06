n = 0
while n == 0:
    try:
        d = float(input("Change: "))
        if d > 0:
            n = 1
    except:
        print("err")
d = d * 100
a = int(d / 25)
d = d % 25
b = int(d / 10)
d = d % 10
c = int(d / 5)
d = d % 5
print(int(a + b + c + d))

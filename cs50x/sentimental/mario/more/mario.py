n = 0
def inp():
    while True:
        try:
            return int(input("Height:"))
        except:
            print("try again")
while n == 0:
    h = inp()
    if h > 0 and 9 > h:
        m = h
        for i in range(h):
            h = h - 1
            print(h * " " + (m - h) * "#" + "  " + (m - h) * "#")
        n = 1

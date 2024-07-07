text = input("Text: ")
S = 0
L = 0
W = 0
for i in text:
    if i in [".", "?", "!"]:
        S = S + 1
    elif i == " ":
        W = W + 1
    elif i.isalpha():
        L = L + 1
W = W + 1
index = round(0.0588 * 100 * L / W - 0.296 * 100 * S / W - 15.8)
if index < 1:
    print("Before Grade 1")
elif index < 16:
    print("Grade " + str(index))
else:
    print("Grade 16+")

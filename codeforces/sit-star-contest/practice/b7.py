a, b = map(int, input().strip().split())

while a > 0 or b > 0:
    if a >= 2:
        print("HH")
        a -= 2
    elif b >= 2:
        print("TT")
        b -= 2
        a += 1
    elif b == 1:
        print("T")
        b += 1
        if a == 0:
            print("T")
            print("T")
            b += 2
    else:
        print("H")
        a -= 1
        b += 1

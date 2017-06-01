#!/bin/python3

pi =  3.14159265358979323846264338327950288419716939937510

def calc(den):
    num = round(den * pi)
    err = abs(num / den - pi)
    terr = abs((num+1)/den - pi)
    terr2 = abs((num-1)/den - pi)
    if terr < terr2:
        if terr < err:
            err = terr
            num = num+1
    else:
        if terr2 <= err:
            err = terr2
            num = num-1
    return (num, err)

def main():
    length = 3 * 10 ** 6
    low, hi = map(int, input().strip().split())
    tlow = max(low, hi - length)
    thi = min(hi, low + length)
    den = low
    num, err = calc(den)
    for i in range(low, thi+1):
        tnum, terr = calc(i)
        if terr < err:
            num = tnum
            den = i
            err = terr
    for i in range(tlow, hi+1):
        tnum, terr = calc(i)
        if terr < err:
            num = tnum
            den = i
            err = terr
    print('{}/{}'.format(num, den))

if __name__ == "__main__":
    main()
import math

b = 1
a = 1
for i in range(1, 3500):
    a = a * i + 1
    b *= i
n = int(input())
ans = 0
sign = True
while n >= 1:
    if n <= 1:
        if sign:
            ans += n * a // b
        else:
            ans -= n * a // b
        break
    if a >= 2 * b:
        c = a // b - 1;
        if sign:
            ans += c * n * (n + 1) // 2
        else:
            ans -= c * n * (n + 1) // 2
        a -= c * b
    m = (a-b) * n // b
    assert(b < a and a < 2 * b)
    if sign:
        ans += (n + m) * (n + m + 1) // 2
    else:
        ans -= (n + m) * (n + m + 1) // 2
    b = a - b
    n = m
    sign = not sign
print(ans)
def op1(u, v):
    return u^v
def op2(u, v):
    return u|v
def op3(u, v):
    return u&v
a = [int(input()) for _ in range(4)]
b = op1(a[0], a[1])
c = op2(a[2], a[3])
d = op3(a[1], a[2])
e = op1(a[0], a[3])

f = op3(b, c)
g = op2(d, e)
h = op1(f, g)
print(h)
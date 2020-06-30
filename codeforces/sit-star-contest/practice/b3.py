x, y, z, m = map(int, input().strip().split())
if x > z:
    x, z = z, x
if y > z:
    y, z = z, y

if x + y + z <= m:
    print(1)
elif x + y <= m:
    print(2)
else:
    print(3)

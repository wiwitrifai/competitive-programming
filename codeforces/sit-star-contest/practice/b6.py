a, b = map(int, input().strip().split())
while a != b:
    if a > b:
        a //= 2
    else:
        b //= 2
print(a)

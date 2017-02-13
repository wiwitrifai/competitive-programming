n = int(input())
a = list(map(int, input().split()))
j = n-1
for i in range(n):
    if i > j: break
    if i & 1 == 0:
        a[i], a[j] = a[j], a[i]
    j -= 1
print(' '.join(map(str, a)))
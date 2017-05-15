n = int(input())
ans = []
cur = 0
while n > 0:
  if ans & 1:
    ans.append(cur)
  cur += 1
  ans >>= 1
print(len(ans))
print(' '.join(map(str, ans)))
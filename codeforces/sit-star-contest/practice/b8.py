s = input().strip()
n = len(s)

def palindrom(s):
    cnt = {}
    for c in s:
        if c not in cnt:
            cnt[c] = 0
        cnt[c] += 1
    ret = ""
    for c, x in cnt.items():
        if x & 1:
            ret += c
    if len(ret) > 1:
        return "NO"
    for c, x in cnt.items():
        x //= 2
        ret = c * x + ret + c * x
    return ret

if n & 1:
    sout = s[0::2]
    sin = s[1::2]
    sout = palindrom(sout)
    sin = palindrom(sin)
    if sout != sout[::-1] or sin != sin[::-1]:
        print("NO")
    else:
        ans = ""
        for i in range(n // 2):
            ans += sout[i] + sin[i]
        ans += sout[-1]
        print(ans)
else:
    a = s[0::2]
    b = s[1::2]
    a = sorted(a)
    b = sorted(b)
    if a != b:
        print("NO")
    else:
        ans = ""
        n = len(a)
        for i in range(n):
            ans += a[i] + a[n-1-i]
        print(ans)

def find(s):
    n = len(s)
    ans = ""
    for i in range(n-1, -1, -1):
        c = chr(ord('A') + i)
        ans = ans[:s[i]] + c + ans[s[i]:]
    return ans

print(find((1,2,0,0)))
print(find((4,1,3,1,0,0)))
print(find((6,4,0,4,0,0,2,1,0)))

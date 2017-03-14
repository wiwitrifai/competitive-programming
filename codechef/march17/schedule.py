#!/bin/python3

def can(n, s, seg):
    ret = 0
    last = s[0]
    cnt = 0
    for i in range(n):
        if last != s[i]:
            cnt = 1
            last = s[i]
        else:
            cnt += 1
        if cnt > seg:
            last ^= 1
            if seg > 1 and i+1 < n and s[i+1] == last:
                last ^= 1
            ret += 1
            cnt = 1
    ret2 = ret
    ret = 1
    last = s[0] ^ 1
    cnt = 1
    for i in range(1, n):
        if last != s[i]:
            cnt = 1
            last = s[i]
        else:
            cnt += 1
        if cnt > seg:
            last ^= 1
            if seg > 1 and i+1 < n and s[i+1] == last:
                last ^= 1
            ret += 1
            cnt = 1
    return min(ret, ret2)

def main():
    for _ in range(int(input())):
        n, k = map(int, input().split())
        s = [ int(c) for c in input().strip() ]
        l = 1
        r = n
        while l < r:
            mid = (l + r) // 2
            if can(n, s, mid) <= k:
                r = mid
            else:
                l = mid+1
        print(l)

if __name__ == "__main__":
    main()
#!/bin/python3
def vowels(c):
    return chr(c) in ['a', 'i', 'u', 'e', 'o'];

def rec(cur, n, isvowels):
    if n == 0:
        return [cur]
    ret = []
    for c in range(ord('a'), ord('z')+1):
        if c == ord('y'): continue
        if isvowels == vowels(c):
            ret += rec(cur + chr(c), n-1, not isvowels)
    return ret

n = int(input().strip())
ans = rec('', n, True) + rec('', n, False)
print('\n'.join(ans))
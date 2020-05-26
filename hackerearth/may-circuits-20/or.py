def significantBit(x):
    if x == 0:
        return -1
    bit = 0
    while (1 << (bit+1)) <= x:
        bit += 1
    return bit

def solve(A, B):
    if A == B:
        return 1
    if A > B:
        return 0
    bit = significantBit(A ^ B)
    mask = (1 << bit) - 1
    A &= mask
    B &= mask
    if A == 0:
        return 2 << bit
    if B == 0:
        return 2 * solve(A, mask) + 1
    k = significantBit(B)
    if k + 1 == bit:
        return 2 * mask - A + 2

    mask2 = (1 << (k+1)) - 1
    res1 = solve(A & mask2, mask2)
    res2 = solve((A // (mask2+1)) + 1, mask // (mask2+1))
    ans = res1 + (res2 * 2 + 1) * (2 ** (k+1))
    if (A // (mask2 + 1)) != 0:
        ans += res1
    return ans

def brute(A, B):
    res = set()
    for i in range(A, B+1):
        for j in range(i, B+1):
            res.add(i | j)
    return len(res)

A = int(input())
B = int(input())

print(solve(A, B))

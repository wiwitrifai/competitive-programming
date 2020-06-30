memo = {}
def calc(n, s, one = False):
    if n < s:
        return -1
    if n == s:
        return 0
    if (n, s, one) in memo:
        return memo[n, s, one]
    ret = calc(n-3, s, one)
    if n % 2 == 0:
        res = calc(n // 2, s, one)
        if ret == -1 or (res != -1 and res < ret):
            ret = res
    if one:
        res = calc(n - 1, s, one)
        if ret == -1 or (res != -1 and res < ret):
            ret = res

    if ret >= 0:
        ret += 1
    memo[n, s, one] = ret
    return ret

def backtrack(n, s, one):
    print('backtrack ' , n, s, one, calc(n, s, one))
    if calc(n, s, one) < 0:
        return "!"
    if calc(n, s, one) == 0:
        return ""
    if calc(n, s, one) == calc(n-3, s, one) + 1:
        return backtrack(n-3, s, one) + "A"
    if n % 2 == 0 and calc(n, s, one) == calc(n // 2, s, one) + 1:
        return backtrack(n // 2, s, one) + "B"
    if one and calc(n, s, one) == calc(n - 1, s, one) + 1:
        return backtrack(n - 1, s, one) + "C"
    return "?"

print(calc(17, 2, False), backtrack(17, 2, False))
print(calc(47, 3, True), backtrack(47, 3, True))

def digit_len(n):
    ans = 0
    cur = 1
    while n >= cur:
        cur *= 10
        ans += 1
    return ans

def find_n(dig_len):
    n = 0
    cnt = 0
    while cnt < dig_len:
        n += 1
        cnt += digit_len(n)
    print(n, cnt)

def count_1(n):
    ans = 0
    while n > 0:
        d = n % 10
        n //= 10
        if d == 1:
            ans += 1
    return ans

def find_max_n(cnt_1):
    n = 0
    cnt = 0
    while cnt + count_1(n+1) <= cnt_1:
        n += 1
        cnt += count_1(n)
    print(n, cnt)

find_n(990)
find_max_n(260)

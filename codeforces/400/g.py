#!/bin/python3

def decode(c):
    if ord(c) <= ord('9') and ord(c) >= ord('0'):
        return ord(c) - ord('0')
    return ord(c) - ord('a') + 10

dp = [[[0, 0] for j in range(2)]for i in range(20)]
def solve(s, full):
    n = len(s)
    ans = 0
    for d_max in range(16):
        for i in range(n+1):
            for j in range(2):
                for k in range(2):
                    dp[i][j][k] = 0
        dp[0][1][0] = 1
        pos = n-1- (d_max // 4)
        bit = 1<<(d_max % 4)
        if pos < 0: continue
        for i in range(n):
            for up in range(2):
                for fill in range(2):
                    if dp[i][up][fill] == 0: continue
                    digm = min(d_max, decode(s[i]) if up > 0 else d_max)
                    for d in range(digm+1):
                        if (i == pos) and ((d & bit) == 0):
                            continue
                        tup = up 
                        if d != decode(s[i]): tup = 0
                        tfill = fill
                        if d == d_max: tfill = 1
                        dp[i+1][tup][tfill] += dp[i][up][fill]
        for i in range(full+1):
            ans += dp[n][i][1]
    return ans

def main():
    q = int(input().strip())
    for _ in range(q):
        l, r = input().strip().split()
        print(solve(r, 1)- solve(l, 0))

if __name__ == "__main__":
    main()
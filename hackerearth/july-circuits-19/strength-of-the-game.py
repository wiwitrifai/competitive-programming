def main():
    n, m = map(int, input().split())
    s = map(int, input().split())
    max_len = 512
    mod = 10 ** 9 + 7
    dp = [0] * max_len
    dp[0] = 1
    for x in s:
        newdp = [0] * max_len
        for i in range(x+1):
            for j in range(max_len):
                newdp[i^j] = (newdp[i^j] + dp[j]) % mod
        dp = newdp
    for i in range(m+1):
        if i:
            print(' ', end='')
        print(dp[i], end='')
    print('')


if __name__ == "__main__":
    main()

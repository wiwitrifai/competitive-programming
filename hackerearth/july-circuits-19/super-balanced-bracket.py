def main():
    for _ in range(int(input())):
        s = input()
        n = len(s)
        i, j = 0, n-1
        ans = 0
        while i < j:
            while i < j and s[i] == ')':
                i += 1
            while i < j and s[j] == '(':
                j -= 1
            if i >= j:
                break
            ans += 2
            i += 1
            j -= 1;
        print(ans)


if __name__ == "__main__":
    main()

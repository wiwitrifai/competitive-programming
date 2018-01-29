if __name__ == "__main__":
    n, k = map(int, input().strip().split())
    r = n % k
    q = n // k
    if r == 0:
        print(q * (q-1) // 2 * k)
    else:
        print(q * (q-1) // 2 * (k-r) + (q+1) * q // 2 * r)
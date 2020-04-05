queries = []
for n in range(2, 51):
    for k in range(n, n*n+1):
        queries.append((n, k))
print(len(queries))
for n, k in queries:
    print(n, k)

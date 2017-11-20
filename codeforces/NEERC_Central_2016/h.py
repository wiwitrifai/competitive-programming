rfile = open("input.txt", "r")
wfile = open("output.txt", "w")
n = int(rfile.read())
ans = 8
now = 2
while now <= min(n, 9):
    ans *= 9
    now += 1
while now <= n:
    ans *= 10
    now += 1
wfile.write(str(ans))
rfile.close()
wfile.close()
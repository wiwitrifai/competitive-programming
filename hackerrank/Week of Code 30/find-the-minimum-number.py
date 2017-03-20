#!/bin/python3

n = int(input().strip())

ans = ""
ending = ""
for i in range(n-1):
    ans += "min(int, "
    ending += ")"

ans += "int" + ending
print(ans)
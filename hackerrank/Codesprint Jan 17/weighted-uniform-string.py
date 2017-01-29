#!/bin/python3

import sys


s = input().strip()
n = int(input().strip())
st = set()
last, cnt = 0, 0
for i in s:
    if last != ord(i):
        last = ord(i)
        cnt = 0
    cnt += 1
    st.add(cnt * (last - ord('a')+1))
    
for a0 in range(n):
    x = int(input().strip())
    print('Yes' if x in st else 'No')
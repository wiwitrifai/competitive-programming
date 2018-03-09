#include <bits/stdc++.h>

using namespace std;

long long solve(long long n, long long off, long long x) {
  if (n == 1)
    return off + 1;
  if (x & 1)
    return off + (x+1)/2;
  long long y = (x)/2;
  return solve(n >> 1, off + (n >> 1), y);
}

int main() {
  long long n;
  int q;
  scanf("%I64d %d", &n, &q);
  long long len = 1;
  while ((len * 2) <= n) len <<= 1;
  long long sisa = n - len;
  while (q--) {
    long long x;
    scanf("%I64d", &x);
    if (x & 1) {
      if ((x + 1)/2 <= sisa) {
        printf("%I64d\n", (x+1)/2);
        continue;
      }
    }
    if (x > 2 * sisa)
      printf("%I64d\n", solve(len, sisa, x - 2 * sisa));
    else {
      long long y = x / 2;
      printf("%I64d\n", solve(len, sisa, len - sisa + y));
    }
  }
  return 0;
}
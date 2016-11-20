#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
long long powmod(long long b, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    p >>= 1;
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    if (n < 3) {
      puts("0");
      continue;
    }
    long long ans = (powmod(2, n-1) + mod - 2) % mod; 
    printf("%lld\n", ans);
  }
  return 0;
}
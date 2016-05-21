#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
long long powmod(long long base, long long pw) {
  long long ret = 1;
  while(pw) {
    if(pw & 1)
      ret = (ret * base) % mod;
    base = (base * base) % mod;
    pw >>= 1;
  }
  return ret;
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n, k;
    scanf("%lld%lld", &n, &k);
    long long ans = k*powmod(k-1, n-1) % mod;
    ans %= mod;
    if(ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  } 

  return 0;
}
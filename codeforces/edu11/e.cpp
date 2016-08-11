#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long pw) {
  long long ret = 1;
  while (pw) {
    if (pw & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    pw >>= 1;
  }
  return ret;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  long long now = powmod(m, n);
  long long ans = now;
  long long mul = (powmod(m, mod-2) * (2LL*m-1)) % mod;
  for (int i = 0; i < n; i++) {
    ans = (ans + now) % mod;
    now = (now * mul) % mod;
  }
  cout << ans << endl;

  return 0;
}